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
	Admin(string name = " ", string password = " ", int id = 0, double balance = 0.0, double salary = 0.0) : Employee(name, password, id, balance, salary)
	{

	}

	//methods
	void deposite(double amount)
	{
		Employee::deposite(amount);
	}
	void withdraw(double amount)
	{
		Employee::withdraw(amount);
	}
	void transferTo(double amount, Client* recipient)
	{
		Employee::transferTo(amount, recipient);
	}
	void checkBalance()
	{
		Employee::checkBalance();
	}
	void displayInfo()
	{
		Employee::displayInfo();
	}










};

