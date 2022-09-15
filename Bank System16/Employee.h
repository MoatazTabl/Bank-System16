#pragma once
#include <iostream>
#include <string>
#include "person.h"
using namespace std;

class Person;
class employee : public Person
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