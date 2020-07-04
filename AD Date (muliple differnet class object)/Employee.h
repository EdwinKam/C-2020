// Employee.h
// Employee class definition showing composition.
// Member functions defined in Employee.cpp.
#pragma once
#define EMPLOYEE_H

#include <string>
//#include "Date.h" // include Date class definition
#include "DateTime.h" // include Date class definition
//#include "Time.h" // include Date class definition
using namespace std;


class Employee
{
public:
   Employee( const std::string &, const std::string &,const Date &, const Date & , DateTime, DateTime);
   void print() const;
   string getFirstName();
   string getLastName();
   Date getHireDate();
   Date getBirthDay();
   DateTime getStartDateTime();
   DateTime getEndDateTime();
   bool testZeroDatetime(DateTime);
   void setendDateTime(int, int, int);
   void print();
   static int getCount() ;
   

   ~Employee(); // provided to confirm destruction order
private:
   std::string firstName; // composition: member object
   std::string lastName; // composition: member object
   const Date birthDate; // composition: member object
   const Date hireDate; // composition: member object
   DateTime startDateTime;
   DateTime endDateTime;
  // static int count ;

}; // end class Employee

