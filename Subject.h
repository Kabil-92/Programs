#pragma once
#include <iostream>
#include <vector>
#include "ObserverBase.h"
using namespace std;

class subject {
	vector<class observer*> observerList;
	bool limitOverflowFlag;
public:
	subject();
	void attach(observer *);
	//void detach(observer *);
	void notify();
	void setLimitOverflowFlag();
};

subject::subject()
{
	limitOverflowFlag = false;
}

void subject::attach(observer *a)
{
	observerList.push_back(a);
}

void subject::setLimitOverflowFlag()
{
	limitOverflowFlag = true;
	notify();
}

void subject::notify()
{
	for (int i = 0; i < observerList.size(); i++)
	{
		observerList[i]->update();
	}
}