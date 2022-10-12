#pragma once
#pragma message("Top in: " __FILE__)
#include <iostream>
#include<string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Validation.h"

#include "Parser.h"

using namespace std;

#pragma message("Before class in: " __FILE__)

class Employee
{
protected:
	double salary = NULL;
	string name,password;
	int id;
	fstream clientFile;
	
public:
	//const
	Employee(int id = 0, string name = " ", string password = " ",  double salary = 0.0)
	{
		setName(name);
		setPassword(password);
		setID(id);
		setSalary(salary);
	}

	//setters / getters
	void setName(string name)
	{
		if (Validation::checkName(name))
		{
			Employee::name = name;
		}

	}
	string getName()
	{
		return name;
	}

	void setPassword(string password)
	{
		if (Validation::checkPassword(password))
		{
			Employee::password = password;
		}
	}
	string getPassword()
	{
		return password;
	}

	

	void setID(int id)
	{
		Employee::id = id;
	}
	int getID()
	{
		return id;

	}

	void setSalary(double salary)
	{
		if (Validation::checkSalary(salary))
		{
			Employee::salary = salary;
		}
	}
	double getSalary()
	{
		return salary;
	}
	//methods
	
	void displayInfo()
	{
		cout << "Name : " << getName() << endl;
		cout << "Password : " << getPassword() << endl;
		cout << "Id : " << getID() << endl;
		cout << "Salary : " << getSalary() << endl;
		cout << "****************" << endl;

	}

	void addClient(Client& client)
	{

		fstream file("clients.txt", ios::app);

		file << client.getID() << '|' << client.getName() << '|' << client.getPassword() << '|' << client.getBalance() << endl;
		file.close();
	}

	Client searchClient(int id)
	{
		fstream file;
		file.open("clients.txt",ios::in);
		string line;
		vector<string>temp;
		vector <string> ClientNum;
		vector <string> Clients;
		while (getline(file, line))
		{
			Clients.push_back(line);

			temp=Parser::split(line, 1);

			ClientNum.insert(ClientNum.end(),temp.begin(), temp.end());
		}

		int current_line = 0;
		int idd = 0;
		for (int i=0; i< ClientNum.size();i++)
		{
			string temp=ClientNum[i];

			idd = stoi(temp);
			
			if (idd!=id)
			{
				current_line++;
			}
			else if (idd=id)
			{
				break;
			}
			
		}

		if (idd!=id)
		{
			cout << "Client not found\n";
			return 1;
		}
		else {
			Client c(Parser::parseToClient(Clients[current_line]));

			return c;
		}
		
		
	}

	void listClient()
	{
		string line;
		fstream file("clients.txt", ios::in);
		vector <string>clients;
		vector <string>temp;
		while (getline(file,line))
		{
			temp=Parser::split(line);

			clients.insert(clients.end(), temp.begin(), temp.end());

			cout << "\nId: " << temp[0];
			cout << "\nName: " << temp[1];
			cout << "\nPassword: " << temp[2];
			cout << "\nBalance: " << temp[3];
			cout << "\n********************";

		}
	}

	void editClient(int id, string name, string password, double balance)
	{
		searchClient(id);


	}

};

