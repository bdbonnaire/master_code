/*
 * =====================================================================================
 *
 *       Filename:  ex1.cpp
 *
 *    Description: pass by copy vs. pass by ref. exercice 
 *
 *        Version:  1.0
 *        Created:  10/05/21 09:56:02
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

using namespace std;

int make_computation(int *x)
{
	int i;
	for(i=1; i<=4; i++)
		*x *= i;
	return *x;
}

int main(void)
{
	int k;
	cout << "Give an integer for the computation ";
	cin >> k;
	cout << "\n Function make_computation returns " << make_computation(&k)
		<< " and the value of k is " << k << endl;
	return 0;
}
