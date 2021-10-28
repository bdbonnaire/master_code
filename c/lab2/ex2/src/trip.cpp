/*
 * =====================================================================================
 *
 *       Filename:  trip.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/07/21 10:21:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <stdlib.h>
#include "date.hpp"
#include "trip.hpp"

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Trip
 *      Method:  Trip :: extensive constructor
 * Description: constructs a trip by creating a Date object in-house from day, month 
 * 		and year values. 
 *--------------------------------------------------------------------------------------
 */
Trip::Trip(const unsigned int &beg_day, const unsigned int &beg_month, const unsigned int &beg_year,
	const unsigned int &end_day, const unsigned int &end_month, const unsigned int &end_year,
	const float &price)
{
	new (&beg) Date(beg_day, beg_month, beg_year);
	new (&end) Date(end_day, end_month, end_year);
	this->price = price;
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Trip
 *      Method:  Trip :: Date constructor
 * Description: constructs a Trip directly from Date objects
 *--------------------------------------------------------------------------------------
 */
Trip::Trip(const Date &beg, const Date &end, const float &price)
{
	this->beg = beg;
	this->end = end;
	this->price = price;
}

/*
 *--------------------------------------------------------------------------------------
 *       Class:  Trip
 *      Method:  Trip :: print_trip
 * Description: prints the price, beginning and end of a trip. 
 *--------------------------------------------------------------------------------------
 */
void Trip::print_trip()
{
	std::cout << "The trip will run from ";
	beg.print_date();
	std::cout << " to ";
	end.print_date();
	std::cout << "(" << beg.duration(end) << " days)";
	std::cout << " and will cost " << price << "¤." << std::endl;
}
