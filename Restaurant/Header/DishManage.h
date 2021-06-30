#ifndef A89B3831_B24A_4A72_97F0_EBB4A41444C9
#define A89B3831_B24A_4A72_97F0_EBB4A41444C9
#include "Dish.h"

class DishManage
{
public
    :
    virtual bool add_dish(Dish) = 0;
    virtual bool add_dish() = 0;
    virtual bool remove_dish() = 0;
    virtual bool remove_dish(Dish) = 0;
    virtual Dish *get_dish(string name) = 0;
    virtual Dish *get_dish(int id) = 0;
    virtual Dish *pick_dish() = 0;
    virtual void dish_list() = 0;
    virtual bool select_dish() = 0;
};

#endif /* A89B3831_B24A_4A72_97F0_EBB4A41444C9 */
