#include <iostream>
using namespace std;
#include "Employee.h"

Employee::Employee(string fname, string lname, int sali)
	:first(fname),last(lname),sal(sali)
{
	if (sal <= 0) {

		cout << "XX Employee: " << first << last << "'s inputted monthly salary was " << sal << endl;
		sal = 1000;
		cout << "The monethly salary adjusted to " << sal << endl;
	}
	//empty constructor
}

int Employee::getMonthlySalary() const
{
	return sal;
}

string Employee::getFirstName()
{
	return first;
}

string Employee::getLastName()
{
	return last;
}

void Employee::increaseMonthlySalary(double amount)
{
	cout << "---Employee: " << first << last << " has a salary adjustment of " << amount << "%\n";
	cout << "The original monthly salary is $" << sal<<endl;
	sal= sal* (1 + amount / 100);
	cout << "The adjusted salary is " << sal << endl;;
}

