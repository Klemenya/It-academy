#include "ConsoleMenu.h"




void ConsoleMenu::FillMenu(std::vector<MenuItem>& vStruct)
{
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

		std::istringstream ss{ str };
		std::string word;
		
		std::getline(ss, word, ';');
		temp.menuItemNum = atoi(word.c_str());

		std::getline(ss, word, ';');
		temp.menuItemText = std::make_shared<std::string>(word);

		std::getline(ss, word, ';');
		temp.menuItemFunc = std::make_shared<std::string>(word);
		
		vStruct.push_back(temp);
		
		
		
		
		
		//char* word;
		//word = strtok_s(str, ";",NULL);


		//std::cout << word << "___";

	}

	//std::string first{ "first item" }, second{ "func item" };
	//MenuItem menuItem = { 1, std::make_shared<std::string>(first) , std::make_shared<std::string>(second) };

	//vStruct.push_back(menuItem);
}




void ConsoleMenu::ShowMenu()
{
	for (const auto& el : menu)
	{
		std::cout << el.menuItemNum << ". " << el.menuItemText << " (" << el.menuItemFunc << ")" << std::endl;
	}
}