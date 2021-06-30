#include "../Header/Member.h"
#include "../Header/Library.h"
Member::Member() {}
Member::~Member() {}
Member::Member(
    AccountStatus stat,

    string full_name,
    time_t date_of_birth,
    string phone,
    string email,
    Address address, string passwrod)
    : Account(
          stat,
          MEMBER,
          full_name,
          date_of_birth,
          phone,
          email,
          address, passwrod)
{
}

Member Member::input()
{
    Member temp;
    temp.setTyp(MEMBER);
    temp.input_account();
    return temp;
}

bool operator==(const Member &lhs, const Member &rhs)
{
    return ((Account)lhs == (Account)rhs);
}
ostream &operator<<(ostream &os, const Member &rhs)
{
    return os << (Account)rhs;
}

void Member::render(list<Member> members)
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
void Member::view()
{
    int option;
    bool loop = true;
    Search *search_engine = ((Library *)Holder::library)->getCatalog();
    while (loop)
    {
        print_option({
            "search books",
            "make request",
            "modify account info",

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            search_engine->search_view();
            break;
        case 2:
            clear();
            make_book_request();
            break;

        case 3:
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

bool Member::make_book_request()
{
    return ((Library *)Holder::library)->getCatalog()->add_book_request(this);
}