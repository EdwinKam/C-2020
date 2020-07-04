//Date.h 
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H
#include "Time.h"

class Date 
{
public:
   static const unsigned int monthsPerYear = 12; // months in a year
   explicit Date( int = 1, int = 1, int = 1900 , Time=Time()); // default constructor
   void print() const; // print date in month/day/year format
   void increaseADay();
   void tick();
   void setDay(int);
   void setMonth(int);
   void setYear(int);

   ~Date(); // provided to confirm destruction order
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year

   // utility function to check if day is proper for month and year
   unsigned int checkDay( int ) const; 
   Time t;
}; // end class Date

#endif

