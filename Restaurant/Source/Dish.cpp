
#include "../Header/Dish.h"
#include "../Header/Restaurant.h"

int Dish::new_id = 0;

ostream &operator<<(ostream &os, const Dish &d)
{
    os
        << "Dish id: " << d.id << endl
        << "Name: " << d.name << endl
        << "Needed ingridient: " << endl;

    for (auto it = d.ingridientList.begin(); it != d.ingridientList.end(); it++)
    {
        os << setw(5) <<""<< *it << endl;
    }
    return os << "Price: " << d.price << " $";
}
bool operator==(const Dish &lhs, const Dish &rhs)
{
    return (lhs.id == rhs.id) &&
           (lhs.name == rhs.name);
}
Dish::Dish()
{
    this->id = new_id++;
}

Dish::Dish(string _name, list<NeededIngridient> _ingriList, double price)
{
    name = _name;
    id = new_id++;
    ingridientList = _ingriList;
    this->price = price;
}

Dish::Dish(const Dish &_dish)
{
    this->id = _dish.id;
    this->name = _dish.name;
    this->ingridientList = _dish.ingridientList;
    this->price = _dish.price;
}

Dish &Dish::operator=(const Dish &_dish)
{
    this->price = _dish.price;
    this->id = _dish.id;
    this->name = _dish.name;
    this->ingridientList = _dish.ingridientList;
    return *this;
}

Dish Dish::input()
{
    Dish temp;

    while (true)
    {
        cout << "Dish 's name: ";
        getline(cin, temp.name);
        if (((Restaurant *)Holder::restaurant)->get_dish(temp.name))
        {
            cout << "Invalid name, please try again";
            wait();
            clear();
            continue;
        }
        break;
    }

    cout << "Price: ";
    cin >> temp.price;
    cin.ignore();

    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Add an ingridient more." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Done." << endl
            << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            if (!temp.add_ingridient())
            {
                cout << "Ingridient already exist";
                wait();
            }
            break;
        default:
            loop = false;
            break;
        }
    }

    return temp;
}

void Dish::modify()
{
    int option;
    bool loop = true;
    string temp_string;

    while (loop)
    {
        int count = 1;
        clear();

        cout

            << setw(3) << left << to_string(count++) + "."
            << "Modify price ." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify ingridients list ." << endl
            << endl
            << setw(3) << "0. "
            << "Done." << endl
            << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {

        case 1:
            clear();
            cout << "New price: ";
            cin >> this->price;
            cin.ignore();
            break;
        case 2:
            clear();
            this->modify_ingridients_list();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Dish::modify_ingridients_list()
{
    int option;
    bool loop = true;
    string temp_string;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "Remove an ingridient ." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Add an ingridient ." << endl
            << setw(3) << left << to_string(count++) + "."
            << "Modify ingridient amount ." << endl

            << "Done." << endl
            << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            remove_ingridient();
            break;
        case 2:
            clear();
            add_ingridient();
            break;
        case 3:
            clear();
            modify_ingridient();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Dish::modify_ingridient()
{
    NeededIngridient *ptr = pick_ingridient();
    if (!ptr)
    {
        cout << "Modification fail";
        wait();
        return false;
    }
    ptr->modify();
    return true;
}

bool Dish::remove_ingridient(NeededIngridient NI)
{
    ingridientList.remove(NI);
    return true;
}

bool Dish::remove_ingridient()
{
    clear();
    NeededIngridient *NI = pick_ingridient();
    clear();
    if (!NI)
    {

        cout << "Removeation fail";
        wait();
        return false;
    }
    return remove_ingridient(*NI);
}

NeededIngridient *Dish::pick_ingridient()
{
    list<string> lst;
    if (this->ingridientList.size() == 0)
    {
        cout << "there no ingridient to choose";
        wait();
        return NULL;
    }
    for (auto it = ingridientList.begin(); it != ingridientList.end(); it++)
    {
        lst.push_back(it->getIngridient_name());
    }
    clear();
    return this->get_ingridient(select_statements(lst));
}

NeededIngridient *Dish::get_ingridient(string name)
{
    for (auto it = ingridientList.begin(); it != ingridientList.end(); it++)
    {
        if (it->getIngridient_name() == name)
            return &*it;
    }
    return NULL;
}

bool Dish::add_ingridient(NeededIngridient ni)
{
    if (this->is_consist_of_ingridient(ni))
        return false;
    this->ingridientList.push_back(ni);
    return true;
}

bool Dish::add_ingridient()
{
    clear();
    cout << "Add ingridient: " << endl
         << endl;
    return this->add_ingridient(NeededIngridient::input());
}

bool Dish::is_consist_of_ingridient(NeededIngridient ni)
{
    for (auto it = this->ingridientList.begin(); it != this->ingridientList.end(); it++)
    {
        if (it->getIngridient_name() == ni.getIngridient_name())
            return true;
    }
    return false;
}

//getter setter
int Dish::getId()
{
    return this->id;
}

void Dish::setId(int id)
{
    this->id = id;
}

string Dish::getName()
{
    return this->name;
}

void Dish::setName(string name)
{
    this->name = name;
}
bool Dish::isAvailable()
{
    for (auto it = this->getIngridientList()->begin(); it != this->getIngridientList()->end(); it++)
    {
        if (it->get_ingridient(Holder::restaurant) && it->get_ingridient(Holder::restaurant)->getStock() < it->getAmount())
            return false;
    }
    return true;
}

bool Dish::commit(void *source)
{
    for (auto it = this->getIngridientList()->begin(); it != this->getIngridientList()->end(); it++)
    {
        if (!it->commit(source))
        {
            return false;
        }
    }

    return true;
}

list<NeededIngridient> *Dish::getIngridientList()
{
    return &this->ingridientList;
}

void Dish::setIngridientList(list<NeededIngridient> ingridientList)
{
    this->ingridientList = ingridientList;
}

double Dish::getPrice()
{
    return this->price;
}

void Dish::setPrice(double price)
{
    this->price = price;
}
