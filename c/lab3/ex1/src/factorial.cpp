/*
 * =====================================================================================
 *
 *       Filename:  factorial.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/21 13:37:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef FACTORIAL_CPP
#define FACTORIAL_CPP

#include <ostream>
#include <stdlib.h>
#include <iostream>
#include "factorial.hpp"

void multi_type_fact(int n)
{
	const char *types[6] = {"Byte integer : char",
	   				"short int",
				   	"int", 
					"long integer : long int",
					"long long integer : long lon int",
					"128 bit integer : __int128"};

	for(int i=0; i<6; i++)
	{
		std::cout << types[i] << " : \n";
		fact_verbose(n,i);
	}
}

void fact_verbose(int n, int t)
{
	switch(t)
	{
		case 0:
			std::cout << "Size : " << sizeof(char) << "\n";
			std::cout << fact<char>(n) << "\n";
		case 1:
			std::cout << "Size : " << sizeof(short int) << "\n";
			std::cout << fact<short int>(n) << "\n";
		case 2:
			std::cout << "Size : " << sizeof(int) << "\n";
			std::cout << fact<int>(n) << "\n";
		case 3:
			std::cout << "Size : " << sizeof(long int) << "\n";
			std::cout << fact<long int>(n) << "\n";
		case 4:
			std::cout << "Size : " << sizeof(long long int) << "\n";
			std::cout << fact<long long int>(n) << "\n";
		case 5:
			std::cout << "Size : " << sizeof(__int128) << "\n";
			std::cout << fact<__int128>(n) << "\n";
		default:
			std::cerr << "Unkown type specified." << std::endl;

	}
}

template<class T>
T fact(int n)
{
	T temp = 1;
	for(int i=n; i>1; i--)
		temp = temp*i;
	return temp;
}

std::ostream &operator<<(std::ostream &o, __int128 value)
{
	
	unsigned __int128 u_value = value < 0 ? -value : value;

	// 2^128 ~=3.4E38 so 38 characters are needed at best.
	// We add 2 more for the possible minus and the
	// terminating character.
	char buffer[40];
	char *head = std::end(buffer);

	do
	{
		--head;
		// access the value of the constant string "0123456789"
		// indexed by u_value % 10.
		// 	Ex : if the last character of u_value is 4 then 
		// 	u_value % 10 gives 4 which conveniently coincides with
		// 	the idnex 4 of "0123456789". 
		*head = "0123456789"[u_value % 10];
		u_value /= 10;
	}while(u_value != 0);

	if(value < 0)
	{
		--head;
		*head = '-';
	}
	o << buffer;
	return o;

}
#endif
