#include "../Header/View.h"

void View::start_app()
{
    clear();
    Account *acc = NULL;
    bool isLibrarin = select_statement("Member", "Librarian");
    clear();
    if (isLibrarin)
    {
        acc = ((Library *)Holder::library)->pick_librarian();
    }
    else
    {
        acc = ((Library *)Holder::library)->pick_member();
    }
    if (!acc)
    {
        cout << "Invalid email";
        wait();
        clear();
    }
    else if (input_str("Password: ") != acc->getPassword())
    {
        cout << "Incorrect password";
        wait();
        clear();
    }
    if (isLibrarin)
    {
        ((Librarian *)acc)->view();
    }
    else
    {
        ((Member *)acc)->view();
    }
    clear();
    start_app();
}