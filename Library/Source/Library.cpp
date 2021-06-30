#include "../Header/Library.h"

Library::Library() {}
Library::~Library() {}
Library::Library(
    string name,
    Catalog catalog,
    list<Member> members,
    list<Librarian> librarians,
    list<BookRequest> requests)
{
    this->name = name;
    this->catalog = catalog;
    this->members = members;
    this->librarians = librarians;
    this->requests = requests;
}

bool Library::add_member(Member i)
{
    if (get_member(i.getEmail()))
    {
        return false;
    }
    members.push_back(i);
    return true;
}

bool Library::add_member()
{
    cout << "add new member: " << endl;
    Member i = Member::input();
    return add_member(i);
}
bool Library::remove_member()
{
    Member *ptr = pick_member();
    if (!ptr)
    {
        cout << "Invalid emmail";
        return false;
    }
    cout << "success";
    return remove_member(*ptr);
}
bool Library::remove_member(Member i)
{
    members.remove(i);
    return true;
}
Member *Library::get_member(string email)
{
    for (auto it = members.begin(); it != members.end(); it++)
    {
        if (it->getEmail() == email)
            return &*it;
    }
    return NULL;
}
Member *Library::get_member(int id)
{
    for (auto it = members.begin(); it != members.end(); it++)
    {
        if (it->getAccount_id() == id)
            return &*it;
    }
    return NULL;
}

Member *Library::pick_member()
{
    return get_member(input_str("Enter email: "));
}

bool Library::select_member()
{
    Member *ptr = pick_member();
    if (!ptr)
    {
        cout << "Invalid email";
        wait();
        clear();
        return false;
    }
    if (select_statement("View info", "modify member account status"))
    {
        clear();
        ptr->setStat(select_account_status());
    }
    else
    {
        clear();
        cout << *ptr;
        wait();
    }
    return true;
}

void Library::members_list()
{
    Member::render(members);
}

//librarian group
bool Library::add_librarian(Librarian i)
{
    if (get_librarian(i.getEmail()))
    {
        return false;
    }
    librarians.push_back(i);
    return true;
}
bool Library::add_librarian()
{
    cout << "add new librarian: " << endl;
    Librarian i = Librarian::input();
    return add_librarian(i);
}
bool Library::remove_librarian()
{
    Librarian *ptr = pick_librarian();
    if (!ptr)
    {
        cout << "Invalid emmail";
        return false;
    }
    cout << "success";
    return remove_librarian(*ptr);
}
bool Library::remove_librarian(Librarian i)
{
    librarians.remove(i);
    return true;
}
Librarian *Library::get_librarian(string email)
{
    for (auto it = librarians.begin(); it != librarians.end(); it++)
    {
        if (it->getEmail() == email)
            return &*it;
    }
    return NULL;
}
Librarian *Library::pick_librarian()
{
    return get_librarian(input_str("Enter email: "));
}

bool Library::select_librarian()
{
    Librarian *ptr = pick_librarian();
    if (!ptr)
    {
        cout << "Invalid email";
        wait();
        clear();
        return false;
    }

    if (select_statement("View info", "modify member account status"))
    {
        clear();
        ptr->setStat(select_account_status());
    }

    else
    {
        clear();
        cout << *ptr;
        wait();
    }
    return true;
}

void Library::librarians_list()
{
    Librarian::render(librarians);
}

//requests
bool Library::add_request(BookRequest i)
{
    if (get_request(i.getBLcode()))
    {
        return false;
    }
    requests.push_back(i);
    return true;
}
bool Library::add_request()
{
    return this->catalog.add_book_request();
};
bool Library::remove_request()
{
    BookRequest *ptr = pick_request();
    if (!ptr)
    {
        cout << "Invalid blcode";
        return false;
    }
    cout << "success";
    return remove_request(*ptr);
}
bool Library::remove_request(BookRequest i)
{
    requests.remove(i);
    return true;
}
BookRequest *Library::get_request(int id)
{
    for (auto it = requests.begin(); it != requests.end(); it++)
    {
        if (it->getBLcode() == id)
            return &*it;
    }
    return NULL;
}
BookRequest *Library::pick_request()
{
    return get_request(my_input_c<int>("Enter BLcode: "));
}
bool Library::select_request()
{
    BookRequest *ptr = pick_request();
    if (!ptr)
    {
        cout << "Invalid blcode";
        wait();
        clear();
        return false;
    }
    if (select_statement("View request", "apply action on request"))
    {
        ptr->take_action();
    }
    else
    {
        clear();
        cout << *ptr;
        wait();
    }
    return true;
}
void Library::requests_list()
{
    BookRequest::render(requests, NONE);
}

//getter setter

string Library::getName()
{
    return this->name;
}

void Library::setName(string name)
{
    this->name = name;
}

Catalog *Library::getCatalog()
{
    return &this->catalog;
}

void Library::setCatalog(Catalog catalog)
{
    this->catalog = catalog;
}

list<Member> *Library::getMembers()
{
    return &this->members;
}

void Library::setMembers(list<Member> members)
{
    this->members = members;
}

list<Librarian> *Library::getLibrarians()
{
    return &this->librarians;
}

void Library::setLibrarians(list<Librarian> librarians)
{
    this->librarians = librarians;
}

list<BookRequest> *Library::getRequests()
{
    return &this->requests;
}

void Library::setRequests(list<BookRequest> requests)
{
    this->requests = requests;
}
