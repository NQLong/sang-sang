#ifndef B607FE79_DFA9_462B_A984_33A8377F0E17
#define B607FE79_DFA9_462B_A984_33A8377F0E17
#include "Person.h"

class Waiter
    : public Person
{
    int id;
    string phone;

    static int new_id;

public:
    Waiter();
    ~Waiter();
    Waiter(string phone, string name , Address address);

    int getId();
    void setId(int id);
    string getPhone();
    void setPhone(string phone);
    static int getNew_id();
    static void setNew_id(int new_id);

    friend bool operator==(const Waiter &lhs, const Waiter &rhs);
    friend ostream &operator<<(ostream &, const Waiter &);

    static Waiter input();

    void modify();
};

#endif /* B607FE79_DFA9_462B_A984_33A8377F0E17 */
