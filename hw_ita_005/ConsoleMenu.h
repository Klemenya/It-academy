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
	std::shared_ptr<std::vector<MenuItem>> pMenu;
	size_t m_widthMenu{};
	size_t m_heightMenu{};


public:

	ConsoleMenu();

	size_t getWidthMenu() { return m_widthMenu; }
	size_t getHeightMenu() { return m_heightMenu; }




	//friend void showBorder( (m_widthMenu *2+2), (m_heightMenu, m_heightMenu + 5) );
	friend void showBorder(const size_t, const size_t);

	//void ShowMenu(const size_t, const size_t);
	void ShowMenu();
	void FillMenu(std::vector<MenuItem>&);
};


