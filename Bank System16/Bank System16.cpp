#include <iostream>
#include<string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;

int main()
{
	system("color f0");

	/*Client* p1 = nullptr;
	Client* p2 = nullptr;

	p1 = new Client("mahmoud badawy biomy", "biomy2020", 50002000, 2000);
	p2 = new Employee("abdo ahmed hassan", "abdo2020", 3001000, 3000, 6000);

	p1->displayInfo();

	p2->displayInfo();

	p1->transferTo(500, p2);

	p2->displayInfo();

	delete p1, p2;*/

	Admin* e1 = nullptr;

	e1 = new Admin("Moataz", "17sdsdsd89", 5, 2500, 5500);

	e1->displayInfo();

	e1->setName("moat");

	

	delete e1;
}

