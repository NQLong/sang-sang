#ifndef E34ABC36_312F_4360_8288_634319D69185
#define E34ABC36_312F_4360_8288_634319D69185

#include "Constraint.h"

class Account
{
    int account_id;
    AccountStatus stat = ACTIVE;
    AccountType typ;
    string full_name;
    time_t date_of_birth;
    string phone;
    string email;
    string password;
    Address address;

    static int new_id;

public:
    Account();
    ~Account();
    Account(
        AccountStatus stat,
        AccountType typ,
        string full_name,
        time_t date_of_birth,
        string phone,
        string email,
        Address address,
        string password);

    friend ostream &operator<<(ostream &os, const Account &);
    friend bool operator==(const Account &lhs, const Account &rhs);

    void render_account();

    void input_account();

    void modify();

    int getAccount_id();
    void setAccount_id(int account_id);
    AccountStatus getStat();
    void setStat(AccountStatus stat);
    AccountType getTyp();
    void setTyp(AccountType typ);
    string getFull_name();
    void setFull_name(string full_name);
    time_t getDate_of_birth();
    void setDate_of_birth(time_t date_of_birth);
    string getPhone();
    void setPhone(string phone);
    string getEmail();
    void setEmail(string email);
    Address getAddress();
    void setAddress(Address address);
    string getPassword();
    void setPassword(string password);
    static int getNew_id();
    static void setNew_id(int new_id);
};

#endif /* E34ABC36_312F_4360_8288_634319D69185 */
