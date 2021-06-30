#include "../Header/View.h"
#include "../Header/Meal.h"

void View::start_app()
{
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "manage ingridient." << endl
            << setw(3) << left << to_string(count++) + "."
            << "manage dish." << endl
            << setw(3) << left << to_string(count++) + "."
            << "manage table." << endl
            << setw(3) << left << to_string(count++) + "."
            << "manage meal." << endl
            << setw(3) << left << to_string(count++) + "."
            << "manage waiter." << endl
            << setw(3) << left << to_string(count++) + "."
            << "manage client." << endl

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
            ingridient_manage_view();
            break;
        case 2:
            clear();
            dish_manage_view();
            break;
        case 3:
            clear();
            table_manage_view();
            break;
        case 4:
            clear();
            meal_manage_view();
            break;
        case 5:
            clear();
            waiter_manage_view();
            break;
        case 6:
            clear();
            client_manage_view();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
void View::client_manage_view()
{
    Client::client_manage_view();
}
void View::ingridient_manage_view()
{
    IngridientManage *ptr = (Restaurant *)Holder::restaurant;
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add ingridient." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove ingrdient." << endl
            << setw(3) << left << to_string(count++) + "."
            << "select ingrdient." << endl
            << setw(3) << left << to_string(count++) + "."
            << "ingrdients list." << endl

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
            ptr->add_ingiridient();
            break;
        case 2:
            clear();
            ptr->remove_ingridient();
            wait();
            break;
        case 3:
            clear();
            ptr->select_ingridient();
            break;
        case 4:
            clear();
            ptr->ingridient_list();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
void View::dish_manage_view()
{
    DishManage *ptr = (Restaurant *)Holder::restaurant;
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add dish." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove dish." << endl
            << setw(3) << left << to_string(count++) + "."
            << "select dish." << endl
            << setw(3) << left << to_string(count++) + "."
            << "dishes list." << endl

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
            ptr->add_dish();
            break;
        case 2:
            clear();
            ptr->remove_dish();
            wait();
            break;
        case 3:
            clear();
            ptr->select_dish();

            break;
        case 4:
            clear();
            ptr->dish_list();
            wait();

            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
void View::table_manage_view()
{
    TableManage *ptr = (Restaurant *)Holder::restaurant;
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add table." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove table." << endl
            << setw(3) << left << to_string(count++) + "."
            << "select table." << endl
            << setw(3) << left << to_string(count++) + "."
            << "table list." << endl

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
            ptr->add_table();
            break;
        case 2:
            clear();
            ptr->remove_table();
            wait();
            break;
        case 3:
            clear();
            ptr->select_table();

            break;
        case 4:
            clear();
            ptr->table_list();
            wait();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
void View::waiter_manage_view()
{
    WaiterManage *ptr = (Restaurant *)Holder::restaurant;
    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add waiter." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove waiter." << endl
            << setw(3) << left << to_string(count++) + "."
            << "select waiter." << endl
            << setw(3) << left << to_string(count++) + "."
            << "waiters list." << endl

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
            ptr->add_waiter();
            break;
        case 2:
            clear();
            ptr->remove_waiter();
            wait();
            break;
        case 3:
            clear();
            ptr->select_waiter();
            break;
        case 4:
            clear();
            ptr->waiter_list();
            wait();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}
void View::meal_manage_view()
{

    int option;
    bool loop = true;
    while (loop)
    {
        int count = 1;
        clear();

        cout
            << setw(3) << left << to_string(count++) + "."
            << "add meal." << endl
            << setw(3) << left << to_string(count++) + "."
            << "remove meal." << endl
            << setw(3) << left << to_string(count++) + "."
            << "select meal." << endl
            << setw(3) << left << to_string(count++) + "."
            << "meals list." << endl

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
            Meal::add_meal();
            wait();
            break;
        case 2:
            clear();
            Meal::remove_meal();
            wait();
            break;
        case 3:
            clear();
            Meal::select_meal();
            wait();
            break;
        case 4:
            clear();
            Meal::meals_list();
            wait();
            break;
        default:
            loop = false;
            break;
        }
    }

    return;
}