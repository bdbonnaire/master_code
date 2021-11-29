/*
 * =====================================================================================
 *
 *       Filename:  functions.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/21 19:35:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <string>
#include <ostream>
#include "function.hpp"

////////////////// Function Class //////////////////

Function::Function(std::string n) : name(n) {}

void Function::print(std::ostream& o)
{
	o << name << "(x) = ";
}

//////////////////// Poly0 Class //////////////////

Poly0::Poly0(std::string n, float c0) :
	Function(n),
	a0(c0)
{}

double Poly0::eval(double x0)
{
	return a0;
}

Function* Poly0::derivative()
{
	return new Poly0(name + "'", 0);
}

void Poly0::print(std::ostream& o)
{
	Function::print(o);
	o << a0 << std::endl;
}

//////////////////// Poly1 Class //////////////////

Poly0::Poly0(std::string n, float c0) :
	Function(n),
	a0(c0)
{}

double Poly0::eval(double x0)
{
	return a0;
}

Function* Poly0::derivative()
{
	return new Poly0(name + "'", 0);
}

void Poly0::print(std::ostream& o)
{
	Function::print(o);
	o << a0 << std::endl;
}

//////////////////// Poly0 Class //////////////////

Poly0::Poly0(std::string n, float c0) :
	Function(n),
	a0(c0)
{}

double Poly0::eval(double x0)
{
	return a0;
}

Function* Poly0::derivative()
{
	return new Poly0(name + "'", 0);
}

void Poly0::print(std::ostream& o)
{
	Function::print(o);
	o << a0 << std::endl;
}
