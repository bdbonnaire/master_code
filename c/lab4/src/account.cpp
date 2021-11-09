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
#include <ostream>
#include <stdlib.h>
#include "account.hpp"

// ===================== CLASS : ACCOUNT ==============================

Account::Account(unsigned int id, double balance)
{
	this->id = id;
	this->balance = balance;
}

double Account::debit(double a)
{
	id -= a;
	return a;
}

unsigned int Account::get_id()
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
	double actual_debit(balance >= a ? a : balance);
	return this->Account::debit(actual_debit);
}

//====================== CLASS : SAVING ===============================

Savings::Savings(unsigned int id, double balance, int interest_rate) :
	Account(id, balance)
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

double Blocked::debit(double amount)
{
	return -1;
}
//===================== CLASS : BLOCKED ===============================
Unblocked::Unblocked(unsigned int id, double balance) : 
	Savings(id, balance, IRATEUNBLOCKED) {}

// Debits the account only if the amount is smaller than 
// the balance
double Unblocked::debit(double amount)
{
	double actual_debit(balance >= amount ? amount : 0);

	return this->Account::debit(actual_debit);
	
}
