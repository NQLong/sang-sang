#include "../Header/Meal.h"
#include "../Header/Restaurant.h"

int Meal::new_id = 0;

list<Meal> Meal::meals;

Meal::Meal()
{
    this->meal_id = new_id++;
}

Meal::Meal(const Meal &other)
{
    this->meal_id = other.meal_id;
    this->table_id = other.table_id;
    this->items = other.items;
    this->waiter_id = other.waiter_id;
    this->client_tax_number = other.client_tax_number;
    this->start = other.start;
    this->duration = other.duration;
}

Meal::~Meal() {}
Meal::Meal(
    int _table_id,
    list<MealItem> _items,
    int _waiter_id,
    string _client_tax_number,
    time_t _start,
    double _duration)
    : table_id(_table_id),
      items(_items),
      waiter_id(_waiter_id),
      client_tax_number(_client_tax_number),
      start(_start),
      duration(_duration)
{
    this->meal_id = new_id++;
}

MealItem *Meal::pick_meal_item()
{

    return get_meal_item(input_str("Enter dish name : "));
}
MealItem *Meal::get_meal_item(string name)
{
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if (it->getDish_name() == name)
            return &*it;
    }
    return NULL;
}

bool Meal::add_meal_item()
{
    cout << "Add new meal item:" << endl;
    MealItem mi = MealItem::input();
    return add_meal_item(mi);
}
bool Meal::add_meal_item(MealItem m_i)
{
    if (get_meal_item(m_i.getDish_name()))
        return false;
    items.push_back(m_i);
    return true;
}

bool Meal::remove_meal_item()
{
    MealItem *ptr = pick_meal_item();
    if (!ptr)
    {
        clear();
        cout << "invalid dish name";
        wait();
        return false;
    }
    if (remove_meal_item(*ptr))
    {
        clear();
        cout << "Success";
        wait();
        return true;
    }
    clear();
    cout << "Fail";
    wait();
    return false;
}

bool Meal::remove_meal_item(MealItem m_i)
{
    items.remove(m_i);
    return true;
}

bool Meal::add_meal()
{
    cout << "Add new meal:" << endl;
    Meal meal = Meal::input();

    wait();
    if (!meal.check())
    {
        wait();
        do
        {
            clear();
            if (select_statement("modify meal", "cancel meal"))
                return false;
            meal.modify();
        } while (!meal.check());
    }
    return add_meal(meal);
}

bool Meal::add_meal(Meal meal)
{
    if (get_meal(meal.meal_id))
        return false;
    meals.push_back(meal);
    meals.back().commit(Holder::restaurant);
    return true;
}

Meal *Meal::get_meal(int id)
{
    for (auto it = meals.begin(); it != meals.end(); it++)
    {
        if (it->meal_id == id)
            return &*it;
    }
    return NULL;
}
Meal *Meal::pick_meal()
{
    return get_meal(my_input_c<int>("Enter meal id: "));
}

bool Meal::remove_meal()
{
    Meal *ptr = pick_meal();
    if (!ptr)
    {
        clear();
        cout << "invalid mea id";

        return false;
    }
    if (remove_meal(*ptr))
    {
        clear();
        cout << "Success";

        return true;
    }
    clear();
    cout << "Fail";
    wait();
    return false;
}

bool Meal::remove_meal(Meal meal)
{
    meals.remove(meal);
    return true;
}

double Meal::total_price()
{
    double price = 0;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        price += it->price_total();
    }
    return price;
}

int Meal::pick_table()
{
    Restaurant *r = (Restaurant *)Holder::restaurant;
    Table *table = NULL;
    while (!table && r->getTables()->size() != 0)
    {
        clear();
        cout << "table id: " << endl;
        table = r->pick_table();
    }
    if (!table)
    {
        cout << "There is no table to pick";
        wait();
        return -1;
    }
    return table->getTable_id();
}

int Meal::pick_waiter()
{
    Restaurant *r = (Restaurant *)Holder::restaurant;
    Waiter *waiter = NULL;
    while (!waiter && r->getWaiters()->size() != 0)
    {
        clear();
        cout << "waiter id: " << endl;
        waiter = r->pick_waiter();
    }
    if (!waiter)
    {
        cout << "There is no waiter to pick";
        wait();
        return -1;
    }
    return waiter->getId();
}

string Meal::pick_client()
{
    cout << "Does this meal require a client info\n";
    if (select_statement("Yes", "No"))
    {
        return "";
    }
    clear();

    Client *client = NULL;
    string tax;
    clear();
    cout << "client 's tax number: " << endl;
    getline(cin, tax);
    client = Client::get_client(tax);
    if (!client)
    {
        cout << "\nClient not found\n";
        if (select_statement("Try again", "add new client"))
        {
            clear();
            while (!Client::add_client())
            {
                cout << "fail to create client, trye again!";
                wait();
            }
            return Client::getClients()->back().getTax_number();
        }
        else
            return pick_client();
    }
    return client->getTax_number();
}

bool Meal::select_meal()
{
    Meal *ptr = pick_meal();
    if (!ptr)
    {
        cout << "Invalid id";
        return false;
    }
    if (select_statement("View meal", "modify meal"))
    {
        ptr->modify();
    }
    else
    {
        clear();
        cout << *ptr;
        wait();
    }
    return true;
}

Meal Meal::input()
{

    Meal temp;
    temp.table_id = temp.pick_table();
    clear();
    temp.waiter_id = temp.pick_waiter();
    clear();
    temp.client_tax_number = temp.pick_client();
    temp.start = time(0);
    clear();
    cout << "enter meal duration: ";
    cin >> temp.duration;
    cin.ignore();
    clear();

    while (!select_statement("Add meal item", "Done"))
    {
        clear();
        temp.add_meal_item();
        clear();
    }
    return temp;
}

void Meal::modify()
{
    int option;
    bool loop = true;
    Client *ptr;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify waiter." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify client." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify duration." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify table." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify meal items." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            this->waiter_id = pick_waiter();
            break;
        case 2:
            clear();
            this->client_tax_number = pick_client();
            break;
        case 3:
            clear();
            cout << "enter duration: ";
            cin >> this->duration;
            cin.ignore();
            break;
        case 4:
            clear();
            this->table_id = pick_table();
            break;
        case 5:
            clear();
            modify_meal_items();
            wait();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Meal::modify_meal_items()
{
    int option;
    bool loop = true;
    Client *ptr;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "meal items list." << endl
            << setw(3) << left << to_string(count++) + "."
            << "add meal item." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove meal item." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify meal item." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            meal_items_list();
            wait();
            break;
        case 2:
            clear();
            add_meal_item();
            break;
        case 3:
            clear();
            remove_meal_item();
            break;
        case 4:
            clear();
            modify_meal_item();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
int Meal::total_item() 
{
    int sum = 0;
    for (auto it = items.begin(); it != items.end(); it++)
    {
        sum += it->getQuantity();
    }
    return sum;
}
void Meal::meals_list()
{
    cout
        << setw(90) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(5) << left << "| id " << '|'
        << setw(30) << left << "start" << '|'
        << setw(30) << left << "end" << '|'
        << setw(10) << left << "price($)" << '|'
        << setw(10) << left << "total item" << '|'
        << endl
        << setw(90) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = meals.begin(); it != meals.end(); it++)
    {
        if (!&*it)
            continue;

        time_t end = it->start + it->duration * SECOND_IN_HOUR;

        cout
            << setw(5) << left << "|" + to_string(it->meal_id) << '|'
            << setw(30) << left << string_of_time(it->start) << '|'
            << setw(30) << left << string_of_time(end) << '|'
            << setw(10) << left << it->total_price() << '|'
            << setw(10) << left << it->total_item() << '|' << endl
            << setw(90) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

void Meal::meal_items_list()
{
    cout
        << setw(58) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(20) << left << "| Dish name " << '|'
        << setw(13) << left << "unit price($)" << '|'
        << setw(10) << left << "qunatity" << '|'
        << setw(10) << left << "price" << '|'
        << endl
        << setw(58) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = items.begin(); it != items.end(); it++)
    {
        if (!&*it)
            continue;

        cout
            << setw(20) << left << "|" + (it->getDish_name()) << '|'
            << setw(13) << left << it->getPrice_single() << '|'
            << setw(10) << left << it->getQuantity() << '|'
            << setw(10) << left << it->price_total() << '|' << endl
            << setw(58) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

void Meal::modify_meal_item()
{
    MealItem *ptr = pick_meal_item();
    if (!ptr)
    {
        cout << "Invlaid meal item name";
        wait();
        return;
    }
    ptr->modify();
}

bool Meal::check()
{
    Restaurant temp = *(Restaurant *)Holder::restaurant;
    if (!this->commit(&temp))
    {
        return false;
    }
    return true;
}

bool Meal::commit(void *source)
{
    for (auto it = items.begin(); it != items.end(); it++)
    {
        if (!it->commit(source))
        {
            return false;
        }
    }
    return true;
}

bool operator==(const Meal &rhs, const Meal &lhs)
{
    return (lhs.meal_id == rhs.meal_id);
}

ostream &operator<<(ostream &os, const Meal &m)
{
    os
        << "Meal id: " << m.meal_id << endl
        << "Table id: " << m.table_id << endl

        << "Start time : " << string_of_time(m.start) << endl
        << "Start time : " << string_of_time(m.start + m.duration * SECOND_IN_HOUR) << endl

        << "Dishes :" << endl;

    for (auto it = m.items.begin(); it != m.items.end(); it++)
    {
        os << setw(5) << "" << *it << endl;
    }
    Meal temp = m;
    return os
           << "Total dishes: " << temp.total_item() << endl
           << "Total payed: " << temp.total_price() << endl
           << "Clinet tax number: " << m.client_tax_number << endl;
}

int Meal::getMeal_id()
{
    return this->meal_id;
}

void Meal::setMeal_id(int meal_id)
{
    this->meal_id = meal_id;
}

int Meal::getTable_id()
{
    return this->table_id;
}

void Meal::setTable_id(int table_id)
{
    this->table_id = table_id;
}

list<MealItem> *Meal::getItems()
{
    return &this->items;
}

void Meal::setItems(list<MealItem> items)
{
    this->items = items;
}

int Meal::getWaiter_id()
{
    return this->waiter_id;
}

void Meal::setWaiter_id(int waiter_id)
{
    this->waiter_id = waiter_id;
}

string Meal::getClient_tax_number()
{
    return this->client_tax_number;
}

void Meal::setClient_tax_number(string client_tax_number)
{
    this->client_tax_number = client_tax_number;
}

int Meal::getNew_id()
{
    return this->new_id;
}

void Meal::setNew_id(int new_id)
{
    this->new_id = new_id;
}

list<Meal> *Meal::getMeals()
{
    return &meals;
}

void Meal::setMeals(list<Meal> _meals)
{

    meals = _meals;
}

time_t Meal::getStart()
{
    return this->start;
}

void Meal::setStart(time_t start)
{
    this->start = start;
}

double Meal::getDuration()
{
    return this->duration;
}

void Meal::setDuration(double duration)
{
    this->duration = duration;
}
