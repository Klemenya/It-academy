#include "menu.h"

#include <conio.h>


void Menu(Organization &myFirm)
{
	PrintMenu();
	int menuItem = GetPressedKey();
	while (menuItem )
	{
		switch (menuItem)
		{
		case 1:
		{
			std::cout << "������ 1 ����� ����" << std::endl;
			break;
		}
		case 2:
		{
			std::cout << "������ 2 ����� ����" << std::endl;
			break;
		}
		case 3:
		{
			std::cout << "������ 3 ����� ����" << std::endl;
			break;
		}
		case 4:
		{
			std::cout << "������ 4 ����� ����" << std::endl;
			break;
		}
		case 5:
		{
			std::cout << "������ 5 ����� ����" << std::endl;
			break;
		}
		case 6:
		{
			std::cout << *myFirm.GetOrganizationName() << std::endl;
			break;
		}
		}
		menuItem = GetPressedKey();
	}
	
}

int GetPressedKey()
{
	int key = _getch();
	return key-48;
}

void PrintMenu()
{
	std::cout << "1. ���������" << std::endl;
	std::cout << "2. ���������" << std::endl;
	std::cout << "3. ���������" << std::endl;
	std::cout << "4. ���������" << std::endl;
	std::cout << "5. ���������" << std::endl;
	std::cout << "6. H����������� �����������" << std::endl;
	std::cout << "0. �����"     << std::endl;
}




//esq = 27
// up   224 + 72
//down  224 + 80
//left  224 + 75
//right 224 + 77


