#ifndef F210FDE9_766A_41E8_8392_7D6C3DD746C7
#define F210FDE9_766A_41E8_8392_7D6C3DD746C7
#include "IngridientManage.h"
#include "DishManage.h"
#include "TableManage.h"
#include "WaiterManage.h"

class Restaurant
    : public IngridientManage,
      public DishManage,
      public TableManage,
      public WaiterManage

{
private:
    string name;
    list<Ingridient> ingridients;
    list<Dish> dishes;
    list<Table> tables;
    list<Waiter> waiters;

public:
    Restaurant();
    ~Restaurant();
    Restaurant(
        string name,
        list<Ingridient> ingridients,
        list<Dish> dishes,
        list<Table> tables,
        list<Waiter> waiters

    );

    void modify();

    void view();

    //Ingridient group
    bool add_ingiridient(Ingridient);
    bool add_ingiridient();
    bool remove_ingridient();
    bool remove_ingridient(Ingridient);
    Ingridient *get_ingridient(string name);
    Ingridient *pick_ingridient();
    bool select_ingridient();
    void ingridient_list();
    // void ingridient_manage_view();

    //Dish group
    bool add_dish(Dish);
    bool add_dish();
    bool remove_dish();
    bool remove_dish(Dish);
    Dish *get_dish(string name);
    Dish *get_dish(int id);
    Dish *pick_dish();
    void dish_list();
    bool select_dish();
    // void dish_manage_view();

    //Table group
    bool add_table(Table);
    bool add_table();
    bool remove_table();
    bool remove_table(Table);
    Table *get_table(int id);
    Table *pick_table();
    void table_list();
    bool select_table();
    // void table_manage_view();

    //waiter group
    bool add_waiter(Waiter);
    bool add_waiter();
    bool remove_waiter();
    bool remove_waiter(Waiter);
    Waiter *get_waiter(int id);
    Waiter *pick_waiter();
    bool select_waiter();
    void waiter_list();
    // void waiter_manage_view();

    //getter setter
    string getName();
    void setName(string name);
    list<Ingridient> *getIngridients();
    void setIngridients(list<Ingridient> ingridients);
    list<Dish> *getDishes();
    void setDishes(list<Dish> dishes);
    list<Table> *getTables();
    void setTables(list<Table> tables);
    list<Waiter> *getWaiters();
    void setWaiters(list<Waiter> waiters);
};

#endif /* F210FDE9_766A_41E8_8392_7D6C3DD746C7 */
