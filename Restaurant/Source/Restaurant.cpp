#include "../Header/Restaurant.h"

Restaurant::~Restaurant() {}
Restaurant::Restaurant() {}

Restaurant::Restaurant(
    string name,
    list<Ingridient> ingridients,
    list<Dish> dishes,
    list<Table> tables,
    list<Waiter> waiters

)
{
    this->name = name;
    this->ingridients = ingridients;
    this->dishes = dishes;
    this->tables = tables;
    this->waiters = waiters;
}
bool Restaurant::add_ingiridient(Ingridient i)
{
    if (get_ingridient(i.getName()))
    {
        return false;
    }
    ingridients.push_back(i);
    return true;
}

bool Restaurant::add_ingiridient()
{
    cout << "add new ingridient: " << endl;
    Ingridient i = Ingridient::input_ingridient();
    return add_ingiridient(i);
}
bool Restaurant::remove_ingridient()
{
    Ingridient *ptr = pick_ingridient();
    if (!ptr)
    {
        cout << "Invalid name";

        return false;
    }
    cout << "success";
    return remove_ingridient(*ptr);
}
bool Restaurant::remove_ingridient(Ingridient i)
{
    ingridients.remove(i);
    return true;
}
Ingridient *Restaurant::get_ingridient(string name)
{
    for (auto it = ingridients.begin(); it != ingridients.end(); it++)
    {
        if (it->getName() == name)
            return &*it;
    }
    return NULL;
}

Ingridient *Restaurant::pick_ingridient()
{
    return get_ingridient(input_str("Enter ingridient name: "));
}

void Restaurant::ingridient_list()
{
    cout
        << setw(100) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(20) << left << "|  Measure unit " << '|'
        << setw(10) << left << "  Stock  " << '|'
        << setw(12) << left << "is available" << '|'
        << setw(50) << left << "Ingridient name"

        << "|"
        << endl
        << setw(100) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = ingridients.begin(); it != ingridients.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(20) << left << "|" + it->getMeasure_unit() << '|'
            << setw(10) << left << it->getStock() << '|'
            << setw(12) << left << (!(it->isAvailable()) ? "False" : "True") << '|'
            << setw(50) << left << it->getName() << '|' << endl
            << setw(100) << setfill('*') << "" << endl
            << setfill(' ');
    }
    wait();
}

//Dish group
bool Restaurant::add_dish(Dish d)
{
    if (get_dish(d.getName()) || get_dish(d.getId()))
    {
        return false;
    }
    dishes.push_back(d);
    return true;
}
bool Restaurant::add_dish()
{
    cout << "add new dish: \n";
    Dish i = Dish::input();
    return add_dish(i);
}

bool Restaurant::remove_dish()
{
    Dish *ptr = pick_dish();
    if (!ptr)
    {
        cout << "Invalid name";
        return false;
    }
    cout << "success";
    return remove_dish(*ptr);
}
bool Restaurant::remove_dish(Dish d)
{
    dishes.remove(d);
    return true;
}
Dish *Restaurant::get_dish(string name)
{
    for (auto it = dishes.begin(); it != dishes.end(); it++)
    {
        if (it->getName() == name)
            return &*it;
    }
    return NULL;
}
Dish *Restaurant::get_dish(int id)
{
    for (auto it = dishes.begin(); it != dishes.end(); it++)
    {
        if (it->getId() == id)
            return &*it;
    }
    return NULL;
}
Dish *Restaurant::pick_dish()
{
    return get_dish(input_str("Enter dish name: "));
}
void Restaurant::dish_list()
{
    cout
        << setw(75) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(10) << left << "| id " << '|'
        << setw(12) << left << "is available" << '|'
        << setw(50) << left << "Name"
        // << setw(30) << right
        << "|"
        << endl
        << setw(75) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = dishes.begin(); it != dishes.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(10) << left << "|" + to_string(it->getId()) << '|'

            << setw(12) << left << (it->isAvailable() ? "True" : "False") << '|'
            << setw(50) << left << it->getName() << '|' << endl
            << setw(75) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

//waiter group
bool Restaurant::add_waiter(Waiter t)
{
    if (get_waiter(t.getId()))
    {
        return false;
    }
    waiters.push_back(t);
    return true;
}
bool Restaurant::add_waiter()
{
    cout << "add new waiter: \n";
    Waiter i = Waiter::input();
    return add_waiter(i);
}
bool Restaurant::remove_waiter()
{
    Waiter *ptr = pick_waiter();
    if (!ptr)
    {
        cout << "Invalid table id";
        return false;
    }
    cout << "success";
    return remove_waiter(*ptr);
}
bool Restaurant::remove_waiter(Waiter w)
{
    waiters.remove(w);
    return true;
}
Waiter *Restaurant::get_waiter(int id)
{
    for (auto it = waiters.begin(); it != waiters.end(); it++)
    {
        if (it->getId() == id)
            return &*it;
    }
    return NULL;
}
Waiter *Restaurant::pick_waiter()
{
    return get_waiter(my_input_c<int>("Enter waiter id: "));
}
void Restaurant::waiter_list()
{
    cout
        << setw(53) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(5) << left << "| id " << '|'
        << setw(15) << left << "   phone" << '|'
        << setw(30) << left << "name"
        // << setw(30) << right
        << "|"
        << endl
        << setw(53) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = waiters.begin(); it != waiters.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(5) << left << "|" + to_string(it->getId()) << '|'
            << setw(15) << left << it->getPhone() << '|'
            << setw(30) << left << it->getName() << '|' << endl
            << setw(53) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

//Table group
bool Restaurant::add_table(Table t)
{
    if (get_table(t.getTable_id()))
    {
        return false;
    }
    tables.push_back(t);
    return true;
}

bool Restaurant::add_table()
{
    cout << "add new table: \n";
    Table i = Table::input();
    return add_table(i);
}
bool Restaurant::remove_table()
{
    Table *ptr = pick_table();
    if (!ptr)
    {
        cout << "Invalid table id";
        return false;
    }
    cout << "success";
    return remove_table(*ptr);
}
bool Restaurant::remove_table(Table t)
{
    tables.remove(t);
    return true;
}
Table *Restaurant::get_table(int id)
{
    for (auto it = tables.begin(); it != tables.end(); it++)
    {
        if (it->getTable_id() == id)
            return &*it;
    }
    return NULL;
}
Table *Restaurant::pick_table()
{
    return get_table(my_input_c<int>("Enter table id: "));
}
void Restaurant::table_list()
{
    cout
        << setw(25) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(10) << left << "| id " << '|'
        << setw(12) << left << "max capacity"
        // << setw(30) << right
        << "|"
        << endl
        << setw(25) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = tables.begin(); it != tables.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(10) << left << "|" + to_string(it->getTable_id()) << '|'
            << setw(12) << left << to_string(it->getMax_capacity()) << '|'

            << endl
            << setw(25) << setfill('*') << "" << endl
            << setfill(' ');
    }
}
bool Restaurant::select_ingridient()
{
    Ingridient *ptr = pick_ingridient();
    if (!ptr)
    {
        cout << "Invalid name";
        wait();
        clear();
        return false;
    }
    if (select_statement("View ingridient", "modify ingridinet"))
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
bool Restaurant::select_dish()
{
    Dish *ptr = pick_dish();
    if (!ptr)
    {
        cout << "Invalid name";
        wait();
        clear();
        return false;
    }
    if (select_statement("View dish", "modify dish"))
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
bool Restaurant::select_table()
{
    Table *ptr = pick_table();
    if (!ptr)
    {
        cout << "Invalid id";
        wait();
        clear();
        return false;
    }
    clear();
    if (select_statement("View table", "modify table"))
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
bool Restaurant::select_waiter()
{
    Waiter *ptr = pick_waiter();
    if (!ptr)
    {
        cout << "Invalid id";
        wait();
        clear();
        return false;
    }
    if (select_statement("View waiter", "modify waiter"))
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
// void Restaurant::ingridient_manage_view()
// {
//     int option;
//     bool loop = true;
//     while (loop)
//     {
//         int count = 1;
//         clear();

//         cout
//             << setw(3) << left << to_string(count++) + "."
//             << "add ingridient." << endl
//             << setw(3) << left << to_string(count++) + "."
//             << "remove ingridient." << endl
//             << setw(3) << left << to_string(count++) + "."
//             << "ingrdient list." << endl
//             << setw(3) << left << to_string(count++) + "."
//             << "modify ingridient." << endl

//             << endl
//             << setw(3) << left << "0."
//             << "Back." << endl;

//         cout << endl
//              << "Enter your choice: ";
//         cin >> option;
//         cin.ignore();
//         switch (option)
//         {
//         case 1:
//             clear();
//             meal_items_list();
//             break;
//         case 2:
//             clear();
//             add_meal_item();
//             break;
//         case 3:
//             clear();
//             remove_meal_item();
//             break;
//         case 4:
//             clear();
//             modify_meal_item();
//             break;
//         default:
//             loop = false;
//             break;
//         }
//     }

//     return;
// }

string Restaurant::getName()
{
    return this->name;
}

void Restaurant::setName(string name)
{
    this->name = name;
}

list<Ingridient> *Restaurant::getIngridients()
{
    return &this->ingridients;
}

void Restaurant::setIngridients(list<Ingridient> ingridients)
{
    this->ingridients = ingridients;
}

list<Dish> *Restaurant::getDishes()
{
    return &this->dishes;
}

void Restaurant::setDishes(list<Dish> dishes)
{
    this->dishes = dishes;
}

list<Table> *Restaurant::getTables()
{
    return &this->tables;
}

void Restaurant::setTables(list<Table> tables)
{
    this->tables = tables;
}

list<Waiter> *Restaurant::getWaiters()
{
    return &this->waiters;
}

void Restaurant::setWaiters(list<Waiter> waiters)
{
    this->waiters = waiters;
}