#include<iostream>
#include "Complex.h"
using namespace std;

int main() {
	Complex x;
	Complex y(4.3, 8.2);
	Complex z(3.3, 1.1);
	Complex k, l;
	Complex m(0, 0.1);
	cin >> k;
	cout << k;
	x = y + z;
	cout << "\nx = y + z:\n" << x << "=" << y << "+" << z << '\n';
	x = y - z;
	cout << "\nx = y - z:\n" << x << "=" << y << "-" << z << '\n';
	x = y * z;
	cout << "\nx = y * z:\n" << x << "=" << y << "*" << z << '\n';
	x = y / z;
	cout << "\nx = y / z:\n" << x << "=" << y << "/" << z << '\n';
	x = y / l;
	cout << "\nx = y / l:\n" << x << "=" << y << "/" << l << '\n';
	x = y / m;
	cout << "\nx = y / m:\n" << x << "=" << y << "/" << m << '\n';
	cout << "Check x!=k" << endl << endl;;
	if (x != k) {
		cout << x << "!=" << k << endl << endl;
	}
	cout << "Check x==k" << endl;
	x = k;
	//cout << "Check x==k" << endl;
	if (x == k) {
		cout << x << "==" << k << endl;

	}
}