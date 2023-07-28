#pragma once

#include <memory>
//#include <vector>
#include <string>

class Product
{
private:
	static inline size_t m_articleNumber{};

	size_t m_article{};
	std::shared_ptr<std::string> m_nameProduct{};
	float m_cost{};
	float m_weight{};
	int m_shelfLife{};
	size_t m_quantity{};


public:
	Product();
	Product(std::string nameProduct);
	Product(std::string nameProduct, float cost, float weight, int shelfLife, size_t quantity);

	std::string& getNameProduct();
	int getShelfLife();
	void showProductFullInfo();
	void decShelfLife();

};

