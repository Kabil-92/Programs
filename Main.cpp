#include <iostream>
#include "Subject.h"
#include "AccountShare1.h"
#include "AccountShare2.h"
#include "JointBusinessAccount.h"

using namespace std;

int main()
{
	subject sub;
	string tmp;
	cout << "enter the first share person name" << endl;
	cin >> tmp;
	accountShare1 sh1(&sub, tmp);
	tmp.clear();
	cout << "enter the first share person 2 name" << endl;
	cin >> tmp;
	accountShare2 sh2(&sub, tmp);

	jointBusinessAccount jba(&sub);
	jba.setAccountDetails();
	int option;
	double amount;
	while (1)
	{
		cout << "enter the option 1 -> credit, 2->withdraw " << endl <<"enter the amount also";
		cin >> option >> amount;
		switch (option)
		{
		case 1:
			jba.credit(amount);
			break;
		case 2:
			jba.withdraw(amount);
			break;
		default:
			cout << "invalid option";
		}
			
	}
}