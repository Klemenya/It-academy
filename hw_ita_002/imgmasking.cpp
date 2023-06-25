
#include <fstream>

#include "utilities.h"

constexpr auto IMAGE = "image.txt";
constexpr auto MASK = "mask.txt";
constexpr auto RESULT = "result.txt";
constexpr auto COMPRESSED = "compressed_mask.txt";


int main(int argc, char* argv[])
{

	std::ifstream ifsImg = OpenStream(IMAGE);
	std::ifstream ifsMask = OpenStream(MASK);
	std::ofstream ofsCompressed(COMPRESSED);
	std::ofstream ofsResult(RESULT);

	PrintFile(ifsImg, IMAGE);
	PrintFile(ifsMask, MASK);

	Masking(ifsImg, ifsMask, ofsResult);
	ofsResult.close();

	std::ifstream ifsResult = OpenStream(RESULT);
	PrintFile(ifsResult, RESULT);

	MakeCompressedMask(ifsMask, ofsCompressed);

	std::ifstream ifsCompressed = OpenStream(COMPRESSED);
	PrintFile(ifsCompressed, COMPRESSED);

	ifsResult.close();
	ifsMask.close();
	ifsImg.close();

	return 0;
}
