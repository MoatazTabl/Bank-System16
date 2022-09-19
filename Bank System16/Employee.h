#include <iostream>
#include<string>
#include "Validation.h"
#include "Client.h"
using namespace std;
#pragma once
class Employee : public Client
{
protected:
	double salary = NULL;
public:
	//const
	Employee(string name = " ", string password = " ", int id = 0, double balance = 0.0, double salary = 0.0) : Client(name, password, id, balance)
	{
		this->setSalary(salary);
	}
	//setters / getters 
	virtual void setSalary(double salary)
	{
		if (Validation::checkSalary(salary))
			this->salary = salary;

	}
	virtual double getSalary()
	{
		return this->salary;
	}

	//methods
	virtual void deposite(double amount)
	{
		Client::deposite(amount);
	}
	virtual void withdraw(double amount)
	{
		Client::withdraw(amount);
	}
	virtual void transferTo(double amount, Client* recipient)
	{
		Client::transferTo(amount, recipient);
	}
	virtual void checkBalance()
	{
		Client::checkBalance();
	}
	virtual void displayInfo()
	{
		cout << "Name : " << this->getName() << endl;
		cout << "Password : " << this->getPassword() << endl;
		cout << "Id : " << this->getID() << endl;
		cout << "Balance : " << this->getBalance() << endl;
		cout << "Salary : " << this->getSalary() << endl;
		cout << "****************" << endl;
	}

};

