#pragma once
#pragma message("Top in: " __FILE__)
#include<iostream>
#include<string>
#include<fstream>
#include "Client.h"
#include"Employee.h"
#include"Admin.h"

#include "FileManager.h"
#pragma message("Before class in: " __FILE__)
using namespace std;
class FileHelper
{
	
public:
	
	static void saveClient(Client& client)
	{
		
		fstream file("clients.txt", ios::app);
		
		file <<client.getID()<<'|' << client.getName() << '|' << client.getPassword() << '|' << client.getBalance() << endl;
		file.close();
	}
	static void saveEmployee(Employee& employee)
	{
		
		fstream file("employees.txt", ios::app);
		file << employee.getID() << '|'<< employee.getName() << '|' << employee.getPassword() << '|' << employee.getSalary() << endl;
		file.close();
	}
	static void saveAdmin(Admin& admin)
	{
		
		
		fstream file("admins.txt", ios::app);
		file << admin.getID() << '|' << admin.getName() << '|' << admin.getPassword() << '|' << admin.getSalary() << endl;
		file.close();
	}

	static void getAllClients()
	{
		fstream clientFile;
		clientFile.open("clients.txt", ios::in);
		string line;
		while (getline(clientFile, line))
		{
			cout << line << endl;
		}
		clientFile.close();
	}
	static void getAllEmployees()
	{
		fstream employeeFile;
		employeeFile.open("employees.txt", ios::in);
		string line;
		while (getline(employeeFile, line))
		{
			cout << line << endl;
		}
		employeeFile.close();
	}
	static void getAllAdmins()
	{
		fstream adminFile;
		adminFile.open("admins.txt", ios::in);
		string line;
		while (getline(adminFile, line))
		{
			cout << line << endl;
		}
		adminFile.close();
	}

	static void clearFile(string fileName)
	{
		fstream file;

		file.open(fileName, std::ofstream::out | std::ofstream::trunc);
	}
};

