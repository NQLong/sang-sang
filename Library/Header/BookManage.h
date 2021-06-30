#ifndef A0327C4C_44D4_467F_B473_80DE306BFC63
#define A0327C4C_44D4_467F_B473_80DE306BFC63

#include "Book.h"

class BookManage
{
public:
    BookManage() {}
    virtual ~BookManage() {}
    virtual bool add_book(Book) = 0;
    virtual bool add_book() = 0;
    virtual bool remove_book() = 0;
    virtual bool remove_book(Book) = 0;
    virtual Book *get_book(string name, string by) = 0;
    virtual Book *pick_book() = 0;
    virtual bool select_book() = 0;
    virtual void books_list(list<Book> books) = 0;
};

#endif /* A0327C4C_44D4_467F_B473_80DE306BFC63 */
