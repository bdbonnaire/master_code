/*
 * =====================================================================================
 *
 *       Filename:  currencies.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/21 12:05:21
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "currencies.hpp"

Dollar::Dollar(const float value) : amount(value) {}

float Dollar::get_value(){
	return amount;
}

Euro::Euro(const float value) : amount(value) {}

float Euro::get_value(){
	return amount;
}

Pounds::Pounds(const float value) : amount(value) {}

float Pounds::get_value(){
	return amount;
}

std::ostream& operator<<(std::ostream& o, Dollar& x){
	o << x.get_value() << " $\n";
	return o;
}
std::ostream& operator<<(std::ostream& o, Euro& x){
	o << x.get_value() << " €\n";
	return o;
}
std::ostream& operator<<(std::ostream& o, Pounds& x){
	o << x.get_value() << " £\n";
	return o;
}
