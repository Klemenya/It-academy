#include <iostream>
#include <vector>


struct MenuItem
{
	size_t MenuItemNum;
	std::shared_ptr <std::string> (MenuItemText);
	std::shared_ptr <std::string> (MenuItemFunc);
};


class Menu
{
private:
	std::shared_ptr<std::vector<MenuItem>> pMenuItem;
public:

	Menu() 
	{
		std::vector<MenuItem > vStruct;
		

		MenuItem menuItem;

		menuItem.MenuItemNum = 1;
		std::string text {"first item"};
		menuItem.MenuItemText = std::make_shared<std::string>(text);
		text = "func item";
		menuItem.MenuItemFunc = std::make_shared<std::string>(text);
		vStruct.push_back(menuItem);

		pMenuItem = std::make_shared<std::vector<MenuItem>>(vStruct);
		

		
	}
	void ShowMenu();
};




int main()
{
	MenuItem testMenu;
	//testMenu.
	Menu menu;
	menu.ShowMenu();

	return 0;
}

void Menu::ShowMenu()
{
	for (auto el : *pMenuItem)
	{
		std::cout << el.MenuItemNum << "\t" << *el.MenuItemText << "- " << *el.MenuItemFunc << std::endl;
	}
}