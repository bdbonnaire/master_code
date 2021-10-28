#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string.h> // strlen, strcpy

#include "date.hpp"

using namespace std;

unsigned int day, month, year;

//---------------------------------------------------------------
//constructor
Date::Date(const unsigned int &d/*1 */, const unsigned int &m/*1*/ , const unsigned int &y/*1970*/)
{
	if(d <= 30 && m <= 12 && y >= 1900 && d != 0 && m!= 0)
	{
		day = d;
		month = m;
		year = y;
	}
}

//-------------------------------------------------------------
//constructor using ctime
Date::Date(const time_t &time)
{
	struct tm *t = localtime(&time);
	day = t->tm_mday;
	month = t->tm_mon + 1;
	year = t->tm_year + 1900;
}
//
//-------------------------------------------------------------
//copy constructor
Date::Date(Date &date)
{
	month = date.month;
	year = date.year;
	day = date.day;
	// initialisation of dayName
	int size_dayName(strlen(date.dayName));
	dayName = new char[size_dayName];
	strcpy(dayName, date.dayName);
}

//-------------------------------------------------------------
//destructor
Date::~Date()
{
	delete [] dayName;	
}

//-------------------------------------------------------------
//a method giving the name of the month
const char* Date::make_month_readable()
{
	switch(month)
	{
		case 1 : return "January";
		case 2 : return "February";
		case 3 : return "March";
		case 4 : return "April";
		case 5 : return "May";
		case 6 : return "June";
		case 7 : return "July";
		case 8 : return "August";
		case 9 : return "September";
		case 10 : return "October";
		case 11 : return "November";
		case 12 : return "December";
		default : return "ERROR";
	}
}

//--------------------------------------------------------------
//prints the full date with the month's name
void Date::print_date()
{
	cout << make_month_readable() << " " << day << " " << year;
}

//-------------------------------------------------------------
//
void Date::happy_birthday(const char* n, Date b)
{
	Date today(time(0));
	if( b.day == day && b.month == month )
	{
		cout << "Happy Birthday " << n << " ! \nYou are now " << today.year - b.year << " years old !"<< endl;
	}
	else
	{
		cout << "Bad news " << endl << "It's not your birthday..." << endl;
	}
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Date
 *      Method:  Date :: before
 * Description: returns a boolean representing whether the current date is before 
 * 		the argument d 
 *--------------------------------------------------------------------------------------
 */
bool Date::operator<(const Date &d)
{
	if((*this - d) < 0 )
		return true;
	else
		return false;
}

bool Date::before(const Date &d)
{
	if(year < d.year ||
		(year == d.year && month < d.month) ||
		(year == d.year && month == d.month && day < d.day))
		return true;
	else
		return false;
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Date
 *      Method:  Date :: difference
 * Description: returns the difference between this ate and the argument d,
 * supposing *this is before d.
 * It supposes for simplicity that 1 month = 30 days and 1 year = 360
 *--------------------------------------------------------------------------------------
 */
int Date::operator-(const Date &d)
{
	return day - d.day + 30*(month -d.month) + 360*(year - d.year);
}

int Date::difference(const Date &d)
{
	return -(day - d.day + 30*(month -d.month) + 360*(year - d.year));
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Date
 *      Method:  Date :: duration
 * Description: returns the number of days between *this and argument d 
 *--------------------------------------------------------------------------------------
 */
int Date::duration(const Date &d)
{
	int	diff = *this - d;
	if(*this < d)
		return -diff;
	else
		return diff;
}
