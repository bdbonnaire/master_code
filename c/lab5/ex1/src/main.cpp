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

/* Answers :
 *
 * Why is polymorphism useful here ?
 * 	Polymorphism allows us to define a purely virtual function in the
 * 	Account class but still be able to use it in a general function,
 * 	ie a function that acts on all the children of Account class.
 *
 * 	What needs to be modified ?
 * 	In my code I have to modify every implementation of the debit
 * 	method as I used Account.debit everywhere. Had I not not done
 * 	that I would only have to declare debit as virtual and remove
 * 	the definition.
 * 	I will also define the operator<< overloading on the Account
 * 	class.
int main()
{
	// creating test objects
	Current current(325.4);
	Unblocked savings(3333.33);
	Blocked blocked(231.33);

	std::cout << current;
	std::cout << savings;
	std::cout << blocked;

	current.debit(231);
	savings.debit(231);
	blocked.debit(231);

	std::cout << current;
	std::cout << savings;
	std::cout << blocked;

	return 0;
}
