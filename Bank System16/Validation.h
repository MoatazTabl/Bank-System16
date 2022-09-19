#pragma once
#include<string>
#include<iostream>
#include <Windows.h>
using namespace std;

class Validation
{
public:

	//try catch to check the lentgh of the name
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

};



