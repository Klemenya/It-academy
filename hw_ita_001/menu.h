#pragma once

#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <conio.h>
#include <string>
#include <fstream>
#include <sstream>
#include "utilities.h"

extern const size_t kLaps;
extern const std::string kPath;

void MainMenu();
void Print();

void EnterRaceData();
void EraseRaceData();
void PrintParsingLine(std::string);
void PrintATableHeader();

float GetLapTime(size_t);
std::string GetLapNote(size_t);
