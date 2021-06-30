#include "../Header/Author.h"

list<Author> Author::authors;

Author::Author() {}
Author::~Author() {}
Author::Author(string name, Gender g)
{
    this->name = name;
    this->gender = g;
}

bool Author::add_author(Author i)
{
    if (get_author(i.getName()))
    {
        return false;
    }
    authors.push_back(i);
    return true;
}

bool Author::add_author()
{
    cout << "add new author: " << endl;
    Author i = Author::input();
    return add_author(i);
}

bool Author::remove_author()
{
    Author *ptr = pick_author();
    if (!ptr)
    {
        cout << "Invalid name";
        return false;
    }
    cout << "success";
    return remove_author(*ptr);
}
bool Author::remove_author(Author i)
{
    authors.remove(i);
    return true;
}
Author *Author::get_author(string name)
{
    for (auto it = authors.begin(); it != authors.end(); it++)
    {
        if (it->getName() == name)
            return &*it;
    }
    return NULL;
}
Author *Author::pick_author()
{
    return get_author(input_str("Enter author name: "));
}
bool Author::select_author()
{
    Author *ptr = pick_author();
    if (!ptr)
    {
        cout << "Invalid name";
        wait();
        clear();
        return false;
    }
    if (select_statement("View author", "modify author"))
    {
        ptr->modify();
    }
    else
    {
        clear();
        cout << *ptr;
        wait();
    }
    return true;
}

void Author::authors_list()
{
    cout
        << setw(42) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(30) << left << "|            Name " << '|'
        << setw(10) << left << "  Gender  " << '|'

        << endl
        << setw(42) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = authors.begin(); it != authors.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(30) << left << "|" + it->getName() << '|'
            << setw(10) << left << (Gender)(it->getGender()) << '|'
            << endl
            << setw(42) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

Author Author::input()
{
    Author temp;
    temp.name = input_str("Author name: ");
    clear();
    temp.gender = select_gender();
    return temp;
}

void Author::modify()
{
    cout << "modify gender:" << endl;
    this->gender = select_gender();
}

bool operator==(const Author &lhs, const Author &rhs)
{
    return (
        (lhs.name == rhs.name) &&
        (lhs.gender == rhs.gender));
}

void Author::manage_author()
{
    int option;
    bool loop = true;
    while (loop)
    {
        print_option({"add author",
                      "remove author",
                      "select author",
                      "authors list"

        });

        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            add_author();
            wait();
            break;
        case 2:
            clear();
            remove_author();
            wait();
            break;

        case 3:
            clear();
            select_author();
            break;
        case 4:
            clear();
            authors_list();
            wait();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}
ostream &operator<<(ostream &os, const Author &author)
{
    return os << "Author name: " << author.name << ", gender: " << (Gender)author.gender;
}

//getter and setter
string Author::getName()
{
    return this->name;
}

void Author::setName(string name)
{
    this->name = name;
}

Gender Author::getGender()
{
    return this->gender;
}

void Author::setGender(Gender gender)
{
    this->gender = gender;
}

list<Author> *Author::getAuthors()
{
    return &authors;
}

void Author::setAuthors(list<Author> _authors)
{
    authors = _authors;
}
