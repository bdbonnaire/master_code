/*
 * =====================================================================================
 *
 *       Filename:  client.hpp
 *
 *    Description:  A class for a bank client.
 *
 *        Version:  1.0
 *        Created:  11/15/21 23:26:32
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef CLIENT_H
#define CLIENT_H

#include <ostream>
#include <string>
#include "account.hpp"

class Client 
{
	private:
		std::string name;
		unsigned int id;
		Current *current;
		Unblocked *savings;
		unsigned int get_and_update_nbrClients();
		
	public:
		Client(std::string n, Current *c=NULL, 
				Unblocked *u=NULL);
		// returns the id of the client
		unsigned int operator()() const;

		void credit_current(double amount);	
		void credit_saving(double amount);	

		void debit_current(double amount);	
		void debit_saving(double amount);	

		// The operator prints the attributes of the client and
		// the details of its bank accounts.
		// !!! CHECK IF THE POINTERS ARE NULL !!!
		friend std::ostream &operator<<(std::ostream &o, Client &c);
};

std::ostream &operator<<(std::ostream &o, Client &c);

#endif
