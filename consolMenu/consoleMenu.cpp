#include <stdio.h> // ��� printf() � scanf()
#include <conio.h> // ��� _getch()
#include <windows.h>
#include <iostream>
#include <iomanip>

//#include ""



int m_pos = 0;          // ������� ����
int max_pos = 3;        // ������������ ������� ����
char s1[101];

char* ru(const char* s) { AnsiToOem(s, s1);   return s1; } // ����� ������� ������

HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);



void add()
{
    return;
}// ��������� ������

void dif()
{
    return;
}// ��� �������

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


void SetColor(int text, int background) // ������������� ����
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int x, int y) // ������� �������
{
    SHORT X = static_cast<SHORT>(x);
    SHORT Y = static_cast<SHORT>(y);

    COORD coord = { X, Y };
    SetConsoleCursorPosition(hStdOut, coord);
}

void go(int x) // ���� ������ Enter
{
    if (x == 0) add();
    if (x == 1) dif();
    
    
    //std::cout << "\n   ������� �����\n      �������";
    printf(ru("\n   ������� �����\n      �������"));
    
    
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

//    system("cls"); // �������� �����


    if (m_pos == 0)
    {
        SetColor(Yellow, Blue); 
        GotoXY(10, 5);
        printf(ru(" \x1a ��������� �������")); 
        
        SetColor(White, Black);
        GotoXY(10, 6);
        printf(ru("   ������ �������"));
        GotoXY(10, 7);
        printf(ru("   �����"));
        choice();
    }
    if (m_pos == 1)
    {
        GotoXY(10,5);
        printf(ru("   ��������� �������"));

        SetColor(Yellow, Blue);
        GotoXY(10, 6);
        printf(ru(" \x1a ������ �������")); 
        
        SetColor(White, Black);
        GotoXY(10, 7);
        printf(ru("   �����"));
        choice();
    }
    if (m_pos == 2)
    {
        GotoXY(10, 5);
        printf(ru("   ��������� �������"));
        
        GotoXY(10, 6);
        printf(ru("   ������ �������"));

        SetColor(Yellow, Blue);
        GotoXY(10, 7);
        printf(ru(" \x1a �����\n")); 
        
        SetColor(15, 0);
        choice();
    }
}

void choice() // ������� ������
{
l:
    int ch = _getch(); // ��������� �������� ������� �������
    if (ch == 224) // 224 - ��� ���������
    {
        switch (ch)
        {
        case 80: // ����
            if (m_pos + 1 < max_pos) ++m_pos;
            menu();
            break;
        case 72: // �����
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
    case 80: // ����
        if (m_pos + 1 < max_pos) ++m_pos;
        menu();
        break;
    case 72: // �����
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
    system("cls"); // �������� �����
    hidecursor();


 
    showBorder();
    menu();



    return 0;
}