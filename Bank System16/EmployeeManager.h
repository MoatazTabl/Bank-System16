#pragma once
#include"Client.h"
#include "Employee.h"
#include "FileHelper.h"
#include"Validation.h"
#include<iostream>
#include<memory>
using namespace std;
class EmployeeManager
{
public:
	static void printEmployeeMenu()
	{
		cout << "\n1-Add Client";
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
		fstream file;
		file.open("clients.txt", ios::in);
		string line;
		vector<string>temp;
		vector <string> ClientNum;
		vector <string> Clients;

		while (getline(file, line))
		{
			Clients.push_back(line);

			temp = Parser::split(line, 1);

			ClientNum.insert(ClientNum.end(), temp.begin(), temp.end());
		}

		int id = client->getID();
		int idd = 0;
		int current_line = 0;
		for (int i = 0; i < ClientNum.size(); i++)
		{
			string temp = ClientNum[i];

			idd = stoi(temp);

			if (idd != id)
			{
				current_line++;
			}
			else if (idd = id)
			{
				cout << "Client found.\n";
				break;
			}

		}

		if (idd != id)
		{
			cout << "Client not found\n";
			
		}
		
	}
	static void editClientInfo(unique_ptr<Client>& client)
	{
		string name, password;
		
		double balance;
		
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
	static unique_ptr<Client> login(int id, string password)
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
	
};

