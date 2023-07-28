#include "FoodStore.h"
#include <iostream>
#include <iomanip>

void FoodStore::addProduct(Product product)
{
	m_products->push_back(product);
}

void FoodStore::showAvailability()
{
	std::cout << std::endl;
	std::cout << std::left << std::setw(5) << "Art" << ' '
		<< std::setw(15) << "Product" << " "
		<< std::setw(8) << "    cost" << ' '
		<< std::setw(6) << "weight" << ' '
		<< std::setw(10) << "shelf life" << ' '
		<< std::setw(8) << "quantity " << std::endl;

	for (auto& product : *m_products)
	{
		product.showProductFullInfo();

	}
}

void FoodStore::moveToNextDay()
{
	for (auto& product : *m_products)
	{
		if (product.getShelfLife() > 0)
		{
			product.decShelfLife();
		}
	}
}

void FoodStore::searchExpiredProduct()
{
	bool isFound = false;
	auto products = *m_products;
	for (auto& product : products)
	{
		if (product.getShelfLife() == 0)
		{
			isFound = true;
			std::cout << "Attention!!! Expired product!: " << product.getNameProduct() << std::endl;
		}
	}
	if (!isFound)
	{
		std::cout << "No expired products" << std::endl;
	}
}

void FoodStore::writeoffExpiredProduct()
{
	size_t quantity = m_products->size();
	auto& myStore = *m_products;
	for (size_t idx(0); idx < quantity; idx++) 
	{
		if ( myStore[idx].getShelfLife() == 0)
		{
			std::cout << "Write-off of expired product: " << myStore[idx].getNameProduct() << std::endl;
			myStore.erase(myStore.begin()+idx);
			quantity--,idx--;
		}
	}
}
