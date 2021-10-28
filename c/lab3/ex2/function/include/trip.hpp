/*
 * =====================================================================================
 *
 *       Filename:  trip.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/07/21 10:21:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

class Trip
{
	private:
		Date beg, end;
		float price;
		
	public:
		Trip(const unsigned int &beg_day, const unsigned int &beg_month, const unsigned int &beg_year,
			const unsigned int &end_day, const unsigned int &end_month,const unsigned int &end_year,
			const float &price);
		Trip(const Date &beg, const Date &end, const float &price);
		void print_trip();

};
