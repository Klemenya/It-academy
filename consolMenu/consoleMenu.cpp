#include <stdio.h> // для printf() и scanf()
#include <conio.h> // для _getch()
#include <windows.h>
#include <iostream>
#include <iomanip>

//#include ""



int m_pos = 0;          // позиция меню
int max_pos = 3;        // максимальная позиция меню
char s1[101];

char* ru(const char* s) { AnsiToOem(s, s1);   return s1; } // вывод русским языком

HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);



void add()
{
    return;
}// объявляем нужные

void dif()
{
    return;
}// нам функции

enum ConsoleColor
{
    Black = 0,
    Blue = 1,
    Green = 2,
    Cyan = 3,
    Red = 4,
    Magenta = 5,
    Brown = 6,
    LightGray = 7,
    DarkGray = 8,
    LightBlue = 9,
    LightGreen = 10,
    LightCyan = 11,
    LightRed = 12,
    LightMagenta = 13,
    Yellow = 14,
    White = 15
};



void hidecursor()
{
    //HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hStdOut, &info);
}


void SetColor(int text, int background) // устанавливаем цвет
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int x, int y) // позиция курсора
{
    SHORT X = static_cast<SHORT>(x);
    SHORT Y = static_cast<SHORT>(y);

    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void go(int x) // Если нажали Enter
{
    if (x == 0) add();
    if (x == 1) dif();
    
    
    //std::cout << "\n   Нажмите любую\n      клавишу";
    printf(ru("\n   Нажмите любую\n      клавишу"));
    
    
    SetColor(0, 0);
    //GotoXY(35, 24);
    exit(0);
}

void choice();






void showBorder()
{
    std::cout << '\xc9' << std::right << std::setfill('\xcd') << std::setw(79 - 1) << '\xbb' << std::endl;

    for (size_t idx(0); idx < 23; idx++)
    {
        std::cout << '\xba' << std::right << std::setfill(' ') << std::setw(79 - 1) << '\xba' << std::endl;
    }

    std::cout << '\xc8' << std::right << std::setfill('\xcd') << std::setw(79 - 1) << '\xbc' ;
}





void menu()
{

//    system("cls"); // очистить экран


    if (m_pos == 0)
    {
        SetColor(Yellow, Blue); 
        GotoXY(10, 5);
        printf(ru(" \x1a Прибавить матрицы")); 
        
        SetColor(White, Black);
        GotoXY(10, 6);
        printf(ru("   Отнять матрицы"));
        GotoXY(10, 7);
        printf(ru("   Выход"));
        choice();
    }
    if (m_pos == 1)
    {
        GotoXY(10,5);
        printf(ru("   Прибавить матрицы"));

        SetColor(Yellow, Blue);
        GotoXY(10, 6);
        printf(ru(" \x1a Отнять матрицы")); 
        
        SetColor(White, Black);
        GotoXY(10, 7);
        printf(ru("   Выход"));
        choice();
    }
    if (m_pos == 2)
    {
        GotoXY(10, 5);
        printf(ru("   Прибавить матрицы"));
        
        GotoXY(10, 6);
        printf(ru("   Отнять матрицы"));

        SetColor(Yellow, Blue);
        GotoXY(10, 7);
        printf(ru(" \x1a Выход\n")); 
        
        SetColor(15, 0);
        choice();
    }
}

void choice() // функция выбора
{
l:
    int ch = _getch(); // считываем значение нажатой клавиши
    if (ch == 224) // 224 - это стрелочки
    {
        switch (ch)
        {
        case 80: // вниз
            if (m_pos + 1 < max_pos) ++m_pos;
            menu();
            break;
        case 72: // вверх
            if (m_pos - 1 >= 0) --m_pos;
            menu();
            break;
        case 13: // Enter
            go(m_pos);
            break;
        default:
            goto l;
        }
    }
    switch (ch)
    {
    case 80: // вниз
        if (m_pos + 1 < max_pos) ++m_pos;
        menu();
        break;
    case 72: // вверх
        if (m_pos - 1 >= 0) --m_pos;
        menu();
        break;
    case 13: // Enter
        go(m_pos);
        break;
    default:
        goto l;
    }
}

int main()
{

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("cls"); // очистить экран
    hidecursor();


 
    showBorder();
    menu();



    return 0;
}