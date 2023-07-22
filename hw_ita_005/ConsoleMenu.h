#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>


struct MenuItem
{
	size_t menuItemNum{};
	std::shared_ptr <std::string>(menuItemText);
	std::shared_ptr <std::string>(menuItemFunc);
};




class ConsoleMenu
{
private:
	std::vector<MenuItem> menu;

public:

	ConsoleMenu()
	{
		//std::vector<MenuItem> menuItem;

		MenuItem a1;
		FillMenu(menu);

		//menuItem = std::make_shared<std::vector<MenuItem>>(vMenuItem);



	}



	void ShowMenu();
	void FillMenu(std::vector<MenuItem>&);
};


