#include "../Header/Librarian.h"
#include "../Header/BookManage.h"
#include "../Header/Library.h"
Librarian::Librarian() {}
Librarian::~Librarian() {}
Librarian::Librarian(
    AccountStatus stat,

    string full_name,
    time_t date_of_birth,
    string phone,
    string email,
    Address address, string password)
    : Account(
          stat,
          LIBRARIAN,
          full_name,
          date_of_birth,
          phone,
          email,
          address,
          password)
{
}

Librarian Librarian::input()
{
    Librarian temp;
    temp.setTyp(LIBRARIAN);
    temp.input_account();
    return temp;
}

void Librarian::render(list<Librarian> members)
{
    cout
        << setw(90) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(10) << left << "| id " << '|'
        << setw(12) << left << " status " << '|'
        << setw(12) << left << " type " << '|'
        << setw(20) << left << "    email " << '|'
        << setw(30) << left << "        full name " << '|'

        << endl
        << setw(90) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = members.begin(); it != members.end(); it++)
    {
        if (!&*it)
            continue;
        it->render_account();
    }
}

void Librarian::view()
{
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({
            "manage books",
            "manage book requests",
            "manage members",
            "manage librarians",
            "manage authors",
            "modify account info",

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            books_manage();
            break;
        case 2:
            clear();
            request_manage();
            break;

        case 3:
            clear();
            member_manage();
            break;
        case 4:
            clear();
            librarian_manage();
            break;
        case 5:
            clear();
            Author::manage_author();
            break;
        
        case 6:
            clear();
            modify();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Librarian::librarian_manage()
{
    LibrarianManage *manager = ((Library *)Holder::library);
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add librarian",
                      "remove librarian",
                      "select librarian",
                      "librarians list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            if (!manager->add_librarian())
                wait();
            break;
        case 2:
            clear();
            manager->remove_librarian();
            wait();
            break;

        case 3:
            clear();
            manager->select_librarian();
            break;
        case 4:
            clear();
            manager->librarians_list();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

void Librarian::member_manage()
{
    MemberManage *manager = ((Library *)Holder::library);
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add member",
                      "remove member",
                      "select member",
                      "members list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            if (!manager->add_member())
                wait();
            break;
        case 2:
            clear();
            manager->remove_member();
            wait();
            break;

        case 3:
            clear();
            manager->select_member();
            break;
        case 4:
            clear();
            manager->members_list();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}
void Librarian::books_manage()
{
    BookManage *manager = ((Library *)Holder::library)->getCatalog();
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add book",
                      "remove book",
                      "select book",
                      "books list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            if (!manager->add_book())
                wait();
            break;
        case 2:
            clear();
            manager->remove_book();
            wait();
            break;

        case 3:
            clear();
            manager->select_book();
            break;
        case 4:
            clear();
            manager->books_list(*((Library *)Holder::library)->getCatalog()->getBooks());
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

void Librarian::request_manage()
{
    RequestManage *manager = ((Library *)Holder::library);
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add request",
                      "remove request",
                      "select request",
                      "requests list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            if (manager->add_request())
                cout << "Success";
            wait();
            break;
        case 2:
            clear();
            manager->remove_request();
            wait();
            break;

        case 3:
            clear();
            manager->select_request();
            break;
        case 4:
            clear();
            manager->requests_list();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}