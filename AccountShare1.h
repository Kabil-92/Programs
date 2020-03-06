#pragma once
#include<iostream>
#include<string>
#include"Subject.h"
#include "ObserverBase.h"
using namespace std;
//class forward subject;
class accountShare1 : public Observer {
	string name;
public:
	accountShare1(class subject *x, string y):Observer(x)
	{
	}
	void update();

	
};

void accountShare1::update()
{
	cout << "cross limit update to share person name::" << name << endl;
}