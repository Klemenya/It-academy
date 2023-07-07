#pragma once

#include <vector>
#include <iostream>
#include <memory>


void printSumDigitsMinAndMaxNumbers(std::shared_ptr<std::vector<int>>);

size_t getMinElementID(std::shared_ptr<std::vector<int>>);
size_t getMaxElementID(std::shared_ptr<std::vector<int>>);

void finMinElement(std::shared_ptr<std::vector<int>>);

void findMinEven(std::shared_ptr<std::vector<int>> pMyVector, std::shared_ptr<int>& ptr);
void findMinOdd(std::shared_ptr<std::vector<int>> pMyVector, std::shared_ptr<int>& ptr);

void getSumOdd(std::shared_ptr<std::vector<int>> pMyVector);
void getProductOfElementsWithOddIndexes(std::shared_ptr<std::vector<int>> pMyVector);

void swap(std::shared_ptr<std::vector<int>> pMyVector);