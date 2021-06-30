#ifndef D43CE051_2102_4C7A_B4E9_A04DC09FFB38
#define D43CE051_2102_4C7A_B4E9_A04DC09FFB38
#include "Ingridient.h"
class IngridientManage
{
    public:
    virtual bool add_ingiridient(Ingridient) = 0;
    virtual bool add_ingiridient() = 0;
    virtual bool remove_ingridient() = 0;
    virtual bool remove_ingridient(Ingridient) = 0;
    virtual Ingridient *get_ingridient(string name) = 0;
    virtual Ingridient *pick_ingridient() = 0;
    virtual bool select_ingridient() = 0;
    virtual void ingridient_list() = 0;
};

#endif /* D43CE051_2102_4C7A_B4E9_A04DC09FFB38 */
