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
 *       Compiler:  gcc
 *
 *         Author:  Basile Dubois Bonnaire (), bdbonnaires@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */
#include <ostream>
#include <stdlib.h>
#include "mycollection.hpp"

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
T MyCollection<T>::get_elem(int i)
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
std::ostream& operator<<(std::ostream& o, MyCollection<T> &collec)
{
	for(int i=0; i<collec.current_nbr; i++)
		o << "[" << i << "] : " << collec.array[i] << "\n";
	return o;
}
