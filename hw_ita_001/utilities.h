#pragma once

#include <iostream>
#include <string>
#include <limits>
#include <fstream>
#include <chrono>
#include <thread>


extern const size_t kLaps;
extern const std::string kPath;

void IgnoreStream();
size_t GetRowInTxt();

void TestTxtFile(std::string);
bool CheckFloat(std::string);

