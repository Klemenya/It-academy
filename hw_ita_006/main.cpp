#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

#include "TemplateVector.h"

int main()
{
	
	//std::vector<std::string> myVecStr;
	//
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("asdfghjkl");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("zxcvbnm,sd");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");
	//myVecStr.push_back("qwertyuiop");

	//std::cout << myVecStr.size() << std::endl;

	//std::string substr {"er"};
	//size_t counter{};

	//auto counSubstrInVectorString = [&substr](std::string& str) { return (str.find(substr) != std::string::npos); };

	//counter = std::count_if(myVecStr.begin(), myVecStr.end(), counSubstrInVectorString);


	//std::cout << counter << std::endl;





	std::vector<int> testInt { 1, 2, 3, 4, 5, 6, 7, 8};
	TemplateVector <int> templatevector({ testInt });

	std::vector<std::string> testString{"text1", "text2", "text3"};
	TemplateVector <std::string> templatevector2({ testString });


	
	templatevector.showVector();
	templatevector2.showVector();






}