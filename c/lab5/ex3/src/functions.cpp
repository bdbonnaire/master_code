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

Poly0::Poly0(std::string n, double c0) :
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

Poly1::Poly1(std::string n, double c0, double c1) :
	Function(n),
	a0(c0),
	a1(c1)
{}

double Poly1::eval(double x0)
{
	return a1*x0 + a0;
}

Function* Poly1::derivative()
{
	return new Poly0(name + "'", a1);
}

void Poly1::print(std::ostream& o)
{
	Function::print(o);
	o << a1 << "x + " << a0 << std::endl;
}

//////////////////// Poly2 Class //////////////////

Poly2::Poly2(std::string n, double c0, double c1, double c2) :
	Function(n),
	a0(c0),
	a1(c1),
	a2(c2)
{}

double Poly2::eval(double x0)
{
	return a2*x0*x0 + a1*x0 + a0;
}

Function* Poly2::derivative()
{
	return new Poly1(name + "'", a1, 2*a2);
}

void Poly2::print(std::ostream& o)
{
	Function::print(o);
	o << a2 << "x² + " << a1 << "x + " << a0 << std::endl;
}

