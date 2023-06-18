
#include "menu.h"


void MainMenu()
{
	char menuItem{};

	while (menuItem != 'q' && menuItem != 'Q')
	{
		system("cls");

		std::cout << "1. Read from file" << std::endl;
		std::cout << "2. Enter race data" << std::endl;
		std::cout << "3. ............" << std::endl;
		std::cout << "4. Erase race data" << std::endl;
		std::cout << "Q. EXIT" << std::endl;
		std::cout << std::endl;

		std::cout << "Please, make your choice" << std::endl;

		menuItem = _getch();

		switch (menuItem)
		{
		case '1': 
			Print(); 
			break;	
		case '2': 
			EnterRaceData(); 
			break;
		case '4':
			EraseRaceData();
			break;
		default:
			break;
		}
	}
	return;
}

void Print() {

	system("cls");
	extern const size_t kLaps;
	extern const std::string kPath;

	std::fstream fs(kPath, std::ios::in);

	PrintATableHeader();

	size_t line{ 0 };

	while (!fs.eof())
	{
		line++;

		std::string str;
		getline(fs, str);
		PrintParsingLine(str);
		if (line % kLaps == 0)
		{
			std::cout << " ---------------------------- " << std::endl;
		}
	}

	fs.close();
	std::cout << "Press any key to EXIT" << std::endl;
	char temp = _getch();

	return;
}

void EnterRaceData()
{
	size_t raceNumber = GetRowInTxt();

	system("cls");
	std::ofstream ofs(kPath, std::ios::app);

	for (size_t lapNumber(1); lapNumber <= kLaps; ++lapNumber)
	{
		char delimiter{ ';' };
		std::stringstream ss;

		float lapTime = GetLapTime(lapNumber);

		std::string lapNote = GetLapNote(lapNumber);

		ss << raceNumber << delimiter << lapNumber << delimiter;
		ss << std::fixed << std::setprecision(3) << lapTime;

		if (lapNote.size() != 0)
		{
			ss << delimiter << lapNote;
		}

		std::string str;
		ss >> str;

		if (raceNumber == 1 && lapNumber == 1)
		{
			ofs << str;
		}
		else
		{
			ofs << '\n' << str;
		}


	}

	ofs.close();

	return;
}

void EraseRaceData()
{
	extern const std::string kPath;
	system("cls");
	std::cout << "                Warning!";
	std::cout << "This operation will destroy all race data!";
	std::cout << "Are you sure? Y / N" << std::endl;
	char confirm = _getch();

	if (toupper(confirm) == 'Y')
	{
		std::ofstream ef(kPath);
		ef.close();
		std::cout << "All race data is erased" << std::endl;
	}
	else
	{
		std::cout << "Data NOT erased" << std::endl;
	}
	std::cout << "Press any key for EXIT" << std::endl;
	char temp = _getch();

	return;
}

float GetLapTime(size_t lap)
{
	std::cout << "Lap # " << lap << ". Enter lap time, please: ";
	std::string strTime;

	getline(std::cin, strTime);

	while (!CheckFloat(strTime))
	{
		std::cout << "Error enering time\n";
		std::cout << "Lap # " << lap << ". Enter lap time, please: ";
		getline(std::cin, strTime);
	}

	float time = stof(strTime);

	return time;
}

std::string GetLapNote(size_t)
{
	std::string str{};
	std::cout << "Enter lap note, if need, please: ";
	getline(std::cin, str);
	return str;
}

void PrintATableHeader()
{
	std::cout << " ---------------------------- \n";
	std::cout << "| Race # |  Lap # | Lap time |\n";
	std::cout << " ---------------------------- \n";
	return;
}

void PrintParsingLine(std::string str)
{
	size_t leftCharacter = 0;
	size_t rightCharacter = str.find(';');

	size_t col{ 0 };

	while (rightCharacter != std::string::npos && col != 4) {
		col++;
		std::cout << "|";

		size_t widthCol{ 0 };

		col < 3 ? widthCol = 7 : widthCol = 9;

		std::cout.left;
		std::cout.width(widthCol);

		std::cout << str.substr(leftCharacter, rightCharacter - leftCharacter) << " ";

		leftCharacter = rightCharacter + 1;
		rightCharacter = str.find(';', rightCharacter + 1);
		if (rightCharacter == std::string::npos)
		{
			std::cout << "|";
		}
	}


	if (col == 2)
	{
		std::cout.left;
		std::cout.width(9);
		std::cout << str.substr(leftCharacter, rightCharacter - leftCharacter) << " |";
		std::cout << "* No more information on the lap: " << std::endl;
	}
	else if (col == 3)
	{
		std::cout << "More info: " << str.substr(leftCharacter, rightCharacter - leftCharacter) << std::endl;
	}

	return;
}
