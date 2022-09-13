#include <string>
#include "Validation.h"
using namespace std;

class Person
{
	Validation validate;
protected:
	int id;
	string name, password;
	double balance , salary;

public:
	//constructor
	Person()
	{
		id = 0;
		name = "";
		password = "";
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
		if (validate.checkName(name))
			Person::name = name;

	}
	void setPassword(string password)
	{
		if (validate.checkPassword(password))
			Person::password = password;
	}
	void setBalance(double balance)
	{
		if(validate.checkBalance(balance))
		Person::balance = balance;
	}
	void setSalary(double salary)
	{
		if (validate.checkSalary(salary))
			Person::salary = salary;
	}
	//getters
	int getId() { return id; }
	string getName() { return name; }
	string getPassword() { return password; }
	double getBalance() { return balance; }
	double getSalary() { return salary; }

	//disply method

	void display()
	{
		cout << "ID: " << id << endl;
		cout << "Name: " << name << endl;
		cout << "Password: " << password << endl;
		cout << "Balance: " << balance << endl;
	}

};

