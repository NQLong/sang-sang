#include "../Header/MealItem.h"
#include "../Header/Restaurant.h"
MealItem::MealItem()
{
}
MealItem::~MealItem()
{
}
MealItem::MealItem(string name, int a)
{
    this->dish_name = name;
    this->quantity = a;
    update_price();
}
MealItem::MealItem(const MealItem &MI)
{
    this->dish_name = MI.dish_name;
    this->quantity = MI.quantity;
    this->price_single = MI.price_single;
}
MealItem &MealItem::operator=(const MealItem &MI)
{
    this->dish_name = MI.dish_name;
    this->quantity = MI.quantity;
    this->price_single = MI.price_single;
    return *this;
}
bool operator==(const MealItem &lhs, const MealItem &rhs)
{
    return (
        (lhs.dish_name == rhs.dish_name) &&
        (lhs.quantity == rhs.quantity)

    );
}

ostream &operator<<(ostream &os, const MealItem &mi)
{
    return os << mi.quantity << " x " << mi.dish_name << " - "
              << "Unit price: " << mi.price_single <<", Total: "<<mi.price_single*mi.quantity;
}

MealItem MealItem::input()
{
    MealItem temp;
    if (((Restaurant *)Holder::restaurant)->getDishes()->size() == 0)
    {
        clear();
        cout << "there is no Dish in Restaurant";
        temp.dish_name = "";
        wait();
        return temp;
    }

    while (true)
    {
        cout << "Dish name: ";
        getline(cin, temp.dish_name);

        if (!temp.get_dish(Holder::restaurant))
        {
            cout << "Invalid name, please try again";
            wait();
            clear();
            continue;
        }
        break;
    }

    cout << "Quantity: ";
    cin >> temp.quantity;
    temp.update_price();
    cin.ignore();
    return temp;
}

bool MealItem::commit(void *source)
{
    Dish *ptr = get_dish(source);
    if (!ptr)
    {
        cout << "Dish(" << this->dish_name << ") no longer exist";
        return false;
    }
    for (int i = 0; i < quantity; i++)
    {
        if (!ptr->commit(source))
        {
            cout << "for " << quantity << "more Dish(" << this->dish_name << ")";
            return false;
        }
    }
    // for (auto it = ptr->getIngridientList()->begin(); it != ptr->getIngridientList()->end(); it++)
    // {
    //     for (int i = 0; i < quantity; i++)
    //     {
    //         if (!it->commit(source))
    //         {
    //             cout << "for "<<quantity<<"more Dish(" << this->dish_name << ")";
    //             return false;
    //         }
    //     }
    // }
    return true;
}

void MealItem::update_price()
{
    this->price_single = get_dish(Holder::restaurant)->getPrice();
    return;
}

double MealItem::price_total()
{
    return price_single * quantity;
}
Dish *MealItem::get_dish(void *from)
{
    return ((Restaurant *)from)->get_dish(this->dish_name);
}

void MealItem::modify()
{
    cout << "Enter new quantity: ";
    cin >> this->quantity;
    cin.ignore();
}

string MealItem::getDish_name()
{
    return this->dish_name;
}

void MealItem::setDish_name(string dish_name)
{
    this->dish_name = dish_name;
}

int MealItem::getQuantity()
{
    return this->quantity;
}

void MealItem::setQuantity(int quantity)
{
    this->quantity = quantity;
}

double MealItem::getPrice_single()
{
    return this->price_single;
}

void MealItem::setPrice_single(double price_single)
{
    this->price_single = price_single;
}