#pragma once
#pragma message("Top in: " __FILE__)
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

#include <vector>
#pragma message("Before class in: " __FILE__)
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

