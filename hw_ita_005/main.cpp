#include "setup.h"
#include "utilities.h"
#include "ConsoleMenu.h"

#include <conio.h>

int main()
{

	SetUpConsole();

	ConsoleMenu menu;
	menu.ShowMenu();

	_getch();

	
	//std::cout << std::endl;
	//for (int i(0); i < 80; i++)
	//{
	//	if (i % 10 == 0) std::cout << i / 10;
	//	else std::cout << ' ';
	//}
	//std::cout << std::endl;
	//for (int i(0); i < 80; i++)
	//{
	//	if (i > 9) std::cout << i % 10;
	//	else std::cout << i;
	//}




	return 0;
}