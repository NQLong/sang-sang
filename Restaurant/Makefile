all: Compiled/main.o Compiled/Constraint.o Compiled/Client.o Compiled/Dish.o Compiled/Ingridient.o Compiled/Meal.o Compiled/MealItem.o Compiled/NeededIngridient.o Compiled/Person.o Compiled/Restaurant.o Compiled/Table.o Compiled/Waiter.o Compiled/View.o
	g++ Compiled/*.o -o app


Compiled/main.o: main.cpp
	g++ -c main.cpp -o Compiled/main.o


Compiled/Client.o: Source/Client.cpp Header/Client.h
	g++ -c Source/Client.cpp -o Compiled/Client.o


Compiled/Dish.o: Source/Dish.cpp Header/Dish.h
	g++ -c Source/Dish.cpp -o Compiled/Dish.o


Compiled/Constraint.o: Source/Constraint.cpp Header/Constraint.h
	g++ -c Source/Constraint.cpp -o Compiled/Constraint.o


Compiled/Ingridient.o: Source/Ingridient.cpp Header/Ingridient.h
	g++ -c Source/Ingridient.cpp -o Compiled/Ingridient.o


Compiled/Meal.o: Source/Meal.cpp Header/Meal.h
	g++ -c Source/Meal.cpp -o Compiled/Meal.o


Compiled/MealItem.o: Source/MealItem.cpp Header/MealItem.h
	g++ -c Source/MealItem.cpp -o Compiled/MealItem.o


Compiled/NeededIngridient.o: Source/NeededIngridient.cpp Header/NeededIngridient.h
	g++ -c Source/NeededIngridient.cpp -o Compiled/NeededIngridient.o


Compiled/Person.o: Source/Person.cpp Header/Person.h
	g++ -c Source/Person.cpp -o Compiled/Person.o


Compiled/Restaurant.o: Source/Restaurant.cpp Header/Restaurant.h
	g++ -c Source/Restaurant.cpp -o Compiled/Restaurant.o


Compiled/Table.o: Source/Table.cpp Header/Table.h
	g++ -c Source/Table.cpp -o Compiled/Table.o


Compiled/View.o: Source/View.cpp Header/View.h
	g++ -c Source/View.cpp -o Compiled/View.o


Compiled/Waiter.o: Source/Waiter.cpp Header/Waiter.h
	g++ -c Source/Waiter.cpp -o Compiled/Waiter.o

clean:
	rm -rf Compiled
	mkdir Compiled
	reset

clear:
	del Compiled
	mkdir Compiled
	cls