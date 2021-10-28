/*
 * =====================================================================================
 *
 *       Filename:  date.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  21/09/2021 12:06:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <ctime>

class Date
{
	private:
		int day, month, year;
		char* dayName;

	public:
		Date(const unsigned int &d=1, const unsigned int &m=1, const unsigned int &y=1970);
		Date(const time_t &time);
		Date(Date &date); 	//copy constructor
		~Date();			//destructor

		const char* make_month_readable();
		void print_date();
		void happy_birthday(const char* n, Date b);

		bool before(const Date &d);
		int difference(const Date &d);
		int duration(const Date &d);

		bool operator<(const Date&);
		int operator-(const Date&);
};
