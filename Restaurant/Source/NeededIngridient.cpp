#include "../Header/NeededIngridient.h"
#include "../Header/Restaurant.h"
NeededIngridient::NeededIngridient() {}
NeededIngridient::NeededIngridient(string name, double amount)
{
    this->ingridient_name = name;
    this->amount = amount;
}

NeededIngridient::NeededIngridient(const NeededIngridient &ingriQuant)
{
    this->ingridient_name = ingriQuant.ingridient_name;
    this->amount = ingriQuant.amount;
}

NeededIngridient &NeededIngridient::operator=(const NeededIngridient &ingriQuant)
{
    this->ingridient_name = ingriQuant.ingridient_name;
    this->amount = ingriQuant.amount;
    return *this;
}

Ingridient *NeededIngridient::get_ingridient(void *from)
{
    return ((Restaurant *)from)->get_ingridient(this->ingridient_name);
}

bool NeededIngridient::commit(void *source)
{
    Ingridient *ptr = get_ingridient(source);
    if (!ptr)
    {
        cout << "Ingridient(" << this->ingridient_name << ") is missing ";
        return false;
    }
    else if (!ptr->isAvailable())
    {
        cout << "Ingridient(" << this->ingridient_name << ") is not available ";
        return false;
    }
    else if (ptr->getStock() < this->amount)
    {
        cout << "Not enough Ingrdient(" << this->ingridient_name << ")";
        return false;
    }
    ptr->setStock(
        ptr->getStock() - amount

    );
    return true;
}

NeededIngridient NeededIngridient::input()
{
    NeededIngridient temp;
    if (((Restaurant *)Holder::restaurant)->getIngridients()->size() == 0)
    {
        clear();
        cout << "there is no Ingridient in Restaurant";
        temp.ingridient_name = "";
        wait();
        return temp;
    }
    bool loop = true;

    while (loop)
    {
        cout << "Ingridient name: ";
        getline(cin, temp.ingridient_name);
        if (!temp.get_ingridient(Holder::restaurant))
        {
            cout << "Invalid name, please try again";
            wait();
            clear();
            continue;
        }
        loop = false;
    }

    cout << "Amoint: ";
    cin >> temp.amount;
    cin.ignore();
    return temp;
}

void NeededIngridient::modify()
{
    cout << "Amoint: ";
    cin >> amount;
    cin.ignore();
}

string NeededIngridient::getIngridient_name()
{
    return ingridient_name;
}
void NeededIngridient::setIngridient_name(string ingridient_name)
{
    this->ingridient_name = ingridient_name;
}
double NeededIngridient::getAmount()
{
    return this->amount;
}
void NeededIngridient::setAmount(double amount)
{
    this->amount = amount;
}

ostream &operator<<(ostream &os, const NeededIngridient &NI)
{
    NeededIngridient temp = NI;
    os << NI.amount <<" x";
    if (temp.get_ingridient(Holder::restaurant))
        os << " "<<temp.get_ingridient(Holder::restaurant)->getMeasure_unit();
    return os<<" "<<NI.ingridient_name;
}

bool operator==(const NeededIngridient &lhs, const NeededIngridient &rhs)
{
    return ((lhs.ingridient_name == rhs.ingridient_name) && (lhs.amount == rhs.amount));
}