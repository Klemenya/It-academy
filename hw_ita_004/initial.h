#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <memory>

class Organization
{
private:
	std::string organizationName{"My firm"};
	std::string organizationBusinessAddress{"firm business addres"};
	std::string organizationPostalAddress{"firm postal addres"};
	int organizationZIP{225415};
	int organizationTIN{9638623};				// смо - taxpayer identification number
	std::string organizationBankAccount{"BY00 0000 0000 0000 0000 0001"};
	Organization *Bank = nullptr;
	
	
public:
	std::string GetOrganizationName();
	//GetOrganizationAddress();			//business/postal/zip/ ...phone
	//GetOrganizationBankAccount();
	//GetOrganizationBank();

};


void Initial();
void SetupConsole();

void CheckFile(const std::string& );

