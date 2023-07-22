#include "setup.h"

void SetUpConsole()
{
	//SetConsoleCP(1251);
	//SetConsoleOutputCP(1251);

	system("cls");

	HideCursor();

}

void HideCursor()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &info);
}