
#include "initial.h"
#include "menu.h"


int main()
{
	Initial();

	Organization organization;
	
	std::cout << sizeof(Organization) << std::endl;

	Menu(organization);

	return 0;
}