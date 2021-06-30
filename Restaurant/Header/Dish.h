#ifndef CCE8C040_5A1E_473C_B5BB_9BAE4086D9C9
#define CCE8C040_5A1E_473C_B5BB_9BAE4086D9C9


#include "NeededIngridient.h"
class Dish
{
private:
    int id;
    string name;
    list<NeededIngridient> ingridientList;
    double price;

    static int new_id;

public:
    Dish();
    Dish(string, list<NeededIngridient>, double);
    Dish(const Dish &);

    Dish &operator=(const Dish &);

    friend ostream &operator<<(ostream &, const Dish &);
    friend bool operator==(const Dish &lhs, const Dish &rhs);
    
    static Dish input();

    NeededIngridient *pick_ingridient();
    NeededIngridient *get_ingridient(string name);

    void modify();
    void modify_ingridients_list();

    bool isAvailable();
    bool commit(void *source);

    bool add_ingridient(NeededIngridient);
    bool add_ingridient();
    bool remove_ingridient(NeededIngridient);
    bool remove_ingridient();
    bool is_consist_of_ingridient(NeededIngridient);
    bool modify_ingridient();

    int getId();
    void setId(int id);
    string getName();
    void setName(string name);
    list<NeededIngridient> *getIngridientList();
    void setIngridientList(list<NeededIngridient> ingridientList);
    double getPrice();
    void setPrice(double price);
};

#endif /* CCE8C040_5A1E_473C_B5BB_9BAE4086D9C9 */
