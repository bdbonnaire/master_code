/*
 * =====================================================================================
 *
 *       Filename:  bank.cpp
 *
 *    Description: Collection of clients objects using std::map 
 *
 *        Version:  1.0
 *        Created:  11/27/21 23:11:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <ostream>
#include "bank.hpp"
#include "account.hpp"
#include "client.hpp"

void Bank::insertClient(Client &c)
{
	clients[c()] = &c;	
}

std::ostream& operator<<(std::ostream &o, Bank &b)
{
	o << "Clients of the bank : \n" <<
		"|\n";
	for( std::map<unsigned int, Client*>::iterator i = 
			b.clients.begin(); i != b.clients.end(); i++)
		o << "|- ID = " << i->first << " : " << *(i->second) << "\n";
	return o;
}
