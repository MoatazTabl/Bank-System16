#include <iostream>
#include <string>
#include "Client.h"
#include "Employee.h"

#include"FileHelper.h"
#include"FileManager.h"
#include "Screen.h"

using namespace std;


int main()
{
	system("color f0");
	
	unique_ptr<Employee>e(new Employee(123, "fdafdad", "afasfasfasfaf",12344.5));

	unique_ptr<Client>c1(new Client(5, "drctfvgh", "xrdcfgvhbj", 456789));

	unique_ptr<Admin> a(new Admin(12, "fsaddas", "asddaddas", 123123));

	a->editEmployee(123,"Moataz","123456789",70000);
	
	//e.addClient(*c1);
	
	

	
	
	
	

	//Screen::welcomeScreen();
	/*Screen::login_or_signup();
	*/

}

