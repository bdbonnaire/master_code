/*
 * =====================================================================================
 *
 *       Filename:  tripmain.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/07/21 11:58:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "date.hpp"
#include "trip.hpp"

int main()
{
	Date beg_paris(22,3,2001), end_paris(12,3,2003);
	Trip Moscow(12,9,1999,30,9,1999, 1053.42), Paris(beg_paris, end_paris, 100000.34);

	Moscow.print_trip();
	Paris.print_trip();
}
