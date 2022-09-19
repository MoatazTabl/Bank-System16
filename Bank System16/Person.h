#pragma once
#include <string>
#include<iostream>
#include "Validation.h"
using namespace std;


class Person
{
	
protected:
	int id;
	string name, password;
	double balance , salary;

public:
	//constructor
	Person()
	{
		id = 0;
		name = "No Name";
		password = "00000000";
		balance = 0;
		salary = 0;
	}
	
	//Setters
	void setId(int id)
	{
		Person::id = id;
	}
	void setName(string name)
	{
		if (Validation::checkName(name))
			Person::name = name;

	}
	void setPassword(string password)
	{
		if (Validation::checkPassword(password))
			Person::password = password;
	}
	void setBalance(double balance)
	{
		if(Validation::checkBalance(balance))
		Person::balance = balance;
	}
	void setSalary(double salary)
	{
		if (Validation::checkSalary(salary))
			Person::salary = salary;
	}
	//getters
	int getId() { return id; }
	string getName() { return name; }
	string getPassword() { return password; }
	double getBalance() { return balance; }
	double getSalary() { return salary; }

	//disply method

	virtual void display() = 0;
	

};

