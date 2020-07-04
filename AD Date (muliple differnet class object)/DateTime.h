#pragma once
#define DATETIME_H
#include "Date.h" // Date class definition
//#include "Employee.h" // Employee class definition
#include "Time.h" // Date class definition
class DateTime
{
	public: 
		explicit DateTime(int = 0, int = 0, int = 0, Time = Time());
		static const int monthsPerYear = 12;
		void print() const;
		void increaseADay();
		void tick();
		int getMonth() const;
		int getYear() const;
		int getDay() const;
		void setMonth(int);
		void setYear(int);
		void setDay(int);
		int getHour() const;
		int getMinute() const;
		int getSecond() const;
		void setHour(int);
		void setSecond(int);
		void setMinute(int);
		~DateTime();


private:
	int month, year, day;
	Time t;
	unsigned int checkDay(int) const;

};

