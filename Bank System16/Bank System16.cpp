#include <iostream>
#include<string>
#include<fstream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

int main()
{
	system("color f0");

	try
	{

	}
	catch (const std::exception&)
	{

	}

	Admin* e1 = nullptr;

	e1 = new Admin("Moataz", "17sdsdsd89", 5, 2500, 5500);

	e1->displayInfo();

	e1->setName("moat");

	

	delete e1;
}

