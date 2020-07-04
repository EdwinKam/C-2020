#include <iostream>
#include "DateTime.h" // Employee class definition
//#include "Date.h" // Date class definition
//#include "Employee.h" // Employee class definition
#include <iomanip>
#include <stdexcept>
#include <array>
using namespace std;

DateTime::DateTime(int mn, int dy, int yr, Time time):month(mn),day(dy),year(yr),t(time)
{
	
}

void DateTime::print() const
{
	cout << month << '/' << day << '/' << year; 
	cout << setfill('0') << setw(2) << t.getHour() << ":"
	<< setw(2) << t.getMinute() << ":" << setw(2) << t.getSecond() << "\t";
}

void DateTime::increaseADay()
{
	day++;
	if (checkDay(day) == 0)
	{
		day = 1;
		month++;
		if (month > 12)
		{
			month = 0;
			year++;
		}
	}
}

void DateTime::tick()
{
	if (t.getSecond() + 1 < 60)
	{
		t.setSecond(t.getSecond() + 1);
	}
	else if (t.getSecond() + 1 == 60)
	{
		t.setSecond(0);
		if (t.getHour() + 1 < 24)
		{
			t.setHour(t.getHour() + 1);

		}
		else
		{
			t.setHour(0);
			increaseADay();
		}
	}

}

int DateTime::getMonth() const
{
	return month;
}

int DateTime::getYear() const
{
	return year;
}

int DateTime::getDay() const
{
	return day;
}
void DateTime::setDay(int dy)
{
	if (checkDay(dy) != 0)
	{
		day = dy;
	}
	else {
		cout << "set day to 1";
		day = 1;
	}
}

int DateTime::getHour() const
{
	return t.getHour();
}

int DateTime::getMinute() const
{
	return t.getMinute();
}

int DateTime::getSecond() const
{
	return t.getSecond();
}

void DateTime::setHour(int h)
{
	t.setHour(h);
} // end function setHour

// set minute value
void  DateTime::setMinute(int m)
{
	t.setMinute(m);
} // end function setMinute

DateTime::~DateTime()
{
	//cout << "DateTime destructor called\n";
}

// set second value
void  DateTime::setSecond(int s)
{
	t.setSecond(s);
} // end function setSecond

void DateTime::setMonth(int mn)
{
	if (mn < 13)
	{
		month = mn;
	}
	else {
		cout << "set month to 1";
		month = 1;
	}
}

void DateTime::setYear(int yr)
{
	if (yr < 1920 || yr>2020)
	{
		cout << "invalid year and set to 2011\n";
		year = 2011;
	}
	else year = yr;
}
unsigned int DateTime::checkDay(int testDay) const
{
	static const array< int, monthsPerYear + 1 > daysPerMonth =
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	// determine whether testDay is valid for specified month
	if (testDay > 0 && testDay <= daysPerMonth[month])
		return testDay;

	// February 29 check for leap year 
	if (month == 2 && testDay == 29 && (year % 400 == 0 ||
		(year % 4 == 0 && year % 100 != 0)))
		return testDay;

	// throw invalid_argument( "Invalid day for current month and year" );
	return 0;
} // end function checkDay