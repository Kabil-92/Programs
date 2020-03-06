#pragma once

#pragma once
#include<iostream>
#include<string>
#include"Subject.h"
#include "ObserverBase.h"
using namespace std;

class accountShare2 : public Observer {
	string name;
public:
	accountShare2(class subject *x1, string y1):Observer(x1)
	{
		
		//name = y1;
	}
	void update();


};

void accountShare2::update()
{
	cout << "cross limit update to share person name::" << name << endl;
}
