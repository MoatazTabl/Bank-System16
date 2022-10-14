#pragma once

#ifndef _File1
#define _File1

#include"Admin.h"
#include "DataSourceInterface.h"
#include <fstream>
#include <string>


class FileManager : public DataSourceInterface
{
private:
	vector <string> clientVector;
	vector <string>employeeVector;
	vector <string>adminVector;
public:
	fstream clientFile;
	fstream employeeFile;
	fstream adminFile;
	
	void addClient(Client& client)
	{
		
		try
		{
			clientFile.open("clients.txt",ios::app);
		}
		catch (const std::exception&)
		{
			clientFile.open("clients.txt");

		}
		clientFile << client.getID() <<"|" << client.getName()<<"|" << client.getPassword() <<"|" << client.getBalance() << endl;
		clientFile.close();
	}
	
	void addEmployee(Employee& employee)
	{
		
		try
		{
			employeeFile.open("employees.txt",ios::app);
		}
		catch (const std::exception&)
		{
			employeeFile.open("employees.txt");
		}
		employeeFile << employee.getID() << "|" << employee.getName() << "|" << employee.getPassword() <<"|" << employee.getSalary()<< endl;
		employeeFile.close();
	}

	void addAdmin(Admin& admin)
	{
		
		try
		{
			adminFile.open("admins.txt",ios::app);
		}
		catch (const std::exception&)
		{
			adminFile.open("admins.txt");
		}
		adminFile << admin.getID() << "|" << admin.getName() << "|" << admin.getPassword() << "|"<<admin.getSalary() << endl;
		adminFile.close();
	}

	vector <string> getAllClients()
	{
		clientFile.open("clients.txt", ios::in);  
		if (clientFile.is_open())
		{
			string temp;
			while (getline(clientFile, temp))
			{
				clientVector.push_back(temp);
			}
		}
		clientFile.close(); 

		return clientVector;
	}
	vector<string>getAllEmployees()
	{
		employeeFile.open("employees.txt", ios::in);
		if (employeeFile.is_open())
		{
			string temp;
			while (getline(employeeFile, temp))
			{
				employeeVector.push_back(temp);
			}
		}
		employeeFile.close();

		return employeeVector;
	}
	vector<string>getAllAdmins()
	{
		adminFile.open("admins.txt", ios::in);
		if (adminFile.is_open())
		{
			string temp;
			while (getline(adminFile,temp))
			{
				adminVector.push_back(temp);
			}
		}
		adminFile.close();
		return adminVector;

	}

	void removeAllClients()
	{
		clientFile.open("clients.txt", std::ofstream::out | std::ofstream::trunc);
		clientFile.close();
	}
	void removeAllEmployees()
	{
		employeeFile.open("employees.txt", std::ofstream::out | std::ofstream::trunc);
		employeeFile.close();
	}
	void removeAllAdmins()
	{
		adminFile.open("admins.txt", std::ofstream::out | std::ofstream::trunc);
		adminFile.close();
	}
	
};

#endif // !
