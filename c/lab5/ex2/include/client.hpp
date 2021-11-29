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
#include <vector>
#include "account.hpp"

class Client 
{
	private:
		std::string name;
		unsigned int id;
		std::vector<Account*> accounts;
		unsigned int max_account;
		unsigned int current_nbr_accounts;

		// method to get and track the id from a file
		unsigned int get_and_update_nbrClients();
		
	public:
		Client(std::string n, unsigned int max_account);
		Client(std::string n, unsigned int max_account, unsigned int id);
		Client(const Client &c);

		// returns the id of the client
		unsigned int operator()() const;

		// creates a new account with balance 0
		void createAccount();
		// debits and credits the account on the given
		void credit(double amount);
		void debit(double amount);

		// The operator prints the attributes of the client and
		// the details of its bank accounts.
		friend std::ostream &operator<<(std::ostream &o, Client &c);
};

std::ostream &operator<<(std::ostream &o, Client &c);

#endif
