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
		// gets how many accounts were created and 
		// initialize the id as the incremented number
		// Updates the file by incremented value
		unsigned int get_and_update_nbrAccounts();

	public:
		Account(double balance=0);
		// returns the id of the account
		unsigned int operator()();

	// ---------------- Methods ---------------------


		// debits the account of amount a. Does not 
		// check the balance, it is a simple
		// substraction. Returns the amount debited.
		virtual double debit(double a) = 0;

		//adds a to the balance
		void credit(double a);
		// print the attributes to the specified ostream
		virtual void print(std::ostream &o);
		friend std::ostream& operator<<(std::ostream&, Account&);
};

std::ostream& operator<<(std::ostream&, Account&);

//========================================= CURRENT CLASS ================================

class Current : public Account {
	// Almost vanilla flavor. Only modifies the debit method 
	// checking that the client has enough to make the debit
	
	// Telling to use the constructor of parent class
	using Account::Account;
	public:
		double debit(double amount);	
		void print(std::ostream &o);
};

//========================================= SAVINGS CLASS ==========================
class Savings : public Account {
	private: 
		int interest_rate;
			
	public:
		Savings(double balance, float interest_rate);
		Savings();

		void add_interest();
		void print(std::ostream &o);

};

//=================================== BLOCKED CLASS ====================================
class Blocked : public Savings {

	public:
		Blocked(double balance=0);
		double debit(double amount);	
		void print(std::ostream &o);
};

//==================================== UNBLOCKED =======================================
class Unblocked : public Savings {

	public:
		Unblocked(double balance=0);
		double debit(double amount);	
		void print(std::ostream &o);
};
#endif
