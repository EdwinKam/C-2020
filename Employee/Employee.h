#pragma once
#include <string>
using namespace std;

class Employee
{
public: 
	explicit Employee(string, string, int);
	int getMonthlySalary() const;
	string getFirstName();
	string getLastName();
	void increaseMonthlySalary(double);
private:
	string first, last;
	int sal;


};