#include "ConsoleMenu.h"
#include "setup.h"
#include "utilities.h"
#include <Windows.h>
#include <conio.h>


ConsoleMenu::ConsoleMenu()
{
	pMenu = std::make_shared<std::vector<MenuItem>>();

	FillMenu(*pMenu);

	size_t lenStr = 0;
	for (const auto& el : *pMenu)
	{
		size_t lenMenuItem = (*el.menuItemText).length();
		if (lenStr < lenMenuItem) lenStr = lenMenuItem;
	}

	m_heightMenu = (*pMenu).size();
	m_widthMenu = lenStr;
}

void ConsoleMenu::FillMenu(std::vector<MenuItem>& vStruct)
{
	std::ifstream ifs("MainMenu.txt");

	if (ifs.fail())
	{
		SetColor(Red, Blue);
		showBorder(30, 1);
		SetCursorPosition(25, 11);

		std::cout << "Error oppening menu file !!!";

		char c = _getch();
		SetColor(White, Black);
		SetCursorPosition(0, 25);
		system("cls");
		exit(0);
	}

	while (!ifs.eof())
	{
		std::string str;
		std::getline(ifs, str);
		std::istringstream ss{ str };
		std::string word;

		MenuItem temp;

		std::getline(ss, word, ';');
		temp.menuItemNum = atoi(word.c_str());

		std::getline(ss, word, ';');
		temp.menuItemText = std::make_shared<std::string>(word);

		std::getline(ss, word, ';');
		temp.menuItemFunc = std::make_shared<std::string>(word);
		
		vStruct.push_back(temp);
	}
}

void ConsoleMenu::ShowMenu()
{
	auto menu = *pMenu;
	
	showBorder(m_widthMenu,m_heightMenu);

	SetCursorPosition(25, 11);


}