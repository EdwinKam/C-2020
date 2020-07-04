// Date.cpp
// Date class member-function definitions.
#include <array>
#include <iostream>
#include <stdexcept>
#include "Date.h" // include Date class definition
#include "Time.h" // include Date class definition
using namespace std;

// constructor confirms proper value for month; calls
// utility function checkDay to confirm proper value for day
Date::Date(int mn, int dy, int yr, Time time) :t(time)
{
   if ( mn > 0 && mn <= monthsPerYear ) // validate the month
      month = mn;
   else 
      throw invalid_argument( "month must be 1-12" );

   year = yr; // could validate yr
   day = checkDay( dy ); // validate the day

   // output Date object to show when its constructor is called
   cout << "Date object constructor for date ";
   print();   
  // t.~time();
   cout << endl;
   //cout << "hh" << t.getSecond() << endl;
  // t.setSecond(t.getSecond() + 1);
   //cout << "ph" << t.getSecond() << endl;
} // end Date constructor



// print Date object in form month/day/year
void Date::print() 
{
	cout << month << '/' << day << '/' << year << "\t";
	
	t.printStandard();
	
	t.printUniversal();
} // end function print; 

// output Date object to show when its destructor is called
Date::~Date()
{ 
   cout << "Date object destructor for date ";
   print();
   cout << endl;
} // end ~Date destructor

void Date::tick()
{
	
	if (t.getSecond() == 59) 
	{
		t.setSecond(0);
		if (t.getMinute() == 59)
		{
			t.setMinute(0);
			if (t.getHour() == 23)
			{
				t.setHour(0);
				increaseADay();
			}
			else
			t.setHour(t.getHour()+1);
		}
		else
		t.setMinute(t.getMinute()+1);
	}
	else
	t.setSecond(t.getSecond() + 1);
}

void Date::increaseADay()
{
	if (checkDay(day + 1) == 32)
	{
		day = 1;
		if (month == 12)
		{
			month = 1;
			year++;
		}
		else {
			month++;
			year++;
		}
	}
	else
		day++;
}
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

   return 32;
} // end function checkDay