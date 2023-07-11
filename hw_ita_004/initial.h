#pragma once

#include <Windows.h>
#include <iostream>
#include <conio.h>
#include <string>
#include <memory>

class Organization
{
private:
	std::shared_ptr<std::string> organizationName				= std::make_shared<std::string>("My firm");
	std::shared_ptr<std::string> organizationBusinessAddress	= std::make_shared<std::string>("firm business addres");
	std::shared_ptr<std::string> organizationPostalAddress		= std::make_shared<std::string>("firm business addres");
	int organizationZIP{ 225415 };
	int organizationTIN{ 9638623 };								// смо - taxpayer identification number
	std::shared_ptr<std::string> organizationBankAccount		= std::make_shared<std::string>("BY00 0000 0000 0000 0000 0001");
	Organization* Bank = nullptr;

	//std::string organizationName{ "My firm" };
	//std::string organizationBusinessAddress{"firm business addres"};
	//std::string organizationPostalAddress{"firm postal addres"};
	//std::string organizationBankAccount{ "BY00 0000 0000 0000 0000 0001" };
	
public:
	std::shared_ptr<std::string> GetOrganizationName();
	//GetOrganizationAddress();			//business/postal/zip/ ...phone
	//GetOrganizationBankAccount();
	//GetOrganizationBank();

};


void Initial();
void SetupConsole();

void CheckFile(const std::string&);

