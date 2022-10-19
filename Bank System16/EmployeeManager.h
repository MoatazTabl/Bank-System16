#pragma once
#pragma message("Top in: " __FILE__)
#include"Client.h"
#include "Employee.h"
#include "FileHelper.h"
#include"Validation.h"
#include<iostream>
#include<memory>
#pragma message("Before class in: " __FILE__)
using namespace std;
class EmployeeManager
{

public:
	static void printEmployeeMenu()
	{
		cout << "\n1-Add Client\n";
		cout << "2-Search Client\n";
		cout << "3-List Client\n";
		cout << "4-Edit Client\n";
		
	}

	static void newClient(unique_ptr<Client>& client)
	{
		FileHelper::saveClient(*client);
	}

	static void listAllClients()
	{
		FileHelper::getAllClients();
	}

	static void searchForClient(unique_ptr<Client>& client)
	{
		fstream file("clients.txt", ios::in);

		string line;

		vector<string>clients;
		vector<string>ids;
		vector<string>temp;
		vector<string>names;

		vector<string> tokens;

		while (getline(file, line))
		{
			clients.push_back(line);
			temp = Parser::split(line, 1);
			ids.insert(ids.end(), temp.begin(), temp.end());

			regex re("[|.]");
			sregex_token_iterator first{ line.begin(), line.end(), re, -1 }, last;//the '-1' is what makes the regex split (-1 := what was not matched)
			vector<string> tokens{ first, last };
			names.push_back(tokens[1]);
		}
		string name = client->getName();
		int id = client->getID();
		int current_line = 0;
		int i = 0;
		for (i = 0; i < ids.size(); i++)
		{
			if (id >= ids.size())
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
				if (name == names[current_line])
				{
					client->displayInfo();
					break;
				}
				else if (name != names[current_line])
				{
					cout << "Password is worng\n";
					break;
				}

			}
		}


		
		
	}

	static void editClientInfo(unique_ptr<Client>& client)
	{
		string name, password;
		int id;
		double balance;
		
		cout << "Enter ID: ";
		cin >> id;

		cout << "Enter Name: ";
		cin >> name;
		if (Validation::checkName(name))
		{
			client->setName(name);
		}
		
		cout << "Enter Password: ";
		cin >> password;
		
		if (Validation::checkPassword(password))
		{
			client->setPassword(password);

		}


		cout << "Enter Balance: ";
		cin >> balance;
		if (Validation::checkBalance(balance))
		{
			client->setBalance(balance);
		}

	}

	static unique_ptr<Client> loginClient(int id, string password)
	{
		fstream file("clients.txt", ios::in);

		string line;

		vector<string>clients;
		vector<string>ids;
		vector<string>temp;
		vector<string>passwords;

		vector<string> tokens;

		while (getline(file, line))
		{
			clients.push_back(line);
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
			if (id >= ids.size())
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
					unique_ptr<Client>c1;
					c1 = Parser::parseToClient(clients[current_line]);
					return c1;
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

	static unique_ptr<Employee> loginAsEmployee(int id, string password)
	{
		fstream file("employees.txt", ios::in);

		string line;

		vector<string>employees;
		vector<string>ids;
		vector<string>temp;
		vector<string>passwords;

		vector<string> tokens;

		while (getline(file, line))
		{
			employees.push_back(line);
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
			if (id >= ids.size())
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
					unique_ptr<Employee>emp;
					emp = Parser::parseToEmployee(employees[current_line]);
					return emp;
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

