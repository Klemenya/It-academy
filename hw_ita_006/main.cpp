#include <vector>
#include <algorithm>
#include <functional>

#include "MyTVector.h"
#include "MyVectorT.h"


int main()
{

#pragma region ������� ����� 1[+]

	// [+]	���������� ������-���������, ������� ���������� ���������� ����� � �������
	//		std::vector<std::string>, ������� �������� ��������� ������������� �������

	std::vector<std::string> myVecStr;
	
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("asdfghjkl");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("zxcvbnm,sd");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");
	myVecStr.push_back("qwertyuiop");

	std::string substr {"er"};
	size_t counter{};

	auto counSubstrInVectorString = [&substr](std::string& str) { return (str.find(substr) != std::string::npos); };

	counter = std::count_if(myVecStr.begin(), myVecStr.end(), counSubstrInVectorString);

	std::cout << "In the vector " << myVecStr.size() << " lines." << std::endl;
	std::cout << "Pattern found in " << counter << " lines." << std::endl << std::endl;
#pragma endregion

#pragma region ������� ����� 2[+]

	// [+]	������� ��������� ����� ��� ������ � �������� ������
	// [+]	������� ������� 1 �-�, ������������� ������ ����������� (�������� std::transform)
	// [+]	������� ������� 1 �-�, ������������ �������� ������� (�������� std::adjacent_find)
	// [+]	��������� ��������� ���������� � �-� ������������� �����

	std::cout << " --- int ---\n";

	std::vector<int> testInt { 1, 2, 3, 4, 5, 6, 7, 8, 8};
	MyVectorT<int> myVectorInt{testInt};

	myVectorInt.ShowMyVector();
	std::cout << (myVectorInt.PairwiseComparison() ? "Pairing is present" : "No pairing") << std::endl;
	
	std::function<int(int)> myFoo;
	myFoo = [](int el) {return el * 2; };

	myVectorInt.ModifyMyVector(myFoo);
	myVectorInt.ShowMyVector();
	
	myFoo = [](int el) {return el + 1; };
	
	myVectorInt.ModifyMyVector(myFoo);
	myVectorInt.ShowMyVector();
	
	////////////////////////////////////////////////////////////////
	
	std::cout << "\n --- std::string ---\n";

	std::vector<std::string> testString{"text1", "text2", "text3", "apple", "apple"};
	MyVectorT <std::string> myVectorStr(testString);
	
	myVectorStr.ShowMyVector();
	std::cout << (myVectorStr.PairwiseComparison() ? "Pairing is present" : "No pairing") << std::endl;
	
	myVectorStr.ModifyMyVector();
	myVectorStr.ShowMyVector();
	
	std::cout << "\n-------------------------------------------------\n";

#pragma endregion

#pragma region ������� ����� 3[-]
	// ������� �����, ������� ������ � ��� ������ ��������� ������ std::function
	// ����������� ����������� ��������� � ������� ����������� (id, idx, ...)

#pragma endregion

#pragma region ������� ����� 4[-]

	// ������� ����� � ����������� �������������� ��� ���������
	// ����� �-� ������ ������� ��������� ����������, �������������� �� std::esception
	// ���������� ������ ��������� ���������� ����������,��� ����� �� ��� �� ����� ����������.


#pragma endregion




}