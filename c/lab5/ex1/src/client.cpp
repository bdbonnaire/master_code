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
#include <ostream>
#include <stdlib.h>
#include <fstream>
#include "account.hpp"
#include "client.hpp"

Client::Client(std::string n, Current *c, Unblocked *u) : name(n)
{
	current = c;
	savings = u;
	id = get_and_update_nbrClients();
}

unsigned int Client::get_and_update_nbrClients()
{

	//============ id generation from a file ============
	// reading the file 
	// if the file does not exist it is created
	std::fstream ids("ids_clients.txt");
	int current_id = -1;
	if(ids.is_open())
	{
		ids >> current_id;
		ids.close();
//		if the file did not exist it was created empty and 
//		current_id is still -1
	}
	
	current_id++;
	// defining the account id

	// adding 1 to the file
	ids.open("ids_clients.txt", std::ios::out | std::ios::trunc);
	if(ids.is_open())
	{
		ids << current_id;
		ids.close();
	}

	return current_id;
}

void Client::credit_saving(double amount)
{
	savings->credit(amount);
}

void Client::credit_current(double amount)
{
	current->credit(amount);
}

void Client::debit_saving(double amount)
{
	savings->debit(amount);
}

void Client::debit_current(double amount)
{
	current->debit(amount);
}

unsigned int Client::operator()() const
{
	return id;
}

std::ostream &operator<<(std::ostream &o, Client &c)
{
	o <<  c.name << "\n";
	if (c.current != NULL){
		o << "--> Current account : \n";
		c.current->print(o);
	}
	else
		o << " -- no current account -- \n";

	if (c.savings != NULL){
		o << "--> Savings  account : \n";
		c.savings->print(o);
	}
	else
		o << " -- no savings account -- \n";

	return o;
}
