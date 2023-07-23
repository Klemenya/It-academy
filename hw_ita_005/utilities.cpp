#include "utilities.h"
#include "setup.h"

#include <iostream>
#include <iomanip>

//#include <string>

void SetCursorPosition(int x, int y)
{
	COORD coord{ x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void showBorder(const size_t width, const size_t height)
{
	//std::cout << width << "\n" << height;



	int x{}, y{};
	size_t widthBorder = consoleWidth;
	size_t heightBorder = consoleHeight;


	bool isSizeDefault = (!width && !height);
	if (!isSizeDefault)
	{
		heightBorder = (height * 2 + 4);
		widthBorder = (width + 7);
		
		y = (consoleHeight - heightBorder) / 2;
		x = (consoleWidth - widthBorder) / 2;
	}

	SetCursorPosition(x, y++);
	std::cout << ulcSymbol << std::right << std::setfill(hbSymbol) << std::setw(widthBorder-1) << urcSymbol << std::endl;

	for (size_t idx(0); idx < (heightBorder); idx++)
	{
		SetCursorPosition(x, y++);
		std::cout << vbSymbol << std::right << std::setfill(' ') << std::setw(widthBorder-1) << vbSymbol << std::endl;
	}

	SetCursorPosition(x, y++);
	std::cout << llcSymbol << std::right << std::setfill(hbSymbol) << std::setw(widthBorder-1) << lrcSymbol;

}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}