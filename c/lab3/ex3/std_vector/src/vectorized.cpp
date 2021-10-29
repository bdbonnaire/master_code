/*
 * =====================================================================================
 *
 *       Filename:  vectorized.cpp
 *
 *    Description: a std::vector implementation of exercice 3 
 *
 *        Version:  1.0
 *        Created:  10/29/21 19:00:22
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <vector>
#include <ctime>
#include "factorial.hpp"
#include "vectorized.hpp"

void init(std::vector<int>& c, int k, int start, int end)
{
	// initialize k elements in the collection. The
	// elements are pseudo randoms between args start and end.
	srand(time(nullptr));

	//if start and end are inverted switch them up
	if(start > end){ 
		start = start + end;
		end = start - end;
		start = start - end;
	}
	for(int i=0; i<k; i++){
		int random = start + rand() % (end - start);
		c.push_back(random);
	}
}

template <class T> 
void apply_fact(const std::vector<int>& c, std::vector<T>& res)
{
	//calculates the factorial of each element of c and put it in res
	for( unsigned long i=0; i<c.size(); i++){
		T facted = fact<T>(c[i]);
		res.push_back(facted);
	}
}
//
// ------- Template apply_fact Available types -------------------//
// char
template void apply_fact(const std::vector<int>& c, std::vector<char>& res);
//short int
template void apply_fact(const std::vector<int>& c, std::vector<short int>& res);
//int
template void apply_fact(const std::vector<int>& c, std::vector<int>& res);
//long int
template void apply_fact(const std::vector<int>& c, std::vector<long int>& res);
//long long int
template void apply_fact(const std::vector<int>& c, std::vector<long long int>& res);
// __int128
template void apply_fact(const std::vector<int>& c, std::vector<__int128>& res);


template <class T>
std::ostream& operator<< (std::ostream& o, std::vector<T> &collec)
{
	for(unsigned long i=0; i<collec.size(); i++)
		o << "[" << i << "] : " <</*  Note the + here */ collec[i] << "\n";
	return o;
}

//======= Definitions so that the linker doesn't go crazy ===============//
//specification for char, so that it shows as an integer and 
//not a character.
template <> std::ostream& operator<< (std::ostream& o, std::vector<char> &collec)
{
	for(unsigned long i=0; i<collec.size(); i++)
		o << "[" << i << "] : " <</*  Note the + here */ +collec[i] << "\n";
	return o;
}
template std::ostream& operator<< (std::ostream& o, std::vector<short int> &collec);
template std::ostream& operator<< (std::ostream& o, std::vector<int> &collec);
template std::ostream& operator<< (std::ostream& o, std::vector<long int> &collec);
template std::ostream& operator<< (std::ostream& o, std::vector<long long int> &collec);
template std::ostream& operator<< (std::ostream& o, std::vector<__int128> &collec);

