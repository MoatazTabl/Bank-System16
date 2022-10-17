#pragma once
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
#include <memory>
#include<fstream>
#include<vector>
#include<regex>


class ClientManger
{
public:
	static void printClientMenu()
	{
		cout << "\n1-Check Balance\n";
		cout << "2-Depoist\n";
		cout << "3-Withdraw\n";
		cout << "4-Transfer to\n";
		cout << "5-Update Password\n";


	}
	static void updatePassword(unique_ptr<Client>& person)
	{
		string pass;
		cout << "Enter New Password: ";
		cin >> pass;

		if (Validation::checkPassword(pass))
		{

			fstream file("clients.txt", ios::in);

			string line;
			vector<string>clients;



			Employee emp;

			unique_ptr<int>c1 = move(emp.searchClient<int>(person->getID()));

			if (c1 != nullptr)
			{
				while (getline(file, line))
				{
					clients.push_back(line);

				}
				file.close();


				file.open("clients.txt", std::ofstream::out | std::ofstream::trunc);
				for (int i = 0; i < clients.size(); i++)
				{

					if (i == *c1)
					{
						file << person->getID() << "|" << person->getName() << "|" << pass << "|" << person->getBalance() << endl;

					}
					else if (i != *c1)
					{
						file << clients[i];
						file << "\n";
					}

				}
			}

			cout << "Password Changed.\n";
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
				else if(password != passwords[current_line])
				{
					cout << "Password is worng\n";
					break;
				}

			}
		}
		

		return nullptr;
	}
	

};

