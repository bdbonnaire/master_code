/*
 * =====================================================================================
 *
 *       Filename:  PPoint.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/21 10:39:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iterator>
#include <stdlib.h> //rand, srand
#include <typeinfo> //type_info
#include <string>
#include <iostream>
#include <time.h> // time
#include "PPoint.hpp"

/**
 *\file PPpoint.cpp
 *\brief contains the implementation of PPoint and Array_of_PPoint metods.
*/
//######################## PPoint #####################################

//---------------------------------------------------------------------
/// Default constructor, initiates to (0,0) if no arg is given
PPoint::PPoint(const int &x/*0*/, const int &y/*0*/)
{
	this->x = new int;
	this->y = new int;

	*(this->x) = x;
	*(this->y) = y;
	std::cout << "type of the object created : " << typeid(*this).name() << std::endl;
}

//---------------------------------------------------------------------
/// Copy constructor
PPoint::PPoint(const PPoint &point)
{
	x = new int;
	y = new int;
	*x = *(point.x);
	*y = *(point.y);
	std::cout << "calling PPoint copy constructor..." << std::endl;
}

//---------------------------------------------------------------------
///Destructor
PPoint::~PPoint()
{
	delete x;
	delete y;
	std::cout << "calling PPoint destructor..." << std::endl;
}

//---------------------------------------------------------------------
/// method to add a point to the current point
void PPoint::add(const PPoint &p)
{
	*x += *(p.x);
	*y += *(p.y);
}

//--------------------------------------------------------------------
/// method to set the coordinates of the points
void PPoint::set_coordinates(const int &x, const int &y)
{
	*(this->x) = x;
	*(this->y) = y;
}

//--------------------------------------------------------------------
/// prints the coordinates of the point in the (x,y) fashion
void PPoint::print()
{
	std::cout << "(" << *x << "," << *y << ")" ;
}


//################ Array_of_PPoint ####################################


//--------------------------------------------------------------------
///Default constructor, initializes every point to (0,0)
Array_of_PPoint::Array_of_PPoint(const unsigned int &len)
{
	array = new PPoint[len];
	length = len;
}

//--------------------------------------------------------------------
/** random constructor, intitializes every point to a random value in 
 * (x0,x1) for the first coordinate and (y0, y1) for the second
 */
Array_of_PPoint::Array_of_PPoint(const unsigned int &len,
		const unsigned int &x0=0,
		const unsigned int &x1=5,
		const unsigned int &y0=0,
		const unsigned int &y1=5
		)
{
	srand (time(NULL)); /// initialize the random seed
	
	array = new PPoint[len];
	length = len;

	for(unsigned int i=0; i<len; i++)
	{
		int x = rand() % x1 + x0;
		int y = rand() % y1 + y0;
		array[i].set_coordinates(x,y);
	}
}

//--------------------------------------------------------------------
///Copy constructor
Array_of_PPoint::Array_of_PPoint(const Array_of_PPoint &p)
{
	array = new PPoint[p.length];
	length = p.length;
	for(unsigned int i=0; i < length; i++)
	   array[i] = p.array[i];	

	std::cout << "calling array copy constructor..." << std::endl;
}

//--------------------------------------------------------------------
/// Destructor
Array_of_PPoint::~Array_of_PPoint()
{
	for(unsigned int i=0; i<length; i++)
		delete &array[i];
	delete array;
	std::cout << "calling array destructor..." << std::endl;
}

//--------------------------------------------------------------------
///  adds a PPoint p to all the points in the array
void Array_of_PPoint::add(const PPoint &p)
{
	for(unsigned int i=0; i < length; i++)
		array[i].add(p);
}

//--------------------------------------------------------------------
/// Print a nice looking tab containing the PPoints of the array 
void Array_of_PPoint::print_tabs()
{
	std::cout << "index \t (x,y)" << std::endl;
	for(unsigned int i=0; i < length; i++)
	{
		std::cout << "[" << i << "]\t";
		array[i].print();
		std::cout << std::endl;
	}
}
