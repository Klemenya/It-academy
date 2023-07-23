#pragma once

#include <Windows.h>

const char ulcSymbol = '\xc9';		// upper-left corner symbol
const char urcSymbol = '\xbb';		// upper-right corner symbol
const char llcSymbol = '\xc8';		// lower-left corner symbol
const char lrcSymbol = '\xbc';		// lower-right corner symbol
const char hbSymbol = '\xcd';		// horizontal border symbol
const char vbSymbol = '\xba';		// vertical border symbol

const int consoleWidth = 80;
const int consoleHeight = 23;

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




void SetUpConsole();
void HideCursor();
