/*
 * =====================================================================================
 *
 *       Filename:  client.cpp
 *
 *    Description: implementation of client.hpp 
 *
 *        Version:  1.0
 *        Created:  11/16/21 00:23:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "account.hpp"
#include "client.hpp"

Client::Client(unsigned int i, std::string n, Current *c, Unblocked *u) : name(n), id(i)
{
	current = c;
	savings = u;
}

~Client()
{

}
