#ifndef C3D2BABC_455A_4A44_8228_F16219F807C3
#define C3D2BABC_455A_4A44_8228_F16219F807C3

#include "BookRequest.h"
#include "Catalog.h"
#include "MemberManage.h"
#include "LibrarianManage.h"
#include "RequestManage.h"
class Library
    : public MemberManage,
      public LibrarianManage,
      public RequestManage
{
    string name;
    Catalog catalog;
    list<Member> members;
    list<Librarian> librarians;
    list<BookRequest> requests;

public:
    Library();
    ~Library();
    Library(
        string name,
        Catalog catalog,
        list<Member> members,
        list<Librarian> librarians,
        list<BookRequest> requests);

    //catalog

    //members group
    bool add_member(Member);
    bool add_member();
    bool remove_member();
    bool remove_member(Member);
    Member *get_member(string email);
    Member *get_member(int id);
    Member *pick_member();
    bool select_member();
    void members_list();

    //librarian group
    bool add_librarian(Librarian);
    bool add_librarian();
    bool remove_librarian();
    bool remove_librarian(Librarian);
    Librarian *get_librarian(string email);
    Librarian *pick_librarian();
    bool select_librarian();
    void librarians_list();

    //requests group
    bool add_request(BookRequest);
    bool add_request();
    bool remove_request();
    bool remove_request(BookRequest);
    BookRequest *get_request(int id);
    BookRequest *pick_request();
    bool select_request();
    void requests_list();

    string getName();
    void setName(string name);
    Catalog *getCatalog();
    void setCatalog(Catalog catalog);
    list<Member> *getMembers();
    void setMembers(list<Member> members);
    list<Librarian> *getLibrarians();
    void setLibrarians(list<Librarian> librarians);
    list<BookRequest> *getRequests();
    void setRequests(list<BookRequest> requests);
};

#endif /* C3D2BABC_455A_4A44_8228_F16219F807C3 */
