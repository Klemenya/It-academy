#include <vector>
#include <algorithm>
#include <functional>

#include "MyTVector.h"
//#include "MyVectorT.h"


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
	// [-]	������� ������� 1 �-�, ������������ �������� ������� (�������� std::adjacent_find)
	// [+]	��������� ��������� ���������� � �-� ������������� ������
	//


	/*
	std::vector<int> testInt { 1, 2, 3, 4, 5, 6, 7, 8, 8};
	MyVectorT<int> myVectorInt{testInt};

	myVectorInt.ShowMyVector();
	myVectorInt.PairwiseComparison();
	std::cout << (myVectorInt.PairwiseComparison() ? "Pairing is present" : "No pairing") << std::endl;
	
	std::function<int(int)> myFoo;
	myFoo = [](int el) {return el * 2; };

	myVectorInt.ModifyMyVector(myFoo);
	myVectorInt.ShowMyVector();
	
	myFoo = [](int el) {return el + 1; };
	myVectorInt.ModifyMyVector(myFoo);
	myVectorInt.ShowMyVector();
	////////////////////////////////////////////////////////////////
	std::vector<std::string> testString{"text1", "text2", "text3", "apple", "apple2"};
	MyVectorT <std::string> myVectorStr(testString);
	myVectorStr.ShowMyVector();

	//myVectorStr.ModifyMyVector();
	//myVectorStr.ShowMyVector();
	//std::cout << (myTVector2.PairwiseComparison() ? "Pairing is present" : "No pairing") << std::endl;
	*/


	std::vector<int> testInt { 1, 2, 3, 4, 5, 6, 7, 8, 8};
	MyTVector <std::vector<int>> myTVector1(testInt);

	
	myTVector1.ShowMyVector();

	std::cout << (myTVector1.PairwiseComparison() ? "Pairing is present" : "No pairing") << std::endl;

	std::function<int(int)> myFoo;
	myFoo = [](int el) {return el * 2; };
	
	myTVector1.ModifyMyVector(myFoo);
	myTVector1.ShowMyVector();

	myFoo = [](int el) {return el + 1; };
	
	myTVector1.ModifyMyVector(myFoo);
	myTVector1.ShowMyVector();

	std::vector<std::string> testString{"text1", "text2", "text3", "apple", "apple2"};
	MyTVector <std::vector<std::string>> myTVector2(testString);
	myTVector2.ShowMyVector();
	myTVector2.ModifyMyVector();
	myTVector2.ShowMyVector();
	std::cout << (myTVector2.PairwiseComparison() ? "Pairing is present" : "No pairing") << std::endl;
	

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