#include "../Header/Waiter.h"

int Waiter::new_id = 0;

Waiter::Waiter()
{
    this->id = new_id++;
}

Waiter::~Waiter() {}

Waiter::Waiter(string _phone, string name, Address address)
    : Person(name, address), phone(_phone), id(new_id++)
{
}

bool operator==(const Waiter &lhs, const Waiter &rhs)
{
    return (
        (lhs.id == rhs.id) &&
        (lhs.phone == rhs.phone) &&
        ((Person)(lhs) == (Person)(rhs)));
}

ostream &operator<<(ostream &os, const Waiter &w)
{
    return os << "Waiter id: " << w.id << endl
              << (Person)w << endl
              << "Phone number" << w.phone;
}

Waiter Waiter::input()
{
    Waiter temp;
    temp.input_person();
    cout << "Phone number: ";
    getline(cin, temp.phone);
    return temp;
}

void Waiter::modify()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify phone number." << endl
            << setw(3) << left << to_string(count++) + "."
            << "more modify option." << endl

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
            cout << "Enter phone number";
            getline(cin, phone);
            
            break;
        case 2:
            clear();
            this->modify_person();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

///getter setter
int Waiter::getId()
{
    return this->id;
}

void Waiter::setId(int id)
{
    this->id = id;
}

string Waiter::getPhone()
{
    return this->phone;
}

void Waiter::setPhone(string phone)
{
    this->phone = phone;
}

int Waiter::getNew_id()
{
    return new_id;
}

void Waiter::setNew_id(int _new_id)
{
    new_id = _new_id;
}
