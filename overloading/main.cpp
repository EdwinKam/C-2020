#include <iostream>
#include "Date.h"
#include "Complex.h"
#include <string>

using namespace std;
template<typename T>
void isEqualTo(T a, T b)
{
	if (a == b)
		cout << a << " and " << b << " are equal\n";
	else
		cout << a << " and " << b << " are NOT equal\n";
}

int main() {
	cout << "**** int test ****\n";
	cout << "Int: ";
	isEqualTo(1, 1);
	cout << "Int: ";
	isEqualTo(2, 4);
	cout << "Int: ";
	isEqualTo(-1, 1);
	cout << "Int: ";
	isEqualTo(-1, -1);
	cout << endl;

	cout << "****char test ****\n";
	cout << "Char: ";
	isEqualTo('a', 'a');
	cout << "Char: ";
	isEqualTo('a', 'c');
	cout << "Char: ";
	isEqualTo('c', 'a');
	cout << "Char: ";
	isEqualTo('c', 'c');
	cout << endl;

	cout << "**** double test ****\n";
	cout << "Double: ";
	isEqualTo(2.2, 2.2);
	cout << "Double: ";
	isEqualTo(2.2, 2.3);
	cout << "Double: ";
	isEqualTo(-2.2, 2.2);
	cout << "Double: ";
	isEqualTo(-2.2, -2.2);
	cout << endl;

	cout << "**** Date test ****\n";
	Date a1(2, 31, 2017);
	Date a2(2, 31, 2017);
	Date b1(2, 13, 2017);
	Date b2(2, 14, 2017);
	Date c1(-2, 13, 2017);
	Date c2(2, 13, 2017);
	Date d1(-2, 13, 2017);
	Date d2(-2, 13, 2017);

	cout << "Date: ";
	isEqualTo(a1, a2);
	cout << "Date: ";
	isEqualTo(b1, b2);
	cout << "Date: ";
	isEqualTo(c1, c2);
	cout << "Date: ";
	isEqualTo(d1, d2);

	cout << endl;
	cout << "**** Complex test ****\n";
	Complex e1(10,5);
	Complex e2(10, 5);
	Complex f1(10, 5);
	Complex f2(10, 54);
	Complex g1(10, -5);
	Complex g2(10, 5);
	Complex h1(-10, -5);
	Complex h2(-10, -5);

	cout << "Date: ";
	isEqualTo(e1, e2);
	cout << "Date: ";
	isEqualTo(f1, f2);
	cout << "Date: ";
	isEqualTo(g1, g2);
	cout << "Date: ";
	isEqualTo(h1, h2);

	cout << endl;






}