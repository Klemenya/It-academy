#include <vector>
#include <algorithm>
#include <functional>

#include "MyTVector.h"
//#include "MyVectorT.h"


int main()
{

#pragma region Задание номер 1[+]

	// [+]	Определить лямбда-выражение, которое возвращает количество строк в векторе
	//		std::vector<std::string>, которые содержат введенный пользователем паттерн

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

#pragma region Задание номер 2[+]

	// [+]	Создать шаблонный класс для работы с вектором данных
	// [+]	Создать минимум 1 ф-ю, анализирующую вектор поэлементно (например std::transform)
	// [-]	Создать минимум 1 ф-ю, сравнивающую элементы попарно (например std::adjacent_find)
	// [+]	Параметры изменения передаются в ф-ю пользователем класса
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

#pragma region Задание номер 3[-]
	// Создать класс, который хранит и при вызове применяет список std::function
	// Реализовать возможность добавлять и удалять экзекьютеры (id, idx, ...)

#pragma endregion

#pragma region Задание номер 4[-]

	// Создать класс с несколькими нетривиальными мат функциями
	// Вызов ф-й должен брасать кастомное исключение, унаследованное от std::esception
	// Исключение должно позволять однозначно определить,что пошло не так во время исполнения.


#pragma endregion




}