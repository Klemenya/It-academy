#include "myVector.h"
#include "utilities.h"


int main()
{
	auto pMyVector = CreateVector();
	fillVector(pMyVector);

	if (pMyVector->empty())
	{
		std::cout << "Vector is empty\nProgram is closed." << std::endl;
		return 0;
	}

	printVector(pMyVector, "Initial values");

	std::cout << "\n----- Task 1 ------" << std::endl;
	finMinElement(pMyVector);

	std::cout << "\n----- Task 2 ------" << std::endl;
	printSumDigitsMinAndMaxNumbers(pMyVector);

	std::cout << "\n----- Task 3 ------" << std::endl;
	getProductOfElementsWithOddIndexes(pMyVector);

	std::cout << "\n----- Task 4 ------" << std::endl;
	swap(pMyVector);

	return 0;
}
