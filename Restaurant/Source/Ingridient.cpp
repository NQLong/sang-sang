#include "../Header/Ingridient.h"

Ingridient::Ingridient() {}

ostream &operator<<(ostream &os, const Ingridient &i)
{
    return os
           << "Name: " << i.name << endl
           << "Sotck: " << i.stock << "(" << i.measure_unit << ")";

    ;
}
bool operator==(const Ingridient &lhs, const Ingridient &rhs)
{
    return (

        (lhs.name == rhs.name) &&
        (lhs.stock == rhs.stock) &&
        (lhs.measure_unit == rhs.measure_unit) &&
        (lhs.available == rhs.available)

    );
}

Ingridient::Ingridient(string name, string measure, double stock)
{
    this->name = name;
    this->measure_unit = measure;
    this->stock = stock;
}

Ingridient::Ingridient(string name, string measure, double stock, bool stat)
{
    this->name = name;
    this->measure_unit = measure;
    this->stock = stock;
    this->available = stat;
}

Ingridient::Ingridient(const Ingridient &ingri)
{
    this->name = ingri.name;
    this->stock = ingri.stock;
    this->measure_unit = ingri.measure_unit;
    this->available = ingri.available;
}

Ingridient &Ingridient::operator=(const Ingridient &ingri)
{
    this->name = ingri.name;
    this->stock = ingri.stock;
    this->measure_unit = ingri.measure_unit;
    this->available = ingri.available;
    return *this;
}

Ingridient Ingridient::input_ingridient()
{
    Ingridient temp;
    cout << "Ingridient name:";
    getline(cin, temp.name);
    cout << "Ingridient measure_unit:";
    getline(cin, temp.measure_unit);
    cout << "Ingridient stock: ";
    cin >> temp.stock;
    cin.ignore();
    return temp;
}

void Ingridient::modify()
{
    int option;
    bool loop = true;

    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "modify measure unit." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify stock." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify status." << endl

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
            cout << "new measure unit : ";
            getline(cin, this->measure_unit);
            break;
        case 2:
            clear();
            cout << "new stock: ";
            cin >> this->stock;
            break;
        case 3:
            clear();
            cout << "Modify available status: " << endl;
            this->available = select_statement("Not available", "Available");
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

string Ingridient::getName()
{
    return name;
}

string Ingridient::getMeasure_unit()
{
    return measure_unit;
}

double Ingridient::getStock()
{
    return stock;
}

void Ingridient::setName(string name)
{
    this->name = name;
}
void Ingridient::setMeasureUnit(string _measure)
{
    measure_unit = _measure;
}
void Ingridient::setStock(double q)
{
    stock = q;
}

bool Ingridient::isAvailable()
{
    return available;
}

void Ingridient::setAvailable(bool available)
{
    this->available = available;
}
