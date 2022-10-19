#pragma once
#pragma message("Top in: " __FILE__)
#include <iostream>
#include<Windows.h>
#include <cstdio>
#include"ClientManger.h"
#include"EmployeeManager.h"
#include"AdminManager.h"
#pragma message("Before class in: " __FILE__)
using namespace std;
class Screens
{
public:
	static void bankName()
	{
		cout << "\t\t\t\tBank System 16";
		Sleep(3000);
		system("cls");
		welcome();
	}

	static void welcome()
	{
		cout << "Hello user!";
		Sleep(3000);
		system("cls");
		loginOptions();
	}

	static void loginOptions()
	{
		cout << "1-Client\n";
		cout << "2-Employee\n";
		cout << "3-Admin\n";
		cout << "4-exit\n\n";
		
		loginAs();
	}

	static int loginAs()
	{
		
		string password;
		int user_choice,id;
		cout << "Login As: ";
		cin >> user_choice;
		if (user_choice <= 0 || user_choice > 4)
		{
			invalid(user_choice);
			loginOptions();
		}
		switch (user_choice)
		{
		
		case (1):
			system("cls");
			
			clientLogin();
			

			break;

		case (2):
			system("cls");
			
			employeeLogin();
			break;

		case (3):
			system("cls");
			
			
			adminLogin();
			break;

		case (4):
			exit(1);
			break;
		}
		


		return 1;
	}

	static void clientLogin()
	{
		unique_ptr<Client>c1 = nullptr;
		int id;
		string password;

		while (c1 == nullptr)
		{
			cout << "Enter ID: ";
			cin >> id;

			if (id <= 0)
			{
				
				cout << "Enter a valid ID";
				Sleep(1750);
				system("cls");
				clientLogin();
			}

			cout << "\nEnter Password: ";
			cin >> password;
			c1 = ClientManger::login(id, password);
			if (c1 == nullptr)
			{
				Sleep(2000);
				system("cls");
			}
		}

		clientOptions(c1);
	}

	static void clientOptions(unique_ptr<Client>& client)
	{
		system("cls");
		ClientManger::printClientMenu();
		int user_choice;
		int amount;
		int id;
		double balance;
		string password,name;
		unique_ptr<Client>c1 =nullptr;

		cout << "\nWhat do you want to do: ";
		cin >> user_choice;

		
		switch (user_choice)
		{
		case 1:
			system("cls");
			client->checkBalance();
			system("pause");
			clientOptions(client);
			break;
		case 2:
			system("cls");
			
			cout << "Enter how much you want to depoist: ";
			cin >> amount;
			client->deposite(amount);
			
			clientOptions(client);
			break;
		case 3:
			system("cls");
			
			cout << "Enter how much you want to withdraw: ";
			cin >> amount;
			client->withdraw(amount);
			cout << "\nDone!";
			clientOptions(client);
			break;
		case 4:
			system("cls");
			
			cout << "Enter how much you want to transfer: ";
			cin >> amount;
			cout << "---------------------------------------------------------\n";

			while (c1 == nullptr)
			{
				cout << "Enter ID: ";
				cin >> id;

				if (id <= 0)
				{

					cout << "Enter a valid ID";
					Sleep(1750);
					system("cls");
					clientLogin();
				}

				cout << "\nEnter Password: ";
				cin >> password;
				c1 = ClientManger::login(id, password);
				if (c1 == nullptr)
				{
					Sleep(2000);
					system("cls");
				}
			}

			client->transferTo(amount, *c1);
			cout << "Done";
			Employee::editClient(c1->getID(), c1->getName(), c1->getPassword(), c1->getBalance());
			Sleep(2000);
			clientOptions(client);
			break;
		case 5:
			system("cls");
			
			ClientManger::updatePassword(client);
			Sleep(1750);
			clientOptions(client);
		case 6:
			logout();
		}	
	}

	static void employeeLogin()
	{
		unique_ptr<Employee>e1 = nullptr;
		int id;
		string password;

		while (e1 == nullptr)
		{
			cout << "Enter ID: ";
			cin >> id;

			if (id <= 0)
			{

				cout << "Enter a valid ID";
				Sleep(1750);
				system("cls");
				employeeLogin();
			}

			cout << "\nEnter Password: ";
			cin >> password;
			e1 = EmployeeManager::loginAsEmployee(id, password);
			if (e1 == nullptr)
			{
				Sleep(2000);
				system("cls");
			}
		}

		employeeOptions(e1);
	}

	static void employeeOptions(unique_ptr<Employee>& employee)
	{
		

		system("cls");
		EmployeeManager::printEmployeeMenu();
		int user_choice;

		cout << "\nWhat do you want to do: ";
		cin >> user_choice;

		int id;
		string name, password;
		double balance;
		
		unique_ptr<Client>c1(new Client(1,"Moataz","12345678",2312231));
		unique_ptr<Client>c2(new Client(1, "123213", "2313123321", 123132));
		switch (user_choice)
		{
		case 1:
			system("cls");
			

			cout << "ID: ";
			cin >> id;
			cout << "Name: ";
			cin >> name;
			cout << "Password: ";
			cin >> password;
			cout << "Balance: ";
			cin >> balance;

			c1->setName(name);
			c1->setBalance(balance);
			c1->setID(id);
			c1->setPassword(password);
			

			EmployeeManager::newClient(c1);
			
			employeeOptions(employee);
			break;
		case 2:
			system("cls");

			cout << "ID: ";
			cin >> id;
			cout << "Name: ";
			cin >> name;
		
			c1->setName(name);
			c1->setID(id);
			system("cls");
			
			EmployeeManager::searchForClient(c1);
			int back;
			cout << "Enter \"1\" to get to the pervious menu: ";
			cin >> back;
			if (back==1)
			{
				employeeOptions(employee);
			}
			
			break;
		case 3:
			EmployeeManager::listAllClients();
			cout << "Enter \"1\" to get to the pervious menu: ";
			cin >> back;
			if (back == 1)
			{
				employeeOptions(employee);
			}
		case 4:
			cout << "ID: ";
			cin >> id;
			c1->setID(id);
			cout << "Name: ";
			cin >> name;
			c1->setName(name);
			cout << "Password: ";
			cin >> password;
			c1->setPassword(password);
			cout << "Balance: ";
			cin >> balance;
			c1->setPassword(password);

			Employee::editClient(id, name, password, balance);
		case 5:
			logout();

		}

	}

	static void adminLogin()
	{
		unique_ptr<Admin>a1 = nullptr;
		int id;
		string password;

		while (a1 == nullptr)
		{
			cout << "Enter ID: ";
			cin >> id;

			if (id <= 0)
			{

				cout << "Enter a valid ID";
				Sleep(1750);
				system("cls");
				adminLogin();
			}

			cout << "\nEnter Password: ";
			cin >> password;
			a1 = AdminManager::loginAsAdmin(id, password);
			if (a1 == nullptr)
			{
				Sleep(2000);
				system("cls");
			}
		}

		adminOptions(a1);
	}

	static void adminOptions(unique_ptr<Admin>& admin)
	{

		system("cls");
		AdminManager::printAdminMenu();
		cout << "6-Exit";
		int user_choice;

		cout << "\nWhat do you want to do: ";
		cin >> user_choice;

		int id;
		string name, password;
		double balance;

		unique_ptr<Client>c1(new Client(1, "Moataz", "12345678", 2312231));
		unique_ptr<Client>c2(new Client(1, "123213", "2313123321", 123132));
		switch (user_choice)
		{
		case 1:
			system("cls");


			cout << "ID: ";
			cin >> id;
			cout << "Name: ";
			cin >> name;
			cout << "Password: ";
			cin >> password;
			cout << "Balance: ";
			cin >> balance;

			c1->setName(name);
			c1->setBalance(balance);
			c1->setID(id);
			c1->setPassword(password);


			AdminManager::newClient(c1);

			adminOptions(admin);
			break;
		case 2:
			system("cls");

			cout << "ID: ";
			cin >> id;
			cout << "Name: ";
			cin >> name;

			c1->setName(name);
			c1->setID(id);
			system("cls");

			EmployeeManager::searchForClient(c1);
			int back;
			cout << "Enter \"1\" to get to the pervious menu: ";
			cin >> back;
			if (back == 1)
			{
				adminOptions(admin);
			}

			break;
		case 3:
			system("cls");
			EmployeeManager::listAllClients();
			cout << "Enter \"1\" to get to the pervious menu: ";
			cin >> back;
			if (back == 1)
			{
				adminOptions(admin);
			}
			break;
		case 4:
			system("cls");
			cout << "ID: ";
			cin >> id;
			c1->setID(id);
			cout << "Name: ";
			cin >> name;
			c1->setName(name);
			cout << "Password: ";
			cin >> password;
			c1->setPassword(password);
			cout << "Balance: ";
			cin >> balance;
			c1->setPassword(password);

			Admin::editClient(id, name, password, balance);
			adminOptions(admin);
			break;
		case 5:
			system("cls");
			cout << "ID: ";
			cin >> id;
			c1->setID(id);
			cout << "Name: ";
			cin >> name;
			c1->setName(name);
			cout << "Password: ";
			cin >> password;
			c1->setPassword(password);
			cout << "Balance: ";
			cin >> balance;
			c1->setPassword(password);

			Admin::editEmployee(id, name, password, balance);
			adminOptions(admin);
			break;
		case 6:
			logout();
			break;
		}

	}

	static void invalid(int user_choice)
	{
		
			cout << "Please enter a right choice\n";
			cout << "Restarting.\n";
			Sleep(2000);
			system("cls");
			
		
	}

	static void logout()
	{
		system("cls");
		loginOptions();
	}

	static void runApp()
	{
		bankName();
	}
};

