/*
 * =====================================================================================
 *
 *       Filename:  PPoint.hpp
 *
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/05/21 10:39:55
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */

/**
 * \file PPoint.hpp
 * \brief header defining the PPoint and Array of PPoint classes 
 **/

/// class defining a 2D point
/**
 * the coordinates are integers dynamically allocated representing a
 * point in a cartesian plane.
 */
class PPoint
{
	private:
		/// coordinates of the 2D points
		int *x, *y; 
	public:
		PPoint(const int &x=0,const int &y=0);
		PPoint(const PPoint &point);
		~PPoint();

		void add(const PPoint &p); ///adds two PPoint together
		/// sets the coordinates of the PPoint to the given x and y
		void set_coordinates(const int &x,const int &y);
		void print();
};


/// A class defining an array of PPoints.
/**
 * the PPoints are stored dynamically, its size being given at
 * construction. 
 */
class Array_of_PPoint
{
	private:
		/// pointer to the array's beginning
		PPoint *array; 
		/// size of the array
		unsigned int length; 
	public:
		Array_of_PPoint(const unsigned int &len);
		Array_of_PPoint(const unsigned int &len,
				const unsigned int &x0,
				const unsigned int &x1,
				const unsigned int &y0,
				const unsigned int &y1
				);
		Array_of_PPoint(const PPoint &p);
		Array_of_PPoint(const Array_of_PPoint &p);
		~Array_of_PPoint();

		void add(const PPoint &p);
		void print_tabs();
};
