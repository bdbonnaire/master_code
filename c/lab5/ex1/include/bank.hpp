/*
 * =====================================================================================
 *
 *       Filename:  bank.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/27/21 23:11:15
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <map>
#include "client.hpp"
#include "ostream"

class Bank {
	private:
		std::map<unsigned int, Client*> clients;

	public:
		void insertClient(Client&);
		friend std::ostream& operator<<(std::ostream &, Bank&);
};

std::ostream& operator<<(std::ostream &, Bank&);
