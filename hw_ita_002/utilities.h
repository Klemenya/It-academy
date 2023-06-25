#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <sstream>


std::ifstream OpenStream(const std::string&);

void PrintFile(std::ifstream&, const std::string&);

void Masking(std::ifstream&, std::ifstream&, std::ofstream&);

void MakeCompressedMask(std::ifstream&, std::ofstream&);


