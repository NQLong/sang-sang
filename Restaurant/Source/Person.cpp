#include "../Header/Person.h"
Person::Person()
{
}
Person::~Person()
{
}
Person::Person(string _name, Address _address)
{
    this->name = _name;
    this->address = _address;
}

bool operator==(const Person &lhs, const Person &rhs){
    return (
        (lhs.name == rhs.name) && 
        (lhs.address == rhs.address)

    );
}

void Person::input_person()
{
    cout << "Name: ";
    getline(cin, this->name);
    cout << "Address: " << endl;
    this->address = Address::inputAddress();
}

void Person::modify_person()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify name." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify address." << endl

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
            cout << "Name: ";
            getline(cin, this->name);
            break;
        case 2:
            clear();
            cout << "Address: " << endl;
            this->address = Address::inputAddress();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

ostream &operator<<(ostream &os, const Person &p){
    return os<<"Name: "<<p.name<<endl<<"Address"<<p.address;
}

//getter setter




string Person::getName()
{
    return this->name;
}

void Person::setName(string name)
{
    this->name = name;
}

Address Person::getAddress()
{
    return this->address;
}

void Person::setAddress(Address address)
{
    this->address = address;
}



