#include "utilities.h"
#include "setup.h"

#include <iostream>
#include <iomanip>

//#include <string>



void showBorder()
{

    std::cout << ulcSymbol << std::right << std::setfill(hbSymbol) << std::setw(79 - 1) << urcSymbol << std::endl;

    for (size_t idx(0); idx < 23; idx++)
    {
        std::cout << vbSymbol << std::right << std::setfill(' ') << std::setw(79 - 1) << vbSymbol << std::endl;
    }

    std::cout << llcSymbol << std::right << std::setfill(hbSymbol) << std::setw(79 - 1) << lrcSymbol;
}