/*
 * =====================================================================================
 *
 *       Filename:  currencies.hpp
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
#include <ostream>

class Dollar{
	private:
		const float amount;
	public:
		Dollar(const float);
		float get_value();
};

std::ostream& operator<<(std::ostream&, Dollar&);

class Euro{
	private:
		const float amount;
	public:
		Euro(const float);
		float get_value();
};
std::ostream& operator<<(std::ostream&, Euro&);

class Pounds{
	private:
		const float amount;
	public:
		Pounds(const float);
		float get_value();
};
std::ostream& operator<<(std::ostream&, Pounds&);
