#pragma once
#pragma message("Top in: " __FILE__)
#include"EmployeeManager.h"
#pragma message("Before class in: " __FILE__)
class AdminManager :public EmployeeManager
{
public:
	static void printAdminMenu()
	{
		EmployeeManager::printEmployeeMenu();
		cout << "5-Edit Employee\n";

	}
	
	static void editEmployeeInfo(unique_ptr<Employee>& employee)
	{
		string name, password;

		double salray;

		cout << "\nEnter Name: ";
		cin >> name;
		if (Validation::checkName(name))
		{
			employee->setName(name);
		}

		cout << "\nEnter Password: ";
		cin >> password;

		if (Validation::checkPassword(password))
		{
			employee->setPassword(password);

		}


		cout << "\nEnter Salary: ";
		cin >> salray;
		if (Validation::checkBalance(salray))
		{
			employee->setSalary(salray);
		}

	}

	static unique_ptr<Admin> loginAsAdmin(int id, string password)
	{
		fstream file("admins.txt", ios::in);

		string line;

		vector<string>admins;
		vector<string>ids;
		vector<string>temp;
		vector<string>passwords;

		vector<string> tokens;

		while (getline(file, line))
		{
			admins.push_back(line);
			temp = Parser::split(line, 1);
			ids.insert(ids.end(), temp.begin(), temp.end());

			regex re("[|.]");
			sregex_token_iterator first{ line.begin(), line.end(), re, -1 }, last;//the '-1' is what makes the regex split (-1 := what was not matched)
			vector<string> tokens{ first, last };
			passwords.push_back(tokens[2]);
		}

		int current_line = 0;
		int i = 0;
		for (i = 0; i < ids.size(); i++)
		{
			if (id > ids.size())
			{
				cout << "User not found";
				break;
			}
			if (id != stoi(ids[i]))
			{
				current_line++;
			}
			if (id == stoi(ids[i]))
			{
				if (password == passwords[current_line])
				{
					unique_ptr<Admin>admin;
					admin = Parser::parseToAdmin(admins[current_line]);
					return admin;
					break;
				}
				else if (password != passwords[current_line])
				{
					cout << "Password is worng\n";
					break;
				}

			}
		}


		return nullptr;

	}


};

