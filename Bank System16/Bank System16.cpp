#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"

#include "Screen.h"

using namespace std;


int main()
{
	system("color f0");
	
	Employee e(123, "fdafdad", "afasfasfasfaf",12344.5);
	Client c1(123,"drctfvgh","xrdcfgvhbj",456789);
	
	e.listClient();

	

	/*vector<string> words=Parser::split(line);

	for (int i = 0; i < words.size(); i++)
	{
		cout << words[i];
	}*/
	
	
	/*

	
	
	vector<string> temp1 = m.getAllClients();
	for (int i = 0; i < temp1.size(); i++)
	{
		cout << temp1[i] << endl;;

	}*/

	//Screen::welcomeScreen();
	/*Screen::login_or_signup();
	*/

}

