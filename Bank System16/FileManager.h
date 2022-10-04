#pragma once
#include "DataSourceInterface.h"
#include <fstream>
#include <string>


class FileManager : public DataSourceInterface
{
private:
	vector <Client> clientVector;
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
		clientFile << client.getID() <<" " << client.getName()<<" " << client.getPassword() << " " << client.getBalance() << endl;
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
		employeeFile << employee.getID() << " " << employee.getName() << " " << employee.getPassword() << " " << employee.getBalance() << endl;
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
		adminFile << admin.getID() << " " << admin.getName() << " " << admin.getPassword() << " " << admin.getBalance() << endl;
		adminFile.close();
	}

	/*vector < Client >getAllClients()
	{

	}*/
	
};

