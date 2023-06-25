#include "utilities.h"


std::ifstream OpenStream(const std::string& nameFile)
{
	std::ifstream ifs(nameFile);

	if (ifs.fail())
	{
		std::cout << "Error opening file " << nameFile << std::endl;
		exit(0);
	}
	else
	{
		return ifs;
	}
}

void PrintFile(std::ifstream& stream, const std::string& name)
{
	std::cout << "--- " << name << " ---\n";
	while (!stream.fail())
	{
		std::string str;
		getline(stream, str);
		std::cout << str << std::endl;
	}
}

void Masking(std::ifstream& image, std::ifstream& mask, std::ofstream& result)
{
	image.clear();
	image.seekg(0, std::ios_base::beg);
	mask.clear();
	mask.seekg(0, std::ios_base::beg);

	while (!image.eof())
	{
		std::string strImage;
		getline(image, strImage);

		std::string strMask;
		getline(mask, strMask);


		std::stringstream localStreamImage;
		localStreamImage << strImage;
		std::stringstream localStreamMask;
		localStreamMask << strMask;


		int cImage;
		int cMask;

		localStreamImage >> cImage;
		localStreamMask >> cMask;

		while (localStreamImage)
		{
			result << (cImage & (cMask == 0 ? 0 : cImage)) << ' ';
			localStreamImage >> cImage;
			localStreamMask >> cMask;
		}
		result << '\n';

	}
}

void MakeCompressedMask(std::ifstream& mask, std::ofstream& compressed)
{
	mask.clear();
	mask.seekg(0, std::ios::beg);

	while (!mask.eof())
	{
		std::string str;
		getline(mask, str);

		int temp{};

		std::stringstream localStream;
		localStream << str;

		while (true)
		{
			int value;
			localStream >> value;

			if (!localStream)
			{
				break;
			}

			temp = temp << 1;
			temp |= value;
		}
		compressed << temp << std::endl;
	}
	compressed.close();
}

