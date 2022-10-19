#pragma once
#pragma message("Top in: " __FILE__)
#include "Validation.h"

#include "Client.h"
#include <iostream>
#include<string>
#include <sstream>
#include <vector>
#include <fstream>
#include<memory>
#pragma message("Before class in: " __FILE__)

using namespace std;


class Employee
{
private:
	
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

	void addClient(Client& client);
	
	template<class T>
	static unique_ptr<T> searchClient(int id);

	void listClient();

	
	static void editClient(int id, string name, string password, double balance)
	{
		fstream file("clients.txt", ios::in);
		
		string line;
		vector<string>clients;


		unique_ptr<int>c1 = move(searchClient<int>(id));

		if (c1!=nullptr)
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
					file << id << "|" << name << "|" << password << "|" << balance << endl;

				}
				else if (i != *c1)
				{
					file << clients[i];
					file << "\n";
				}

			}
		}
		
	}
};

#include"Filehelper.h"
#include "Parser.h"

void Employee::addClient(Client& client)
{
	FileHelper::saveClient(client);
	
}



template<class T>
 static unique_ptr<T> Employee::searchClient(int id)
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

			break;
		}

	}

	if (idd != id)
	{
		cout << "Client not found\n";
		return nullptr;
	}
	else {
		if constexpr (is_same_v<T, Client>)
		{
			unique_ptr<T>c(new T(Parser::parseToClient(Clients[current_line])));


			return c;
		}
		else if constexpr (is_same_v<T, int>)
		{
			unique_ptr<T>line_num(new int);

			line_num = make_unique<int>(current_line);
			return line_num;
		}

	}
}

 void Employee::listClient()
 {
	 string line;
	 fstream file("clients.txt", ios::in);
	 vector <string>clients;
	 vector <string>temp;
	 while (getline(file, line))
	 {
		 temp = Parser::split(line);

		 clients.insert(clients.end(), temp.begin(), temp.end());

		 cout << "\nId: " << temp[0];
		 cout << "\nName: " << temp[1];
		 cout << "\nPassword: " << temp[2];
		 cout << "\nBalance: " << temp[3];
		 cout << "\n********************";

	 }
 }

