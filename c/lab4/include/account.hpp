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
		// The constructor is made protected so that no element different from child can
		// create a barebone bank account
		Account(unsigned int id, double balance);
		double balance;

		// ---------------- Methods ---------------------
		// debits the account of amount a. Does not check the balance, it is a simple
		// substraction. Returns the amount debited.
		double debit(double a);


	public:
		unsigned int get_id();
		//adds a to the balance
		void credit(double a);
		// print the attributes to the specified ostream
		void print(std::ostream &o);
};

//========================================= CURRENT CLASS ================================

class Current : public Account {
	public:
		Current(unsigned int id, double balance);
};

//========================================= SAVINGS CLASS ==========================
class Savings : public Account {
	private: 
		int interest_rate;
		Savings(unsigned int id, double balance, int interest_rate);
			
	public:
		void add_interest();
		void debit(double amount);	

};

//=================================== BLOCKED CLASS ====================================
class Blocked : public Savings {

	public:
		Blocked(unsigned int id, double balance);
};

//==================================== UNBLOCKED =======================================
class Unblocked : public Savings {

	public:
		Unblocked(unsigned int id, double balance);
};
#endif
