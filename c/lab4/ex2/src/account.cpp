/*
 * =====================================================================================
 *
 *       Filename:  account.cpp
 *
 *    Description: Implementation of the classes in account.h 
 *
 *        Version:  1.0
 *        Created:  11/09/21 11:02:07
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "account.hpp"

// ===================== CLASS : ACCOUNT ==============================
unsigned int Account::get_and_update_nbrAccounts()
{

	//============ id generation from a file ============
	// reading the file 
	// if the file does not exist it is created
	std::fstream ids("ids.txt");
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
	ids.open("ids.txt", std::ios::out | std::ios::trunc);
	if(ids.is_open())
	{
		ids << current_id;
		ids.close();
	}

	return current_id;
}

Account::Account(unsigned int id, double balance)
{
	this->id = id;
	this->balance = balance;
}

Account::Account(double balance)
{
	this->balance = balance;
	id = get_and_update_nbrAccounts();
}

Account::Account()
{
	balance = 0;
	id = get_and_update_nbrAccounts();
}



double Account::debit(double a)
{
	balance -= a;
	return a;
}

unsigned int Account::operator()()
{
	return id;
}

void Account::credit(double a)
{
	balance += a;
}

void Account::print(std::ostream &o)
{
	o << "Account ID : " << id << 
		"\n Current Balance : " << balance << std::endl;
}

//======================= CLASS : CURRENT ============================

// if the amount a is smaller debits a from the balance
// if a is greater than the balance debits the whole balance but do
// not go to the negative
// Returns the amount debited
double Current::debit(double a)
{
	// variable holding the actual debited value
	double actual_debit = balance >= a ? a : balance;
	return this->Account::debit(actual_debit);
}

//====================== CLASS : SAVING ===============================

Savings::Savings(unsigned int id, double balance, float interest_rate) :
	Account(id, balance)
{
	this->interest_rate = interest_rate;
}

Savings::Savings(double balance, float interest_rate) :
	Account(balance)
{
	this->interest_rate = interest_rate;
}

void Savings::add_interest()
{
	balance += balance*interest_rate;
}
//===================== CLASS : BLOCKED ===============================
Blocked::Blocked(unsigned int id, double balance) : 
	Savings(id, balance, IRATEBLOCKED) {}

Blocked::Blocked(double balance) : 
	Savings(balance, IRATEBLOCKED) {}

double Blocked::debit(double amount)
{
	return -1;
}
//===================== CLASS : BLOCKED ===============================
Unblocked::Unblocked(unsigned int id, double balance) : 
	Savings(id, balance, IRATEUNBLOCKED) {}

Unblocked::Unblocked(double balance) : 
	Savings(balance, IRATEUNBLOCKED) {}

// Debits the account only if the amount is smaller than 
// the balance
double Unblocked::debit(double amount)
{
	double actual_debit(balance >= amount ? amount : 0);

	return this->Account::debit(actual_debit);
	
}
