/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/21 12:34:06
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include "PPoint.hpp"

using namespace std;

int main()
{
	Array_of_PPoint zero(4);
	Array_of_PPoint random(4,0,5,0,5);
	cout << "An array of null points :" << endl;
	zero.print_tabs();
	cout << "An array of random points between 0 and 5 :" << endl;
	random.print_tabs();

	PPoint p(2,6);
	cout << "Adding P = (2,6) to the previous arrays" << endl;
	zero.add(p);
	random.add(p);
	zero.print_tabs();
	random.print_tabs();

	cout << "This array addition will throw two \"unexpected value\" exeptions" << endl;
	Array_of_PPoint exeption(2);
	exeption.add(PPoint(21,0));


	return 0;
}
