#pragma once

#include<iostream>

#include<vector>
#include<string>
#include<sstream>
#include<memory>

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
		unique_ptr<Client>c(new Client(stoi(info[0]), info[1], info[2], stod(info[3])));
		//Client c(stoi(info[0]), info[1],info[2], stod(info[3]));
		return c;
	}

	
};


