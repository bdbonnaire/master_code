/*
 * =====================================================================================
 *
 *       Filename:  factorial.hpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/21 13:37:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef FACTORIAL_HPP
#define FACTORIAL_HPP
#include <ostream>

void multi_type_fact(int);

void fact_verbose(int n, int t);
template<class T> T fact(int);

std::ostream &operator<<(std::ostream&, __int128);
#endif
