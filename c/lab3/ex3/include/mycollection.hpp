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


void init(MyCollection<int>&, int);
void apply_fact(const MyCollection<int>&, MyCollection<int>&);

#endif
