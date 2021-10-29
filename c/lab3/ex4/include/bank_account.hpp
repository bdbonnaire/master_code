/*
 * =====================================================================================
 *
 *       Filename:  bank_account.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/29/21 11:53:40
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

/*
 * =====================================================================================
 *        Class:  Bank_account
 *  Description: A representation of a bank account, regadless of the currency 
 * =====================================================================================
 */
#include <string>

template < class Type_currency >
class Bank_account
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		Bank_account (std::string name, Type_currency amount);                             /* constructor */
//		Bank_account(Bank_account&);            /* copy constructor */
//		~Bank_account();

		/* ====================  ACCESSORS     ======================================= */
		bool credit_balance();

		/* ====================  MUTATORS      ======================================= */

		/* ====================  OPERATORS     ======================================= */

	private:
		/* ====================  DATA MEMBERS  ======================================= */
	Type_currency amount;
	std::string owner_name;

}; /* ----------  end of template class Bank_account  ---------- */

