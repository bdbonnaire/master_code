/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/09/21 12:38:36
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
#include "account.hpp"
#include "client.hpp"
template <class T>
void test_debit(T &A, double amount)
{
	
	A.print(std::cout << "\n");
	std::cout << "debiting " << A.debit(amount) << 
		" to account n° " << A() << "\n";
	A.print(std::cout << "\n");
}	

template <class T>
void test_credit(T &A, double amount)
{
	std::cout << "crediting " << amount <<
	   "to account n° " << A() << "\n";
	A.print(std::cout << "\n");
	A.credit(amount);
	A.print(std::cout << "\n");
}	

int main()
{
	// creating test objects
	Current current(325.4);
	Unblocked savings(3333.33);

	Client charle("Charle", &current, &savings);

	std::cout << charle;

	return 0;
}
