/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description: gets an integer as an argument from the command line and returns the 
 *    factorial. Tests for overflow for different types.
 *
 *        Version:  1.0
 *        Created:  10/28/21 13:16:00
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
#include "factorial.hpp"

using namespace std;

int maint(int argc, char *argv[])
{
	if (argc == 2)
	{
		//calls a wrapper that will calculates the factorial using different types
		// and will print it saying the type and the amount of bytes each can hold.
		multi_type_fact(atoi(argv[1]));	
	}
	else
	{
		cerr << "Too many or too few arguments. \n" << 
			argc << " were given instead of 1.";
	}

	return 0;
}
