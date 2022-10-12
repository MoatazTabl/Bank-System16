#pragma once
#pragma message("Top in: " __FILE__)
#include <iostream>
#include "Employee.h"
#include<string>
#include "Validation.h"


using namespace std;


#pragma message("Before class in: " __FILE__)
class Admin :Employee
{
public:
	//const
	Admin(int id = 0, string name = " ", string password = " ", double salary = 0.0) : Employee(id, name, password,  salary)
	{

	}

	//methods
	
	void displayInfo()
	{
		cout << "Name : " << getName() << endl;
		cout << "Password : " << getPassword() << endl;
		cout << "Id : " << getID() << endl;
		cout << "Salary : " << getSalary() << endl;
		cout << "****************" << endl;
	}

};

