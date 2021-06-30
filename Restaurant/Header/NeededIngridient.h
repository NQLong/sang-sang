#ifndef C094DFA0_E291_4807_A84C_FE9BCE7B4E0D
#define C094DFA0_E291_4807_A84C_FE9BCE7B4E0D


#include "Ingridient.h"

class NeededIngridient
{
private:
    string ingridient_name;
    double amount;

public:
    NeededIngridient();
    NeededIngridient(const NeededIngridient &);
    NeededIngridient(string, double);

    NeededIngridient &operator=(const NeededIngridient &);

    friend bool operator==(const NeededIngridient &, const NeededIngridient &);
    Ingridient *get_ingridient(void *from);

    bool commit(void *from);

    static NeededIngridient input();

    void modify();

    

    string getIngridient_name();
    void setIngridient_name(string ingridient_name);
    double getAmount();
    void setAmount(double amount);

    friend ostream &operator<<(ostream &, const NeededIngridient &);
};

#endif /* C094DFA0_E291_4807_A84C_FE9BCE7B4E0D */
