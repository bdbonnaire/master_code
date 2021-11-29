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
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <fstream>
#include "account.hpp"
#include "client.hpp"

//_________________ Client Constructors ___________________//

Client::Client(std::string n,unsigned int max) : name(n),
   	max_account(max),
	current_nbr_accounts(0)
{
	id = get_and_update_nbrClients();
}

// constructor for setting the client id manually
Client::Client(std::string n,unsigned int max, unsigned int i) :
   	name(n), 
	id(i), 
	max_account(max),
	current_nbr_accounts(0)

{}

//Copy constructor
Client::Client(const Client &c) : name(c.name), 
	id(c.id),
	accounts(c.accounts),
	max_account(c.max_account), 
	current_nbr_accounts(c.current_nbr_accounts)
{}
	
//________________ Client ID Generation _________________//

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


unsigned int Client::operator()() const
{
	return id;
}

//utility function to test whether a string is a number
bool isNum(std::string s)
{
	std::locale loc;

	for(unsigned long i=0; i < s.size(); i++)
		if(! isdigit(s[0], loc))
			return false;
	return true;
}


// creates accounts of different types interactively.
// each created account will have a balance of 0 using the default
// value of the constructor.
void Client::createAccount()
{
	std::cout << "Creation of accounts for" << name << " :\n" <<
		"Creation of a current account (1), unblocked savings account(2) or blocked savings account (3) ? \n";

	// var to hold the answer, string to manage error
	std::string answer;
	// bool var to test the correctness of the input
	bool correct = false;
	// a do while loop to manage user error
	do
	{
		std::cin >> answer;

		if(isdigit(answer[0]))
		{
			switch (stoi(answer))
			{
				case 1:
				{
					accounts.push_back(new Current);
					current_nbr_accounts++;
					correct = true;
					break;
				}
				case 2:
				{
					accounts.push_back(new Unblocked);
					current_nbr_accounts++;
					correct = true;
					break;
				}
				case 3:
				{
					accounts.push_back(new Blocked);
					current_nbr_accounts++;
					correct = true;
					break;
				}
				default:
				{
					std::cout << "Bad entry, please try again" << std::endl;
					// if wrong answer var is emptied out
					answer = "";
					break;
				}
			}
		}
		else
		{
			std::cout << "Bad entry, please try again" << std::endl;
			// if wrong answer var is emptied out
			answer = "";
		}

		
	}while (correct != true);
}

std::ostream &operator<<(std::ostream &o, Client &c)
{
	o <<  "--[ ID = " << c() << "\t NAME = " << c.name << " ]-- \n" <<
		"|\n" <<
		"|- Accounts : \n";
	if(!c.accounts.empty())
	{
		for(std::vector<Account*>::iterator i = std::begin(c.accounts); i != c.accounts.end(); i++)
		{
			o << *(*i) << "\n";
		}
	}
	else
	{
		o << "-- No account --" << std::endl;
	}
	
	return o;
}
