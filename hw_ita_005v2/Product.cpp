#include "Product.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>





Product::Product()
{
	std::cout << "new product data entry";
}

Product::Product(std::string nameProduct)
{
	m_articleNumber++;
	m_article = m_articleNumber;
	m_nameProduct = std::make_shared<std::string>(nameProduct);
}

Product::Product(std::string nameProduct, float cost, float weight, int shelfLife, size_t quantity)
{
	m_articleNumber++;
	m_article = m_articleNumber;
	m_nameProduct = std::make_shared<std::string>(nameProduct);
	m_cost = cost;
	m_weight = weight;
	m_shelfLife = shelfLife;
	m_quantity = quantity;
}

std::string& Product::getNameProduct()
{
	return *(m_nameProduct);
}

int Product::getShelfLife()
{
	return m_shelfLife;
}

void Product::showProductFullInfo()
{
	std::stringstream ss;
	ss << m_shelfLife;
	std::string shelfLife = ss.str();
	shelfLife = (shelfLife == "-1") ? "-" : shelfLife;

	std::cout << std::left << std::setw(5) << std::fixed << std::setprecision(2)
		<< m_article << ' '
		<< std::setw(15) << *m_nameProduct << " "
		<< std::right
		<< std::setw(8) << m_cost << ' '
		<< std::setw(6) << m_weight << ' '
		<< std::setw(10) << shelfLife << ' '
		<< std::setw(8) << m_quantity << std::endl;
}

void Product::decShelfLife()
{
	--m_shelfLife;
}
