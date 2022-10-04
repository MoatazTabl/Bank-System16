#include <iostream>

#include <string>
#include<fstream>
#include<windows.h>
#include "Client.h"
#include "Employee.h"
#include "Admin.h"
#include "Screen.h"
using namespace std;


int main()
{
	system("color f0");

	

	
	Client* client = nullptr;
	Employee* employee = nullptr;
	Admin* admin = nullptr;

	//Screen::welcomeScreen();

	

	
	Screen::login_or_signup();

	
	

	string* ptr=Screen::clientLogin();

	cout << *(ptr+1);

}

