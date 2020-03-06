#pragma once

#include<iostream>
#include "Subject.h"
using namespace std;

class Observer
{
	subject *mode1;
public:
	observer(subject *buf1)
	{
		mode1 = buf1;
		mode1->attach(this);
	};
	virtual void update() = 0;
};

