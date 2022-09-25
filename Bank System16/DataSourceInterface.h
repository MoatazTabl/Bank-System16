#pragma once
#include "Client.h"
#include "Admin.h"
#include "Employee.h"
class DataSourceInterface
{
	virtual void addClient(Client) = 0;
	virtual void addEmployee(Client) = 0;
	virtual void addAdmin(Admin) = 0;

	virtual void removeAllClients() = 0;
	virtual void removeAllEmployees() = 0;
	virtual void removeAllAdmins() = 0;



};

