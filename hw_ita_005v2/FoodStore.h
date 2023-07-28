#pragma once

#include <memory>
#include <vector>
#include <string>

#include "Product.h"






class FoodStore
{
private:
	std::shared_ptr<std::vector<Product>> m_products;
public:
	FoodStore() 
	{
		m_products = std::make_shared<std::vector<Product>> ();
	}

	void addProduct(Product);
	void showAvailability();
	void moveToNextDay();
	void searchExpiredProduct ();


	void writeoffExpiredProduct();


};

