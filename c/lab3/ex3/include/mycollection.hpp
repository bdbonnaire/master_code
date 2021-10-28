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
template < class T >
class MyCollection
{
	public:
		/* ====================  LIFECYCLE     ======================================= */
		MyCollection ();                             /* constructor */
		~MyCollection();

		/* ====================  ACCESSORS     ======================================= */
		T get_elem(int) const;

		/* ====================  MUTATORS      ======================================= */
		void insert_elem(T&);

		/* ====================  OPERATORS     ======================================= */
		template <class T2>
		friend std::ostream& operator<<(std::ostream&, MyCollection<T2>&);

	private:
		/* ====================  DATA MEMBERS  ======================================= */

		T *array;
		const int max_elem;
		int current_nbr;

}; /* ----------  end of template class MyCollection  ---------- */

template <class T2>
std::ostream& operator<<(std::ostream&, MyCollection<T2>&);

#endif
