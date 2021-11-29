/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/29/21 20:19:00
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "function.hpp"

int main()
{

	std::vector<Function*> polynoms;
	polynoms.push_back(new Poly0("p0", 6));
	polynoms.push_back(new Poly1("p1", 2, 5));
	polynoms.push_back(new Poly2("p2", 10, 3, 2));

	std::cout << "++ Content of the vector ++ \n";
	for(unsigned long i = 0; i < polynoms.size(); i++)
	{
		polynoms[i]->print(std::cout);
		std::cout << "\n its derivative : ";
	   	polynoms[i]->derivative()->print(std::cout);
		std::cout << "\n has on 1 the value " << 
			polynoms[i]->derivative()->eval(1) << std::endl;

	}
	return 0;
}
