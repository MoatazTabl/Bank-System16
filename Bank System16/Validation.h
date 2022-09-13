#include<string>
#include<iostream>
using namespace std;
class Validation
{
public:
	//try catch to check the lentgh of the name
	bool checkName(string name)
	{
		try
		{
			if (name.length()<5)
			{
				cout << "Name cannot be less than 5 chars\n";
				throw name;
			}
			else if (name.length()>20)
			{
				cout << "Name cannot be more than 20 chars\n";
				throw name;
			}
			else
			{
				return true;
			}
		}
		catch (string name)
		{
			return false;
		}

	}

	bool checkPassword(string password)
	{
		try
		{
			if (password.length() < 8)
			{
				cout << "Password cannot be less than 8 chars\n";
				throw password;
			}
			else if (password.length() > 20)
			{
				cout << "Password cannot be more than 20 chars\n";
				throw password;
			}
			else
			{
				return true;
			}
		}
		catch (string password)
		{
			return false;
		}
	}

	bool checkBalance(double balnace)
	{
		try
		{
			if (balnace<1500)
			{
				cout << "Balance can`t be less than 1500\n";
				throw balnace;
			}
			else
			{
				return true;
			}
		}
		catch (double balance)
		{
			return false;
		}
	}

	bool checkSalary(double salary)
	{
		try
		{
			if (salary<5000)
			{
				cout << "Salray cannot be less than 5000$\n";
				throw salary;
			}
			else
			{
				return true;
			}

		}
		catch (double salary)
		{
			return false;
		}
	}

};

