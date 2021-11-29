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
#include <fstream>
#include "client.hpp"

int main()
{
	// creating a client called Roger
	Client roger("Roger", 4);
	
	//adding two accounts to Roger
	roger.createAccount();
	roger.createAccount();

	//displaying Roger
	std::cout << roger << std::endl;

	// copying Roger
	Client roger2(roger);
	std::cout << roger2 << std::endl;

	//putting Roger into a file and hoping he stays there
	std::fstream roger3_the_file;

	roger3_the_file.open("roger3_the_file.txt", std::ios::out | std::ios::trunc);
	if(roger3_the_file.is_open())
	{
		roger3_the_file << roger;
		roger3_the_file.close();
	}

	return 0;
}
