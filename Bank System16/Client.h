#include <iostream>
#include<string>
#include "Validation.h"
using namespace std;
#pragma once
class Client
{
private:

	
protected:
	string name, password;
	int id;
	double balance = NULL;
public:

	//const
	Client(string name = " ", string password = " ", int id = 0, double balance = 0.0)
	{
		setName(name);
		setPassword(password);
		setID(id);
		setBalance(balance);
	}

	//setters / getters
	void setName(string name)
	{
		if (Validation::checkName(name))
			Client::name = name;

	}
	string getName()
	{
		return name;
	}

	void setPassword(string password)
	{
		if (Validation::checkPassword(password))

			Client::password = password;

	}
	string getPassword()
	{
		return password;
	}

	void setBalance(double balance)
	{
		if (Validation::checkBalance(balance))
			Client::balance = balance;
	}
	double getBalance()
	{
		return balance;
	}

	void setID(int id)
	{
		Client::id = id;
	}
	int getID()
	{
		return id;
	}

	//methods
	void deposite(double amount)
	{
		Client::balance += amount;
	}
	void withdraw(double amount)
	{
		if (amount <= this->balance)
		{
			Client::balance -= amount;
		}
		else
		{
			cout << "amount exceeded your balance is : " << this->getBalance() << endl;
		}
	}
	void transferTo(double amount, Client& recipient)
	{
		if (amount <= Client::balance)
		{
			Client::balance -= amount;
			recipient.deposite(amount);
		}
		else
		{
			cout << "amount exceeded your balance is : " << getBalance() << endl;
		}
	}
	void checkBalance()
	{
		cout << "Balance is : " << getBalance() << endl;
	}
	void displayInfo()
	{
		cout << "Name : " << getName() << endl;
		cout << "Password : " << getPassword() << endl;
		cout << "Id : " << getID() << endl;
		cout << "Balance : " << getBalance() << endl;
		cout << "****************" << endl;

	}

};

