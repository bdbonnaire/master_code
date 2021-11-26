/*
 * =====================================================================================
 *
 *       Filename:  account.hpp
 *
 *    Description: Different banking classes. Used to practive inheritance.
 *    	Content and Hierarchy:
 *
 *    		General Account class 
 *    			Current
 *    			Savings
 *    				Blocked
 *    				Unblocked
 *
 *        Version:  1.0
 *        Created:  11/09/21 10:18:03
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H

#define IRATEBLOCKED 4
#define IRATEUNBLOCKED 2

#include <ostream>

//========================================= ACCOUNT CLASS ==================================
class Account {
	//------------------ Attributes --------------------
	private:
		unsigned int id;

	protected:
		double balance;

	public:
		Account(unsigned int id, double balance=0);
		Account();
		// returns the id of the account
		unsigned int operator()();

	// ---------------- Methods ---------------------


		// debits the account of amount a. Does not check the balance, it is a simple
		// substraction. Returns the amount debited.
		double debit(double a);

		//adds a to the balance
		void credit(double a);
		// print the attributes to the specified ostream
		void print(std::ostream &o);
};

//========================================= CURRENT CLASS ================================

class Current : public Account {
	// Almost vanilla flavor. Only modifies the debit method 
	// checking that the client has enough to make the debit
	
	// Telling to use the constructor of parent class
	using Account::Account;
	public:
		double debit(double amount);	
};

//========================================= SAVINGS CLASS ==========================
class Savings : public Account {
	private: 
		int interest_rate;
			
	public:
		Savings(unsigned int id, double balance, float interest_rate);
		Savings();

		void add_interest();

};

//=================================== BLOCKED CLASS ====================================
class Blocked : public Savings {

	public:
		Blocked(unsigned int id, double balance);
		Blocked();
		double debit(double amount);	
};

//==================================== UNBLOCKED =======================================
class Unblocked : public Savings {

	public:
		Unblocked(unsigned int id, double balance);
		Unblocked();
		double debit(double amount);	
};
#endif
