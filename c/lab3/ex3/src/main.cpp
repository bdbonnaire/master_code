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
#include "factorial.hpp"
#include "mycollection.hpp"

using namespace std;
int main(){

	MyCollection<int> collec;
	init(collec, 5);

	cout << "Creation of an integer collection of size 5 with random numbers:\n" <<
		collec;

	MyCollection<int> res;
	apply_fact(collec, res);	
	cout << "Here is the factorial of every elements in the previous collection :\n" << res << endl;

}
