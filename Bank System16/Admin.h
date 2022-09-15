#pragma once
#include "Person.h"

class Admin : public Person
{
public:
	void display()
	{
		Person::display();
		cout << "salary: " << salary << endl;
		cout << "\v";
		cout << "***********************\n";
	}
};