#pragma once
#include"EmployeeManager.h"
class AdminManager :public EmployeeManager
{
	static void printAdminMenu()
	{
		EmployeeManager::printEmployeeMenu();
		cout << "5-Edit Employee\n";

	}
	

};

