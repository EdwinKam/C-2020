// Date.h 
// Date class definition; Member functions defined in Date.cpp
#ifndef DATE_H
#define DATE_H
#include "Time.h"

class Date 
{
public:
   static const unsigned int monthsPerYear = 12; // months in a year
   explicit Date( int = 1, int = 2, int = 1900, Time = Time() ); // default constructor
   void print(); // print date in month/day/year format
   ~Date(); // provided to confirm destruction order
   void tick();
   void increaseADay();
private:
   unsigned int month; // 1-12 (January-December)
   unsigned int day; // 1-31 based on month
   unsigned int year; // any year
   Time t;
   // utility function to check if day is proper for month and year
   unsigned int checkDay( int ) const; 
}; // end class Date

#endif
