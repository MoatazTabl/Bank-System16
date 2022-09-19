#include <iostream>
#include<string>
#include "Validation.h"
using namespace std;
#pragma once
class Client
{
protected:
	string name, password;
	int id;
	double balance = NULL;
public:

	//const
	Client(string name = " ", string password = " ", int id = 0, double balance = 0.0)
	{
		this->setName(name);
		this->setPassword(password);
		this->setID(id);
		this->setBalance(balance);
	}

	//setters / getters
	void setName(string name)
	{
		if (Validation::checkName(name))
			this->name = name;

	}
	string getName()
	{
		return this->name;
	}

	void setPassword(string password)
	{
		if (Validation::checkPassword(password))

			this->password = password;

	}
	string getPassword()
	{
		return this->password;
	}

	void setBalance(double balance)
	{
		if (Validation::checkBalance(balance))
			this->balance = balance;
	}
	double getBalance()
	{
		return this->balance;
	}

	void setID(int id)
	{
		this->id = id;
	}
	int getID()
	{
		return this->id;
	}

	//methods
	virtual void deposite(double amount)
	{
		this->balance += amount;
	}
	virtual void withdraw(double amount)
	{
		if (amount <= this->balance)
		{
			this->balance -= amount;
		}
		else
		{
			cout << "amount exceeded your balance is : " << this->getBalance() << endl;
		}
	}
	virtual void transferTo(double amount, Client* recipient)
	{
		if (amount <= this->balance)
		{
			this->balance -= amount;
			recipient->deposite(amount);
		}
		else
		{
			cout << "amount exceeded your balance is : " << this->getBalance() << endl;
		}
	}
	virtual void checkBalance()
	{
		cout << "Balance is : " << this->getBalance() << endl;
	}
	virtual void displayInfo()
	{
		cout << "Name : " << this->getName() << endl;
		cout << "Password : " << this->getPassword() << endl;
		cout << "Id : " << this->getID() << endl;
		cout << "Balance : " << this->getBalance() << endl;
		cout << "****************" << endl;

	}



};

