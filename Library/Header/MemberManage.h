#ifndef A827541B_A1B5_4501_AD86_1626A5C1EAD6
#define A827541B_A1B5_4501_AD86_1626A5C1EAD6
#include "Member.h"

class MemberManage
{
public:
    MemberManage() {}
    virtual ~MemberManage() {}
    virtual bool add_member(Member) = 0;
    virtual bool add_member() = 0;
    virtual bool remove_member() = 0;
    virtual bool remove_member(Member) = 0;
    virtual Member *get_member(string email) = 0;
    virtual Member *get_member(int id) = 0;
    virtual Member *pick_member() = 0;
    virtual bool select_member() = 0;
    virtual void members_list() = 0;
};

#endif /* A827541B_A1B5_4501_AD86_1626A5C1EAD6 */
