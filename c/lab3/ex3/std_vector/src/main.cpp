/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/21 07:32:06
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <iostream>
#include <vector>
#include "factorial.hpp"
#include "vectorized.hpp"

using namespace std;
int main(){

	vector<int> collec;
	init(collec, 5,  5, 15);

	cout << "Creation of an integer collection of size 5 with random numbers from 5 to 15:\n" <<
		collec;

	vector<char> res;
	apply_fact<char>(collec, res);	
	cout << "factorial of every elements in the previous collection in type char :\n" << res << endl;


	vector<short int> res1;
	apply_fact<short int>(collec, res1);	
	cout << "factorial of every elements in the previous collection in type short int :\n" << res1 << endl;

	vector<int> res2;
	apply_fact<int>(collec, res2);	
	cout << "factorial of every elements in the previous collection in type int :\n" << res2 << endl;

	vector<long int> res3;
	apply_fact<long int>(collec, res3);	
	cout << "factorial of every elements in the previous collection in type long int :\n" << res3 << endl;

	vector<long long int> res4;
	apply_fact<long long int>(collec, res4);	
	cout << "factorial of every elements in the previous collection in type long long int :\n" << res4 << endl;

	vector<__int128> res5;
	apply_fact<__int128>(collec, res5);	
	cout << "factorial of every elements in the previous collection in type __int128 :\n" << res5 << endl;

	return 0;
}
