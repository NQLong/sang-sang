#ifndef C8E006EA_87C6_44D7_AD73_AA2308EE39C1
#define C8E006EA_87C6_44D7_AD73_AA2308EE39C1

#include "Account.h"

class Member
    : public Account
{
private:
public:
    Member();
    ~Member();
    Member(
        AccountStatus stat,
        
        string full_name,
        time_t date_of_birth,
        string phone,
        string email,
        Address address,
        string password);

    friend bool operator==(const Member &lhs, const Member &rhs);
    friend ostream &operator<<(ostream &os, const Member &author);

    static void render(list<Member> members);

    static Member input();

    void view();
    bool authentiacate();
    bool make_book_request();
};

#endif /* C8E006EA_87C6_44D7_AD73_AA2308EE39C1 */
