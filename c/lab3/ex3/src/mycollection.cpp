/*
 * =====================================================================================
 *
 *       Filename:  mycollection.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/28/21 17:59:53
 *       Revision:  none
 *       Compiler:  g++
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#ifndef MYCOLLECTION_CPP
#define MYCOLLECTION_CPP

#include <ostream>
#include <stdlib.h>
#include "mycollection.hpp"
#include "factorial.hpp"

template <class T>
MyCollection<T>::MyCollection() : max_elem(200) {
	array = new T[max_elem];
	current_nbr = 0;
}

template <class T>
MyCollection<T>::~MyCollection()
{
	delete [] array;
}


/*
 *--------------------------------------------------------------------------------------
 *       Class:  MyCollection
 *      Method:  MyCollection :: get_elem
 * Description: get the element at index i 
 *--------------------------------------------------------------------------------------
 */
template <class T>
T MyCollection<T>::get_elem(int i) const
{
	if(i < current_nbr)
		return array[i];
	else
		throw("out of bound index");
}

template <class T>
void MyCollection<T>::insert_elem(T &elem)
{
	if(current_nbr != max_elem)
		array[current_nbr] = elem;
	else
		throw("Array is full");
}

template <class T>
int MyCollection<T>::get_size() const
{
	return current_nbr;
}

template <class T>
std::ostream& operator<< (std::ostream& o, MyCollection<T> &collec)
{
	for(int i=0; i<collec.current_nbr; i++)
		o << "[" << i << "] : " << collec.array[i] << "\n";
	return o;
}

//Definitions so that the linker doesn't go crazy
template std::ostream& operator<< (std::ostream& o, MyCollection<char> &collec);
template std::ostream& operator<< (std::ostream& o, MyCollection<short int> &collec);
template std::ostream& operator<< (std::ostream& o, MyCollection<int> &collec);
template std::ostream& operator<< (std::ostream& o, MyCollection<long int> &collec);
template std::ostream& operator<< (std::ostream& o, MyCollection<long long int> &collec);
template std::ostream& operator<< (std::ostream& o, MyCollection<__int128> &collec);
template class MyCollection<int>;
template class MyCollection<char>;
template class MyCollection<short int>;
template class MyCollection<long int>;
template class MyCollection<long long int>;
template class MyCollection<__int128>;
//-------------------- END MYCOLLECTION CLASS ---------------------------//

void init(MyCollection<int>& c, int k)
{
	// initialize k elements in the collection. The
	// elements are pseudo randoms between 0 and 12.
	srand(time(nullptr));
	for(int i=0; i<k; i++){
		int random = rand() % 13;
		c.insert_elem(random);
	}
}

void apply_fact(const MyCollection<int>& c, MyCollection<int>& res)
{
	//calculates the factorial of each element of c and put it in res
	for( int i=0; i<c.get_size(); i++){
		int facted = fact<int>(c.get_elem(i));
		res.insert_elem(facted);
	}
}

#endif
