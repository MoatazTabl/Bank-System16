#include <iostream>
#include<string>
#include "Validation.h"
#include "Employee.h"
using namespace std;
#pragma once
class Admin : public Employee
{
public:
	//const
	Admin(string name = " ", string password = " ", int id = 0 ,double salary = 0.0) : Employee(name, password, id, salary)
	{

	}

	//methods
	
	void displayInfo()
	{
		Employee::displayInfo();
	}

};

