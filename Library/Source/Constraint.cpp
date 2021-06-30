#include "../Header/Constraint.h"
#include <algorithm>
#include <cctype>

void *Holder::library = NULL;

bool is_linux()
{

#ifdef _WIN32
    return false;
#elif _WIN64
    return false;
#elif __APPLE__ || __MACH__
    return false;
#elif __linux__
    return true;
#elif __FreeBSD__
    return false;
#elif __unix || __unix__
    return true;
#else
    return true;
#endif
}

void clear()
{
    if (!is_linux)
        system("cls");
    else
        system("clear");
}

string select_statements(list<string> stmts)
{
    int count = 1;
    for (auto it = stmts.begin(); it != stmts.end(); it++)
    {
        cout << setw(3) << to_string(count++) + "." << *it << endl;
    }
    int option;
    cout << endl;
    while (true)
    {
        cout << "Enter number: ";
        cin >> option;
        cin.ignore();
        if (option < 1 && option > stmts.size())
        {
            cout << "Invalid number, try again";
            wait();
            clear();
            continue;
        }
        break;
    }
    auto it = stmts.begin();
    for (int i = 0; i < option - 1; i++)
    {
        it++;
    }
    return *it;
}

bool select_statement(string stm1, string stm2)
{
    cout << "1. " + stm1 << endl;
    cout << "2. " + stm2 << endl
         << endl;
    cout << "Select: ";
    int option;
    cin >> option;
    cin.ignore();
    if (option > 2 || option < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_statement(stm1, stm2);
    }
    return option - 1;
}

bool is_valid_date(time_t t)
{
    return (t < time(0) || (t - time(0)) / 3600 / 24 < 7);
}

void print_option(list<string> stmts)
{
    int count = 1;
    clear();
    for (auto stm = stmts.begin(); stm != stmts.end(); stm++)
    {
        cout
            << setw(3) << left << to_string(count++) + "."
            << *stm << "." << endl;
    }

    cout << endl
         << setw(3) << left << "0."
         << "Back." << endl;

    cout << endl
         << "Enter your choice: ";
}

time_t input_time()
{
    int day, month, year;
    time_t now = time(0);
    tm ltm = *localtime(&now);
    cout << "Day : ";
    cin >> ltm.tm_mday;
    cout << "Month : ";
    cin >> month;
    ltm.tm_mon = month - 1;
    cout << "Year : ";
    cin >> year;
    ltm.tm_year = year - 1900;
    cout << "Hour: ";
    cin >> ltm.tm_hour;
    cout << "Min : ";
    cin >> ltm.tm_min;
    cout << "Seccond: ";
    cin >> ltm.tm_sec;
    cin.ignore();
    return mktime(&ltm);
}

time_t input_date()
{
    int day, month, year;
    time_t now = time(0);
    tm ltm = *localtime(&now);
    cout << "Day : ";
    cin >> ltm.tm_mday;
    cout << "Month : ";
    cin >> month;
    ltm.tm_mon = month - 1;
    cout << "Year : ";
    cin >> year;
    ltm.tm_year = year - 1900;
    ltm.tm_hour = 0;
    ltm.tm_sec = 0;
    ltm.tm_min = 0;
    cin.ignore();
    return mktime(&ltm);
}

bool is_consist(list<int> lst, int i)
{
    for (auto it = lst.begin(); it != lst.end(); it++)
    {
        if (*it == i)
            return true;
    }
    return false;
}

Address Address::inputAddress()
{
    Address temp;
    cout << "Street: ";
    getline(cin, temp.street);
    cout << "State: ";
    getline(cin, temp.city);
    cout << "State: ";
    getline(cin, temp.state);
    cout << "zip-code: ";
    getline(cin, temp.zip_code);
    cout << "Country: ";
    getline(cin, temp.country);
    return temp;
}

Address::Address() {}
Address::~Address() {}

bool operator==(const Address &rhs, const Address &lhs)
{
    return (
        (lhs.city == rhs.city) &&
        (lhs.state == rhs.state) &&
        (lhs.street == rhs.street) &&
        (lhs.zip_code == rhs.zip_code) &&
        (lhs.country == rhs.country)

    );
}

void wait()
{
    string str;
    getline(cin, str);
}

ostream &operator<<(ostream &os, const time_t &T)
{
    return (os << (char *)ctime(&T));
}

string lower_string(string in)
{
    string data = in;
    transform(data.begin(), data.end(), data.begin(),
              [](unsigned char c) { return tolower(c); });
    return data;
}

string input_str(string stm)
{
    string inp;
    cout << stm;
    getline(cin, inp);
    return inp;
}

string string_of_time(time_t t)
{
    stringstream ss;
    ss << (char *)ctime(&t);
    string temp;
    getline(ss, temp);
    return temp;
}

ostream &operator<<(ostream &os, const BookStatus &l)
{

    switch (l)
    {
    case LOANED:
        return os << "Loaned";
    case AVAILABLE:
        return os << "Available";
    }
    return os;
}

BookStatus select_book_status()
{
    cout << "Select book status" << endl
         << endl;
    for (int i = 0; i < 2; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (BookStatus)i << endl;
    }
    cout << endl
         << "Choose status: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 2 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_book_status();
    }
    return (BookStatus)(state - 1);
}

ostream &operator<<(ostream &os, const Gender &l)
{

    switch (l)
    {
    case MALE:
        return os << "Male";
    case FEMALE:
        return os << "Female";
    case OTHER:
        return os << "Other";
    }
    return os;
}

Gender select_gender()
{
    cout << "Select gender" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (Gender)i << endl;
    }
    cout << endl
         << "Choose gender: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 3 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_gender();
    }
    return (Gender)(state - 1);
}

ostream &operator<<(ostream &os, const AccountStatus &l)
{

    switch (l)
    {
    case ACTIVE:
        return os << "Active";
    case SUSPENDED:
        return os << "Suspended";
    case CLOSED:
        return os << "Closed";
    }
    return os;
}

AccountStatus select_account_status()
{
    cout << "Select account status" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (AccountStatus)i << endl;
    }
    cout << endl
         << "Choose status: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 3 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_account_status();
    }
    return (AccountStatus)(state - 1);
}

ostream &operator<<(ostream &os, const BookRequestStatus &l)
{

    switch (l)
    {
    case HOLD:
        return os << "Hold";
    case APPROVE:
        return os << "Approve";
    case DECLINE:
        return os << "Decline";
    case RETURNED:
        return os << "Returned";
    }
    return os;
}

BookRequestStatus select_book_request_status()
{
    cout << "Select book request status" << endl
         << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (BookRequestStatus)i << endl;
    }
    cout << endl
         << "Choose status: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 4 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_book_request_status();
    }
    return (BookRequestStatus)(state - 1);
}

ostream &operator<<(ostream &os, const AccountType &l)
{

    switch (l)
    {
    case LIBRARIAN:
        return os << "Librarian";
    case MEMBER:
        return os << "Member";
    }
    return os;
}

AccountType select_account_type()
{
    cout << "Select account type" << endl
         << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << setw(3) << left << to_string(i + 1) + "." << (AccountType)i << endl;
    }
    cout << endl
         << "Choose type: ";
    int state;
    cin >> state;
    cin.ignore();
    if (state > 3 || state < 1)
    {
        cout << "invalid option, try again";
        wait();
        clear();
        return select_account_type();
    }
    return (AccountType)(state - 1);
}