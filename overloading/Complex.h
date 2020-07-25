#pragma once
#include <iostream>
using namespace std;

class Complex {
public:
	explicit Complex(int , int);
	friend ostream& operator<< (ostream& stream, const Complex& other);
	bool operator==(const Complex& other);
private:
	double real, imaginary;

};