#include <iostream>
#include<string>
#include <sstream>
#include <vector>
#include <fstream>
#include "Validation.h"
#include "Client.h"
using namespace std;
#pragma once
class Employee
{
protected:
	double salary = NULL;
	string name,password;
	int id;
	fstream clientFile;
	
public:
	//const
	Employee(string name = " ", string password = " ", int id = 0, double salary = 0.0)
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

		try
		{
			clientFile.open("clients.txt", ios::app);
		}
		catch (const std::exception&)
		{
			clientFile.open("clients.txt");

		}
		clientFile << client.getID() << "|" << client.getName() << "|" << client.getPassword() << "|" << client.getBalance() << endl;
		clientFile.close();
	}

	vector<string> searchClient()
	{
		vector<string>clientVector;
		string temp;

		clientFile.open("clients.txt", ios::in);
		if (clientFile.is_open())
		{
			while (getline(clientFile, temp))
			{
				clientVector.push_back(temp);
			}
		}

		clientFile.close();
		
		//vector<int> 
		for (int i = 0; i < clientVector.size(); i++)
		{
			temp = clientVector[i];

			for (int j = 0; j < temp.size(); j++)
			{
				if (temp=="|")
				{

				}
			}
		}
		
	}

};

