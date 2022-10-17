#pragma once
#pragma message("Top in: " __FILE__)
#include "Employee.h"
#include <iostream>

#include<string>
#include "Validation.h"


using namespace std;


#pragma message("Before class in: " __FILE__)
class Admin :public Employee
{
public:
	//const
	Admin(int id = 0, string name = " ", string password = " ", double salary = 0.0) : Employee(id, name, password, salary)
	{

	}

	//methods

	void addEmployee(Employee& employee);

	template<class T>
	unique_ptr<T> searchEmployee(int id)
	{
		fstream file;
		file.open("employees.txt", ios::in);
		string line;
		vector<string>temp;
		vector <string> EmployeeNum;
		vector <string> Employees;

		while (getline(file, line))
		{
			Employees.push_back(line);

			temp = Parser::split(line, 1);

			EmployeeNum.insert(EmployeeNum.end(), temp.begin(), temp.end());
		}


		int idd = 0;
		int current_line = 0;
		for (int i = 0; i < EmployeeNum.size(); i++)
		{
			string temp = EmployeeNum[i];

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
			cout << "Employee not found\n";
			return nullptr;
		}
		else {
			if constexpr (is_same_v<T, Client>)
			{
				unique_ptr<T>c(new T(Parser::parseToClient(Employees[current_line])));


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
	void editEmployee(int id, string name, string password, double salary)
	{
		fstream file("employees.txt", ios::in);

		string line;
		vector<string>employees;


		unique_ptr<int>emp = move(searchEmployee<int>(id));

		if (emp != nullptr)
		{
			while (getline(file, line))
			{
				employees.push_back(line);

			}
			file.close();


			file.open("employees.txt", std::ofstream::out | std::ofstream::trunc);
			for (int i = 0; i < employees.size(); i++)
			{

				if (i == *emp)
				{
					file << id << "|" << name << "|" << password << "|" << salary << endl;

				}
				else if (i != *emp)
				{
					file << employees[i];
					file << "\n";
				}

			}
		}


	}
	void listEmployee()
	{
		string line;
		fstream file("employees.txt", ios::in);
		vector <string>clients;
		vector <string>temp;
		while (getline(file, line))
		{
			temp = Parser::split(line);

			clients.insert(clients.end(), temp.begin(), temp.end());

			cout << "\nId: " << temp[0];
			cout << "\nName: " << temp[1];
			cout << "\nPassword: " << temp[2];
			cout << "\nSalary: " << temp[3];
			cout << "\n********************";

		}
	}




};

#include "FileManager.h"



void Admin::addEmployee(Employee& employee)
{
	FileManager m;
	m.addEmployee(employee);
}
