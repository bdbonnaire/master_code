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
