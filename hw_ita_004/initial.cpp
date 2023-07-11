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
	SetConsoleTitle(L"--- ��������� ����������� ���� ---");
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	//std::cout << "������. ����� ������� �������" << std::endl;
	//std::string str;
	//std::cin >> str;
	//std::cout << str << std::endl;
	// ANSI - ��������� ��� ���������� ����� !!!
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


