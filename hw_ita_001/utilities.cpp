#include "utilities.h"

void IgnoreStream()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

size_t GetRowInTxt() 
{
	

	std::ifstream ifs(kPath);
	size_t cnt(0);
	
	std::string temp;
	
	getline(ifs, temp);
	
	while (!ifs.eof()) 
	{
		getline(ifs, temp);
		cnt++;
	}
	
	ifs.close();

	return (cnt + kLaps - 1) / kLaps + 1;
}

void TestTxtFile(std::string path)
{
	std::ifstream temp(path);
	
	if (!temp.is_open())
	{
		
		std::cout << "Error opening file!" << std::endl;
		std::cout << "Creating a new file!" << std::endl;
		std::ofstream temp(path);
		temp.close();
		
		std::this_thread::sleep_for(std::chrono::seconds(3));
	}
	return;
}

bool CheckFloat(std::string str) {
	bool res = true;

	for (auto c : str)
	{
		if (!std::isdigit(c) && c != '.')
		{
			res = false;

		}
	}

	return res;
}
