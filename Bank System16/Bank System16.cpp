#include <iostream>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
using namespace std;


int main()
{
	system("color f0");

	employee e;
	e.setBalance(2500);
	Client c;

	Admin a;
	a.setPassword("65256252562625");

	a.display();

	e.display();
	c.display();


}

