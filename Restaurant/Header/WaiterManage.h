#ifndef F6782EA1_B316_4D1A_83F3_DE3C38E7D929
#define F6782EA1_B316_4D1A_83F3_DE3C38E7D929
#include "Waiter.h"

class WaiterManage
{
public:
    WaiterManage() {}
    virtual ~WaiterManage() {}
    virtual bool add_waiter(Waiter) = 0;
    virtual bool add_waiter() = 0;
    virtual bool remove_waiter() = 0;
    virtual bool remove_waiter(Waiter) = 0;
    virtual Waiter *get_waiter(int id) = 0;
    virtual Waiter *pick_waiter() = 0;
    virtual bool select_waiter() = 0;
    virtual void waiter_list() = 0;
};

#endif /* F6782EA1_B316_4D1A_83F3_DE3C38E7D929 */
