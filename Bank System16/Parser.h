#pragma once
#pragma message("Top in: " __FILE__)
#include<iostream>

#include<vector>
#include<string>
#include<sstream>
#include<memory>

#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#pragma message("Before class in: " __FILE__)
using namespace std;


class Parser
{


public:

	static vector<string> split(string line,int whichIndex=0)
	{
		stringstream s(line);
		string lineWords;
		vector<string> splitWords;
		vector<string>splitNums;
		if (whichIndex==0)
		{
			while (getline(s, lineWords, '|'))
			{
				splitWords.push_back(lineWords);
			}
			return splitWords;
		}
		else if (whichIndex==1)
		{
		
			string firstWord1;

			while (getline(s, lineWords))
			{
				firstWord1 = lineWords.substr(0, lineWords.find('|'));


				splitNums.push_back(firstWord1);
				
			}
			return splitNums;
		}
		
	}

	static unique_ptr<Client> parseToClient(string line)
	{
		vector <string> info = split(line);
		unique_ptr<Client>client(new Client(stoi(info[0]), info[1], info[2], stod(info[3])));
		//Client c(stoi(info[0]), info[1],info[2], stod(info[3]));
		return client;
	}
	static unique_ptr<Employee> parseToEmployee(string line)
	{
		vector <string> info = split(line);
		unique_ptr<Employee>emp(new Employee(stoi(info[0]), info[1], info[2], stod(info[3])));
		
		return emp;
	}
	static unique_ptr<Admin> parseToAdmin(string line)
	{
		vector <string> info = split(line);
		unique_ptr<Admin>admin(new Admin(stoi(info[0]), info[1], info[2], stod(info[3])));
		
		return admin;
	}

	
};


