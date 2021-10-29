/*
 * =====================================================================================
 *
 *       Filename:  bank_account.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/21 12:11:47
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
#include "bank_account.hpp"
#include "currencies.hpp"

template <class Type_currency>
Bank_account<Type_currency>::Bank_account(std::string name, Type_currency amount){
	this->amount = amount;	
	owner_name = name;
}

template <class Type_currency>
bool Bank_account<Type_currency>::credit_balance(){
	return amount.get_value();
}

template <class Type_currency>
std::ostream& operator<<(std::ostream &o, Bank_account<Type_currency> account)
{
	o << "-| ACCOUNT OF : " << account.owner_name << " |-\n" <<
		"|\n" <<
		"| -- balance : " << account.amount <<
		"|\n" <<
		"|______ Have A NCE DAY.\n\n";
	return o;
}

template std::ostream& operator<<(std::ostream &o, Bank_account<Dollar> account);
template std::ostream& operator<<(std::ostream &o, Bank_account<Euro> account);
template std::ostream& operator<<(std::ostream &o, Bank_account<Pounds> account);
