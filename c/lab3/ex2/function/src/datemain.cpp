/*
 * =====================================================================================
 *
 *       Filename:  datemain.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/09/2021 09:52:05
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h> //atoi
#include <iostream>

#include "date.hpp"
using namespace std;

int main(int argc, char* argv[])
{
	if(argc==5)
	{
		char* name = argv[1];
		Date birth(atoi(argv[2]),atoi(argv[3]), atoi(argv[4])), today(time(0));
		today.happy_birthday(name, birth);
		return 0;
	}
	else
		cerr << "Wrong number of arguments : name day month year" << endl;
		return 1;

}
