#include <iostream>
#include <Windows.h>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>


struct MenuItem
{
	size_t MenuItemNum{};
	std::shared_ptr <std::string>(MenuItemText);
	std::shared_ptr <std::string>(MenuItemFunc);
};


class Menu
{
private:
	std::shared_ptr<std::vector<MenuItem>> pMenuItem;
public:

	Menu()
	{
		std::vector<MenuItem> vStruct;

		FillMenu(vStruct);

		pMenuItem = std::make_shared<std::vector<MenuItem>>(vStruct);



	}



	void ShowMenu();
	void FillMenu(std::vector<MenuItem>&);
};




int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Menu menu;

	menu.ShowMenu();

	return 0;
}


void Menu::FillMenu(std::vector<MenuItem> &vStruct)
{
	//std::ifstream ifs("MainMenu.txt", std::ios::in);
	std::ifstream ifs("MainMenu.txt");

	if (ifs.fail())
	{
		std::cout << "Error oppening menu file !!!";
		exit(0);
	}

	while (!ifs.eof())
	{
		std::string str;
		std::getline(ifs, str);

		MenuItem temp;

		std::istringstream ss {str};

		std::string word;

		std::getline(ss, word, ';');
		temp.MenuItemNum = atoi(word.c_str());
		std::getline(ss, word, ';');
		temp.MenuItemText = std::make_shared<std::string>(word);
		std::getline(ss, word, ';');
		temp.MenuItemFunc = std::make_shared<std::string>(word);
		
		
		vStruct.push_back(temp);
		//char* word;
		//word = strtok_s(str, ";",NULL);


		//std::cout << word << "___";

	}

	//std::string first{ "first item" }, second{ "func item" };
	//MenuItem menuItem = { 1, std::make_shared<std::string>(first) , std::make_shared<std::string>(second) };

	//vStruct.push_back(menuItem);
}




void Menu::ShowMenu()
{
	for (const auto& el : *pMenuItem)
	{
		std::cout << el.MenuItemNum << ". " << *el.MenuItemText << " (" << *el.MenuItemFunc << ")" << std::endl;
	}
}