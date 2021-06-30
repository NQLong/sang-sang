#ifndef E65A23F9_5CDE_4FB3_AADC_4AD5EA718273
#define E65A23F9_5CDE_4FB3_AADC_4AD5EA718273
#include "Librarian.h"

class LibrarianManage
{
public:
    LibrarianManage() {}
    virtual ~LibrarianManage() {}
    virtual bool add_librarian(Librarian) = 0;
    virtual bool add_librarian() = 0;
    virtual bool remove_librarian() = 0;
    virtual bool remove_librarian(Librarian) = 0;
    virtual Librarian *get_librarian(string email) = 0;
    // virtual Librarian *get_librarian(int id) = 0;
    virtual Librarian *pick_librarian() = 0;
    virtual bool select_librarian() = 0;
    virtual void librarians_list() = 0;
};

#endif /* E65A23F9_5CDE_4FB3_AADC_4AD5EA718273 */
