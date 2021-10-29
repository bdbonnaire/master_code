/*
 * =====================================================================================
 *
 *       Filename:  vectorized.hpp
 *
 *    Description: a vectorized version of ex 3 
 *
 *        Version:  1.0
 *        Created:  10/29/21 19:19:28
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <vector>
#include <ostream>

void init(std::vector<int>& c, int k, int start, int end);

template <class T> 
void apply_fact(const std::vector<int>& c, std::vector<T>& res);
template <class T>
std::ostream& operator<< (std::ostream& o, std::vector<T> &collec);
