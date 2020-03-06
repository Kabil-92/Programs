#pragma once
#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include "subject.h"
using namespace std;

class jointBusinessAccount {
public:
	string branchName;
	double accountNo;
	int shareCount;
	std::map<int, string> myMap;
	double balance;
	double crossLimit;
	string logPath;
	fstream myFile;
	subject *mode;
	jointBusinessAccount(subject *buf);
	void setAccountDetails();
	void withdraw(int,int);
	void credit(int,int);
	void setLogPath(string);
	void getLogPath();
	void monitorCrossLimit();

};
jointBusinessAccount::jointBusinessAccount(subject *tmp)
{
	mode = tmp;
}
void jointBusinessAccount::setAccountDetails()
{
	cout << "enter the branch name,accountNo,shareCount,balance,crosslimit" << endl;
	cin >> branchName >> accountNo >> shareCount >> balance >> crossLimit;
	logPath = "D:\kabil_Projects\ConsoleApplication1\ConsoleApplication1\Activity.log";
	for (int i = 0; i < shareCount; i++)
	{
		string tmp;
		cout << "enter the share holder name" << endl;
		cin >> tmp;
		int j = i + 1;
		myMap.insert(std::pair<int,string>(j,tmp));
	}
	myFile.open(logPath);
	if (myFile)
	{
		cout << "file opened" << endl;
	}
	else
		cout << "file open error" << endl;
};

void  jointBusinessAccount::withdraw(int amount, int key)
{
	balance = balance - amount;
	std::map<int, string>::iterator it;
	it= myMap.find(key);
	myFile << it->second << "withdraw the amount " << amount << "current balance is " << balance;
	monitorCrossLimit();
	
}

void jointBusinessAccount::credit(int amount, int key)
{
	balance = balance + amount;
	std::map<int, string>::iterator it;
	it = myMap.find(key);
	myFile << it->second << "credited the amount " << amount << "current balance is " << balance;
		
}
void jointBusinessAccount::monitorCrossLimit()
{
	if (balance < crossLimit)
	{
		mode->setLimitOverflowFlag();
	}
}