#pragma once
#include <iostream>
#include <string>
#include "Person.h"
using namespace std;


class Client :public Person
{

public:

	void deposit(double amount)
	{
		balance += amount;
	}
	void withdraw(double amount)
	{
		balance -= amount;
	}

	void transferTo(double amount, Client& recipent)
	{
		balance -= amount;
		recipent.balance += amount;
	}

	void checkBalance()
	{
		cout << "Your Balance is: " << balance << endl;
	}

	void display()
	{
		Person::display();
		cout << "\v";
		cout << "***********************\n";
	}
};

