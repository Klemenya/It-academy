#include <iostream>
#include <sstream>

#include "myVector.h"


std::shared_ptr<std::vector<int>> CreateVector()
{
	return std::make_shared<std::vector<int>>();
}

void printVector(std::shared_ptr<std::vector<int>> pMyVector, std::string str)
{
	std::cout << "---- " << str << " ----\n";
	for (auto el : *pMyVector)
	{
		std::cout << el << " ";
	}
	std::cout << std::endl;
}

void fillVector(std::shared_ptr<std::vector<int>> pMyVector)
{
	std::cout << "Enter vector elements: ";
	std::string strData;
	getline(std::cin, strData);

	std::stringstream localString;

	localString << strData;

	int intData(0);

	while (localString >> intData)
	{
		pMyVector->push_back(intData);
	}
}