#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include"FileManager.h"
#include "Screen.h"
using namespace std;


int main()
{
	system("color f0");
	
	
	Client c("dcfgvhbn", "sxdrctfvgybuhnj", 15, 74236);
	

	Employee emp("sdfghjkl","753.12220",7,457892);
	
	
	vector<string>tempp = emp.searchClient();
	
	for (int i = 0; i < tempp.size(); i++)
	{
		cout << tempp[i];
	}
	
	

	//employee.addClient(client);

	
	
	/*vector<string> temp = m.getAllClients();
	for (int i = 0; i < temp1.size(); i++)
	{
		cout << temp1[i] << endl;;

	}*/

	//Screen::welcomeScreen();
	/*Screen::login_or_signup();
	*/

}

