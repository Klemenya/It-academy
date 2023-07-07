#pragma once

#include <vector>
#include <iostream>
#include <memory>


std::shared_ptr<std::vector<int>> CreateVector();

void printVector(std::shared_ptr<std::vector<int>>, std::string str = "");

void fillVector(std::shared_ptr<std::vector<int>>);

