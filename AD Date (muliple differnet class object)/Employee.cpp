//  Employee.cpp
// Employee class member-function definitions.
#include <iostream>
#include "Employee.h" // Employee class definition
#include "Date.h" // Date class definition
//#include "DateTime.h" // Date class definition
#include <stdexcept>
#include <iomanip>
using namespace std;

// constructor uses member initializer list to pass initializer 
// values to constructors of member objects  
Employee::Employee( const string &first, const string &last,
   const Date &dateOfBirth, const Date &dateOfHire, DateTime st, DateTime et )
   : firstName( first ), // initialize firstName
     lastName( last ), // initialize lastName
     birthDate( dateOfBirth ), // initialize birthDate
     hireDate( dateOfHire ), // initialize hireDate
	 startDateTime(st),
	endDateTime(et)
{
   // output Employee object to show when constructor is called
   cout << "Employee object constructor: " 
      << firstName << ' ' << lastName << endl;
   //count++;
} // end Employee constructor

// print Employee object
void Employee::print() const
{
   cout << lastName << ", " << firstName << "  Hired: ";
   hireDate.print();
   cout << "  Birthday: ";
   birthDate.print();
   cout << endl;
} // end function print

string Employee::getFirstName()
{
	return firstName;
}

string Employee::getLastName()
{
	return lastName;
}

Date Employee::getHireDate()
{
	return hireDate;
}

Date Employee::getBirthDay()
{
	return birthDate;
}

DateTime Employee::getStartDateTime()
{
	return startDateTime;
}

DateTime Employee::getEndDateTime()
{
	return endDateTime;
}

bool Employee::testZeroDatetime(DateTime dt)
{
	if (dt.getDay()==0&&dt.getHour() ==0&&dt.getMinute() ==0&&dt.getMonth() ==0&&dt.getSecond() ==0&&dt.getYear() ==0)
	return true;
	return false;
}

void Employee::setendDateTime(int hr, int mn, int sc)
{
	endDateTime.setHour(hr);
	endDateTime.setMinute(mn);
	endDateTime.setSecond(sc);
}

void Employee::print()
{
	cout << "Employee: " << getFirstName() << " " << getLastName() << setw(2) << "birth date: ";
	birthDate.print();
	hireDate.print();
	cout << endl;
	if (!testZeroDatetime(startDateTime))
	{
		cout << "No specified end training date and time\n";
	}
	else {
		startDateTime.print();
		endDateTime.print();
	}

}

int Employee::getCount()
{
	return 1;
}



// output Employee object to show when its destructor is called
Employee::~Employee()
{ 
   cout << "Employee object destructor: " 
      << lastName << ", " << firstName << endl;
} // end ~Employee destructor
