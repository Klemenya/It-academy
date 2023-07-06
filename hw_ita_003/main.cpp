#include <vector>
#include <iostream>
#include <memory>


void findMinEven(std::vector<int>&, std::shared_ptr<int>&);
void findMinOdd(std::vector<int>&, std::shared_ptr<int>&);

int main()
{
    std::vector<int> myVec = { 1,5,7,9,5,11,13,2,3,17 };

    if (myVec.size() != 0) {
        std::shared_ptr<int> minElement;
        minElement = nullptr;

        findMinEven(myVec, minElement);

        if (minElement == nullptr) {
            findMinOdd(myVec, minElement);
        }

        std::cout << *minElement;
    }
    else
    {
        std::cout << "Error! Vector is empty!" << std::endl;
    }



}

void findMinEven(std::vector<int>& v, std::shared_ptr<int>& ptr) {

    for (auto el : v) {
        if (el % 2 == 0)
        {
            if (ptr == nullptr)
            {
                ptr = std::make_shared <int>();
                *ptr = el;
            }
            else
            {
                if (*ptr > el)
                {
                    *ptr = el;
                }
            }
        }
    }
}

void findMinOdd(std::vector<int>& v, std::shared_ptr<int>& ptr) {

    for (auto el : v) {
        if (el % 2 != 0)
        {
            if (ptr == nullptr)
            {
                ptr = std::make_shared <int>();
                *ptr = el;
            }
            else
            {
                if (*ptr > el)
                {
                    *ptr = el;
                }
            }
        }
    }
}