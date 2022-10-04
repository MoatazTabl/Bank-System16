#include <iostream>
#include<string>
#include <algorithm>
#include <cctype>
#include "Validation.h"
using namespace std;
#pragma once
class Screen
{
public:
	static void welcomeScreen()
	{
		cout << "Welcome!";
		Sleep(5000);
		system("cls");
	}

	static void login_or_signup()
	{
		string login_or_signup;
		cout << "Type \"Login\" for Login or \"Signup\" for Signup\n";
		cin >> login_or_signup;


		transform(login_or_signup.begin(), login_or_signup.end(), login_or_signup.begin(),
			[](unsigned char c) { return std::tolower(c); });

		if (login_or_signup == "login")
		{
			system("cls");
			Screen::Login();
		}
		else if (login_or_signup == "signup")
		{
			system("cls");

		}
		else
		{
			cout << "please choose correctly";
		}
	}

	static void Login()
	{
		int userChoice;

		cout << "1-Client\n";
		cout << "2-Employee\n";
		cout << "3-Admin\n";
		cout << "Enter 1,2,3: ";
		cin >> userChoice;

		if (Validation::UserChoiceLogin(userChoice)==false)
		{
			Login();
		}

		switch (userChoice)
		{
		default:
			break;
		case(1):
			clientLogin();
		}
	}

	static string* clientLogin()
	{
		system("cls");
		string name, password;
		static string arr[2];

		cout << "Enter Name: ";
		cin >> name;
		cout << "\nEnter Password: ";
		cin >> password;

		arr[0] = name;
		arr[1] = password;

		return arr;
	}



	static void clientScreen()
	{
		system("cls");
		cout << "1-Check Balance\n";
		cout << "2-Depoist from account\n";
		cout << "3-Withdraw from account\n";

	}

};

