#include "Date.h"
#include <iostream>
#include <array>
using namespace std;
Date::Date(int mn, int dy, int yr):month(mn),day(dy),year(yr)
{
	//cout << dy;
	if (mn > 0 && mn < 13) {
		month = mn;
	}
	else
		month = 1;
	static const array< int, 12 + 1 > daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (dy > 0 && dy <= daysPerMonth[month]) {
		day = dy;
	}

	// February 29 check for leap year 
	else if (month == 2 && dy == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		day== dy;
	else {
		day = 1;
	}
	

}

bool Date::operator==(const Date& other)
{
	if (month == other.month && day == other.day && year == other.year)
		return true;
	else return false;
}

ostream& operator<<(ostream& stream, const Date& other)
{
	try {
		string monthname[19] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
		stream << monthname[other.month - 1] << " " << other.day << ", " << other.year;
	}
	catch (exception e) {
		cout << other.month - 1;
	}
	return stream;
}
