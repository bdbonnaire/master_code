/*
 * =====================================================================================
 *
 *       Filename:  mycollection.hpp
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
#ifndef MYCOLLECTION_HPP
#define MYCOLLECTION_HPP
#include <ostream>


/*
 * =====================================================================================
 *        Class:  MyCollection
 *  Description: General dynamic collection of elements.
 * =====================================================================================
 */
template <class T> class MyCollection;
template <class T>
std::ostream& operator<<(std::ostream&, MyCollection<T>&);
template < class T >
class MyCollection
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		MyCollection ();                             /* constructor */
		~MyCollection();

		/* ====================  ACCESSORS     ======================================= */
		T get_elem(int) const;
		int get_size() const;

		/* ====================  MUTATORS      ======================================= */
		void insert_elem(T&);

		/* ====================  OPERATORS     ======================================= */
		friend std::ostream& operator<< <>(std::ostream&, MyCollection<T>&);

	private:
		/* ====================  DATA MEMBERS  ======================================= */

		T *array;
		const int max_elem;
		int current_nbr;

}; /* ----------  end of template class MyCollection  ---------- */


/// initialize the collection with random int element
void init(MyCollection<int>&, int, int, int);
/// applies the factorial to every element in the first argument 
// and put them in the second one.
// The template is to choose the precision of the output to avoid
// overflow
// Available precision are :
// 	char, short int, int, long int, long long int, __int128
template <class T>
void apply_fact(const MyCollection<int>&, MyCollection<T>&);

#endif
