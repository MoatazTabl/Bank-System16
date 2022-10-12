#pragma once
#pragma message("Top in: " __FILE__)
#include<string>
#include<iostream>
using namespace std;
#pragma message("Before class in: " __FILE__)
class Validation
{
public:

	static bool checkName(string name)
	{
		if (name.length() >= 5 && name.length() <= 20)
		{
			return true;
		}
		else
		{
			cout << "Name must be min 5 chars and max 20 chars\n";
			return false;
		}
	}

	static bool checkPassword(string password)
	{

		if (password.length() >= 8 && password.length() <= 20)
		{
			return true;
		}
		else
		{
			cout << "Password must be min 8 chars and max 20 chars\n";
			return false;
		}

	}

	static bool checkBalance(double balnace)
	{

		if (balnace < 1500)
		{
			cout << "Balance can`t be less than 1500$\n";
			return false;
		}

	}

	static bool checkSalary(double salary)
	{

		if (salary < 5000)
		{
			cout << "Salray cannot be less than 5000$\n";
			return false;
		}

	}

	static bool UserChoiceLogin(int userChoice)
	{
		if (userChoice >= 1 && userChoice <= 3)
		{
			
			return true;
		}
		else
		{
			cout << "please enter a correct number";
			return false;
		}
	}

};



