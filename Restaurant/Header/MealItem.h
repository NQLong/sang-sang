#ifndef A845BDDC_86F7_46E0_92E8_3E1E73D6A014
#define A845BDDC_86F7_46E0_92E8_3E1E73D6A014

#include "Dish.h"
class MealItem
{
private:
    string dish_name;
    int quantity;
    double price_single;


public:
    MealItem();
    ~MealItem();
    MealItem(string, int);
    MealItem(const MealItem &);
    MealItem &operator=(const MealItem &);
    friend bool operator==(const MealItem &, const MealItem &);
    friend ostream &operator<<(ostream &, const MealItem &);
    static MealItem input();

    Dish *get_dish(void *from);

    void modify();

    bool commit(void * from);

    void update_price();

    double price_total();

    string getDish_name();
    void setDish_name(string dish_name);
    int getQuantity();
    void setQuantity(int quantity);
    double getPrice_single();
    void setPrice_single(double price_single);
};

#endif /* A845BDDC_86F7_46E0_92E8_3E1E73D6A014 */
