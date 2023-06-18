#include "menu.h"

const size_t kLaps = 5;
const std::string kPath = "race.txt";


int main()
{
	
	TestTxtFile(kPath);
	
	MainMenu();

	return 0;
}


