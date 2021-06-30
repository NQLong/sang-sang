#ifndef E727424F_4FEE_46A3_A23E_14921E54031D
#define E727424F_4FEE_46A3_A23E_14921E54031D
#include "MealItem.h"
#include "../Header/Client.h"
class Meal
{
private:
    int meal_id = -1;
    int table_id = -1;
    list<MealItem> items;
    int waiter_id = -1;
    string client_tax_number = "";
    time_t start;
    double duration;

    static int new_id;
    static list<Meal> meals;

public:
    Meal();
    Meal(const Meal &other);
    ~Meal();
    Meal(
        int table_id,
        list<MealItem> items,
        int waiter_id,
        string client_tax_number,
        time_t start,
        double duration

    );
    friend bool operator==(const Meal &, const Meal &);
    friend ostream &operator<<(ostream &, const Meal &);

    bool commit(void *source);

    static Meal input();
    static bool add_meal();
    static bool add_meal(Meal);
    static Meal *get_meal(int id);
    static Meal *pick_meal();
    static bool remove_meal();
    static bool remove_meal(Meal);
    static bool select_meal();
    static void meals_list();

    static list<Meal> *getMeals();
    static void setMeals(list<Meal> meals);

    void modify();
    void modify_meal_items();

    int pick_table();
    int pick_waiter();
    string pick_client();

    bool check();

    bool add_meal_item();
    bool add_meal_item(MealItem);
    bool remove_meal_item();
    bool remove_meal_item(MealItem);
    void modify_meal_item();
    void meal_items_list();

    MealItem *pick_meal_item();
    MealItem *get_meal_item(string name);

    double total_price();
    int total_item() ;

    int getMeal_id();
    void setMeal_id(int meal_id);
    int getTable_id();
    void setTable_id(int table_id);
    list<MealItem> *getItems();
    void setItems(list<MealItem> items);
    int getWaiter_id();
    void setWaiter_id(int waiter_id);
    string getClient_tax_number();
    void setClient_tax_number(string client_tax_number);
    int getNew_id();
    void setNew_id(int new_id);
    time_t getStart();
    void setStart(time_t start);
    double getDuration();
    void setDuration(double duration);
};

#endif /* E727424F_4FEE_46A3_A23E_14921E54031D */
