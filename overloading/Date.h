#pragma once
using namespace std;
#include <iostream>
class Date {
public: 
	explicit Date(int, int, int);
	friend ostream& operator<< (ostream& stream, const Date& other);
	bool operator== (const Date&);
private:
	int month, day, year;

};