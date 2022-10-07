#pragma once
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
#include <vector>

class DataSourceInterface
{
	virtual vector < string >getAllClients()=0;
	virtual vector<string>getAllEmployees()=0;
	virtual vector<string>getAllAdmins()=0;

	virtual void addClient(Client& client) = 0;
	virtual void addEmployee(Employee& employee) = 0;
	virtual void addAdmin(Admin& admin) = 0;

	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;



};

