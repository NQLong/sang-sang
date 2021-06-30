#ifndef C79EA926_D358_44BE_94F1_C24BB39D657B
#define C79EA926_D358_44BE_94F1_C24BB39D657B

#include "Account.h"

class Librarian
    : public Account
{
private:
public:
    Librarian();
    ~Librarian();
    Librarian(
        AccountStatus stat,

        string full_name,
        time_t date_of_birth,
        string phone,
        string email,
        Address address,
        string password);

    static Librarian input();
    static void render(list<Librarian> lst);
    void view();
    void books_manage();
    void member_manage();
    void request_manage();
    void librarian_manage();
    bool process_book_request();
    bool make_book_request();
};

#endif /* C79EA926_D358_44BE_94F1_C24BB39D657B */
