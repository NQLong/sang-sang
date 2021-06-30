#ifndef C30ECE8E_31B7_44A2_9BD2_7EAA6869E4A8
#define C30ECE8E_31B7_44A2_9BD2_7EAA6869E4A8
#include "Person.h"

class Client
    : public Person
{
    string tax_number;

    static list<Client> clients;

public:
    Client();
    ~Client();
    Client(string tax, string name, Address add);

    static bool add_client(Client);
    static bool add_client();
    static bool remove_client(Client);
    static bool remove_client();
    static Client *pick_client();
    static Client *get_client(string tax);
    static void client_manage_view();
    static void clients_list();
    
    static list<Client> *getClients();
    static void setClients(list<Client> clients);

    void client_view();

    void modify();

    static Client input();

    

    friend ostream &operator<<(ostream &, const Client &);
    friend bool operator==(const Client &lhs, const Client &rhs);

    string getTax_number();
    void setTax_number(string tax_number);
};
#endif /* C30ECE8E_31B7_44A2_9BD2_7EAA6869E4A8 */
