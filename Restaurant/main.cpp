#include "Header/Constraint.h"
#include "Header/View.h"
#include "Header/Meal.h"
#include "Header/Ingridient.h"

Restaurant init_data();
int main()
{
    Restaurant restaurant = init_data();
    Holder::restaurant = &restaurant;
    View view;
    view.start_app();
}

Restaurant init_data()
{
    Address test("Bleeker", "New York", "New York", "123456", "USA");

    Restaurant restaurant("Hell",
                          {
                              Ingridient("nam", "kg", 1.5),
                              Ingridient("gao", "kg", 2.5),
                              Ingridient("hanh la", "cay", 10),
                              Ingridient("thit heo", "kg", 10, false),
                              Ingridient("thit bo", "kg", 15),

                          },
                          {
                              Dish(
                                  "chao nam",
                                  {
                                      NeededIngridient("nam", 0.05),
                                      NeededIngridient("gao", 0.1),
                                  },
                                  15

                                  ),

                              Dish(
                                  "heo quay",
                                  {
                                      NeededIngridient("thit heo", 0.1),
                                  },
                                  30

                                  ),

                              Dish(
                                  "bo nuong",
                                  {
                                      NeededIngridient("thit bo", 0.2),
                                  },
                                  50

                                  ),

                          },
                          {
                              Table(10),
                              Table(11),
                              Table(12),
                              Table(13),
                          },
                          {
                              Waiter("01234567", "Long 1", test),
                              Waiter("01234568", "Long 2", test),
                              Waiter("01234569", "Long 3", test),
                              Waiter("01234570", "Long 4", test),
                          }

    );

    Client::setClients({
        Client("1234xyz", "Ben 1", test),
        Client("1235xyz", "Ben 2", test),
        Client("1236xyz", "Ben 3", test),
        Client("1237xyz", "Ben 4", test),
    });
    Holder::restaurant = &restaurant;
    Meal::setMeals(
        {

            Meal(
                1, //table id
                {
                    MealItem("chao nam", 4),
                    MealItem("heo quay", 5),
                    MealItem("bo nuong", 2),
                },                       // meal item
                1,                       //waiter id
                "1234xyz",               //client_tax_number
                time(0) - SECOND_IN_DAY, //start
                2                        //duration
                ),

        }

    );
    return restaurant;
}