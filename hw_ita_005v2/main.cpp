#include "Product.h"
#include "FoodStore.h"

#include <iostream>

int main()
{

	FoodStore store;

	Product apple1("apple red", 10.10f, 1, -1, 10);
	Product apple2("apple green", 12.12f, 1, -1, 15);
	Product apple3("apple white", 11.11f, 1, 5, 10);
	Product tomato("tomato", 5.05f, 1, 2, 15);
	Product juice("tomato juice", 4, 0.87f, 365, 5);

	store.addProduct(apple1);
	store.addProduct(apple2);
	store.addProduct(apple3);
	store.addProduct(tomato);
	store.addProduct(juice);

	store.showAvailability();

	store.moveToNextDay();
	store.showAvailability();

	store.moveToNextDay();
	store.showAvailability();
	store.searchExpiredProduct();
	store.writeoffExpiredProduct();


	store.moveToNextDay();
	store.showAvailability();

	store.searchExpiredProduct();



	//std::cout << apple.getNameProduct();

	return 0;
}