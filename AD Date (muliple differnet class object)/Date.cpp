//  Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date( int mn, int dy, int yr, Time time ):t(time)
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
  // cout << "Date object constructor for date ";
  // print();                   
   cout << endl;
} // end Date constructor

// print Date object in form month/day/year
void Date::print() const
{
   cout << month << '/' << day << '/' << year; 
} // end function print

void Date::increaseADay()
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

void Date::tick()
{
	if (t.getSecond() + 1 < 60)
	{
		t.setSecond(t.getSecond() + 1);
	}
	else if  (t.getSecond() + 1 == 60)
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

void Date::setDay(int dy)
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

void Date::setMonth(int mn)
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

void Date::setYear(int yr)
{
	if (yr < 1920 || yr>2020)
	{
		cout << "invalid year and set to 2011\n";
		year = 2011;
	}
	else year = yr;
}

// output Date object to show when its destructor is called
Date::~Date()
{ 
  // cout << "Date object destructor for date ";
  // print();
   cout << endl;
} // end ~Date destructor

// utility function to confirm proper day value based on 
// month and year; handles leap years, too
unsigned int Date::checkDay( int testDay ) const
{
   static const array< int, monthsPerYear + 1 > daysPerMonth = 
      { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

   // determine whether testDay is valid for specified month
   if ( testDay > 0 && testDay <= daysPerMonth[ month ] )
      return testDay;

   // February 29 check for leap year 
   if ( month == 2 && testDay == 29 && ( year % 400 == 0 || 
      ( year % 4 == 0 && year % 100 != 0 ) ) )
      return testDay;

  // throw invalid_argument( "Invalid day for current month and year" );
   return 0;
} // end function checkDay
