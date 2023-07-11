#include "initial.h"

#include <fstream>

const std::string DETAILS = "details.txt";

void Initial()
{
	SetupConsole();
	CheckFile(DETAILS);
	

}

void SetupConsole()
{
	SetConsoleTitle(L"--- Заголовок консольного окна ---");
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//std::cout << "Привет. Введи русские символы" << std::endl;
	//std::string str;
	//std::cin >> str;
	//std::cout << str << std::endl;
	// ANSI - кодировка для текстового файла !!!
}

void CheckFile(const std::string& PATH)
{
	std::fstream iof(PATH, std::ios::in | std::ios::out | std::ios::app);

	if (iof.fail())
	{
		std::cout << "Error openenig " << PATH << " file!" << std::endl;
		exit(0);
	}

	//else
	//{
	//	std::cout << "The file " << PATH << " is opened correctly!" << std::endl;
	//}

	iof.close();
}



std::shared_ptr<std::string> Organization::GetOrganizationName()
{
	return Organization::organizationName;
}


