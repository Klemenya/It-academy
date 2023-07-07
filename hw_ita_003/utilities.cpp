#include "utilities.h"
#include "myVector.h"


void finMinElement(std::shared_ptr<std::vector<int>> pMyVector)
{

	if (pMyVector->size() != 0) {

		std::shared_ptr<int> minElement;
		minElement = nullptr;

		findMinEven(pMyVector, minElement);

		if (minElement == nullptr) {
			findMinOdd(pMyVector, minElement);
		}
		std::cout << "\nDesired element is: " << *minElement << std::endl;
	}
	else
	{
		std::cout << "\nError! Vector is empty!" << std::endl;
	}
}

void findMinEven(std::shared_ptr<std::vector<int>> pMyVector, std::shared_ptr<int>& ptr) {

	for (auto el : *pMyVector) {
		if (el % 2 == 0)
		{
			if (ptr == nullptr)
			{
				ptr = std::make_shared <int>();
				*ptr = el;
			}
			else
			{
				if (*ptr > el)
				{
					*ptr = el;
				}
			}
		}
	}
}

void findMinOdd(std::shared_ptr<std::vector<int>> pMyVector, std::shared_ptr<int>& ptr) {

	for (auto el : *pMyVector) {
		if (el % 2 != 0)
		{
			if (ptr == nullptr)
			{
				ptr = std::make_shared <int>();
				*ptr = el;
			}
			else
			{
				if (*ptr > el)
				{
					*ptr = el;
				}
			}
		}
	}
}

void printSumDigitsMinAndMaxNumbers(std::shared_ptr<std::vector<int>> pMyVector)
{
	size_t minEl = getMinElementID(pMyVector);
	size_t maxEl = getMaxElementID(pMyVector);

	std::cout << "Min element is: " << minEl << std::endl;
	std::cout << "Max element is: " << maxEl << std::endl;
	
	std::cout << "The sum of the numbers of the minimum and maximum numbers: " << minEl + maxEl << std::endl;
}

size_t getMinElementID(std::shared_ptr<std::vector<int>> pMyVector)
{
	size_t len = pMyVector->size();
	size_t res = 0;
	int resValue = (*pMyVector)[0];

	for (size_t idx(1); idx < len; ++idx)
	{
		if (resValue > (*pMyVector)[idx])
		{
			res = idx;
			resValue = (*pMyVector)[idx];
		}
	}
	return res;
}

size_t getMaxElementID(std::shared_ptr<std::vector<int>> pMyVector)
{
	size_t len = pMyVector->size();
	size_t res = 0;
	int resValue = (*pMyVector)[0];

	for (size_t idx(1); idx < len; ++idx)
	{
		if (resValue < (*pMyVector)[idx])
		{
			res = idx;
			resValue = (*pMyVector)[idx];
		}
	}
	return res;
}

void getSumOdd(std::shared_ptr<std::vector<int>> pMyVector)
{
	int sum(0);

	for (auto el : *pMyVector)
	{
		if (el % 2 != 0)
		{
			sum += el;
		}
	}

	std::cout << "Sum of odd is: " << sum << std::endl;
}

void getProductOfElementsWithOddIndexes(std::shared_ptr<std::vector<int>> pMyVector)
{
	size_t lenVector = pMyVector->size();
	if (lenVector < 1)
	{
		std::cout << 0;
		return;
	}

	int res = (*pMyVector)[1];

	for (int idx(3); idx < lenVector; idx += 2)
	{
		res *= (*pMyVector)[idx];
	}

	std::cout << "The product of elements with odd numbers = " << res << std::endl;
}

void swap(std::shared_ptr<std::vector<int>> pMyVector)
{
	int first;
	int second;
	printVector(pMyVector, "Vector before swap:");

	std::cout << "Enter first item number: ";
	std::cin >> first;
	std::cout << "Enter second item number: ";
	std::cin >> second;
	
	int temp = (*pMyVector)[first];
	(*pMyVector)[first] = (*pMyVector)[second];
	(*pMyVector)[second] = temp;

	printVector(pMyVector, "Vector after swap:");
}
