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
#include "bank.hpp"
#include "account.hpp"
#include "client.hpp"

int main()
{
	// creating test objects
	Current current(325.4);
	Unblocked savings(3333.33);

	Client charle("Charle", &current, &savings);

	Bank smithAndSmithAndSmithAndSmith;
	smithAndSmithAndSmithAndSmith.insertClient(charle);

	std::cout << smithAndSmithAndSmithAndSmith;

	return 0;
}
