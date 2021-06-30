#include "../Header/Client.h"
list<Client> Client::clients;
Client::Client() {}
Client::~Client() {}
Client::Client(string tax, string name, Address address)
    : Person(name, address)
{
    this->tax_number = tax;
}

bool Client::add_client(Client c)
{
    if (get_client(c.tax_number))
        return false;
    clients.push_back(c);
    return true;
}

bool Client::add_client()
{
    cout << "New client: \n";
    Client client = input();
    return add_client(client);
}

Client *Client::pick_client()
{
    string pattern;
    cout << "Enter client tax_num: ";
    getline(cin, pattern);
    return get_client(pattern);
}
Client *Client::get_client(string tax_n)
{
    for (auto it = clients.begin(); it != clients.end(); it++)
    {
        if (it->getTax_number() == tax_n)
            return &*it;
    }
    return NULL;
}

void Client::client_manage_view()
{
    int option;
    bool loop = true;
    Client *ptr;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add client." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove client." << endl
            << setw(3) << left << to_string(count++) + "."
            << "select client." << endl
            << setw(3) << left << to_string(count++) + "."
            << "clients list." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            add_client();
            wait();
            break;
        case 2:
            clear();
            remove_client();
            wait();
            break;
        case 3:
            clear();
            ptr = pick_client();
            if (!ptr)
            {
                cout << "Invalid tax number";
                wait();
                break;
            }
            ptr->client_view();
            // wait();
            break;

        case 4:
            clear();
            clients_list();
            wait();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}

void Client::client_view()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "clinet info." << endl
            << setw(3) << left << to_string(count++) + "."
            << "modify client info." << endl

            << endl
            << setw(3) << left << "0."
            << "Back." << endl;

        cout << endl
             << "Enter your choice: ";
        cin >> option;
        cin.ignore();
        switch (option)
        {
        case 1:
            clear();
            cout << *this;
            wait();
            break;
        case 2:
            clear();
            this->modify_person();
            break;

        default:
            loop = false;
            break;
        }
    }

    return;
}

bool Client::remove_client(Client c)
{
    clients.remove(c);
    return true;
}

bool Client::remove_client()
{
    Client *ptr = pick_client();
    if (!ptr)
    {
        cout << "Invalid tax_number";

        return false;
    }
    return remove_client(*ptr);
}

void Client::modify()
{
}

void Client::clients_list()
{
    cout
        << setw(48) << setfill('*') << "" << endl
        << setfill(' ')
        << setw(15) << left << "| tax number " << '|'
        << setw(30) << left << "name"
        // << setw(30) << right
        << "|"
        << endl
        << setw(48) << setfill('*') << "" << endl
        << setfill(' ');

    for (auto it = clients.begin(); it != clients.end(); it++)
    {
        if (!&*it)
            continue;
        cout
            << setw(15) << left << "|" + it->getTax_number() << '|'
            << setw(30) << left << it->getName() << '|' << endl
            << setw(48) << setfill('*') << "" << endl
            << setfill(' ');
    }
}

Client Client::input()
{
    Client temp;
    cout << "tax_number";
    getline(cin, temp.tax_number);
    temp.input_person();
    return temp;
}

ostream &operator<<(ostream &os, const Client &c)
{
    return os << Person(c) << endl
              << "Tax number: " << c.tax_number;
}

bool operator==(const Client &lhs, const Client &rhs)
{
    return (
        (lhs.tax_number == rhs.tax_number) &&
        (Person(lhs) == Person(rhs)));
}

string Client::getTax_number()
{
    return tax_number;
}

void Client::setTax_number(string tax_number)
{
    this->tax_number = tax_number;
}

list<Client> *Client::getClients()
{
    return &clients;
}

void Client::setClients(list<Client> _clients)
{
    clients = _clients;
}
