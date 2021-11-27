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
	Account account(123.4);
	Current current(325.4);
	Savings savings(3333.33, 2.6);
	Blocked blocked(32323.95);
	Unblocked unblocked(2322);

	std::cout << "######### \nTesting a debit of 1\n######### ";

	test_debit(account, 1);
	test_debit(current, 1);
	test_debit(savings, 1);
	test_debit(blocked, 1);
	test_debit(unblocked, 1);

	std::cout << "######### \nTesting a credit of 1\n######### ";

	test_credit(account, 1);
	test_credit(current, 1);
	test_credit(savings, 1);
	test_credit(blocked, 1);
	test_credit(unblocked, 1);

	std::cout << "######### \nTesting a debit of 100,000 \n######### ";
	
	test_debit(account, 100000);
	test_debit(current, 100000);
	test_debit(savings, 100000);
	test_debit(blocked, 100000);
	test_debit(unblocked, 100000);

	return 0;
}
