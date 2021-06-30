#ifndef CD079305_DA48_4314_87A7_D091D09AF2DF
#define CD079305_DA48_4314_87A7_D091D09AF2DF

#include "Constraint.h"

class Person
{

    string name;
    Address address;

public:
    Person();
    ~Person();
    Person(string, Address);

    void input_person();

    void modify_person();

    friend bool operator==(const Person &lhs, const Person &rhs);
    friend ostream &operator<<(ostream &, const Person &);

    string getName();
    void setName(string name);
    Address getAddress();
    void setAddress(Address address);
};

#endif /* CD079305_DA48_4314_87A7_D091D09AF2DF */
