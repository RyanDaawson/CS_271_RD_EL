#ifndef SET_H
#define SET_H

#include <iostream>
#include <string>

using namespace std;

template <class T> 
class Set
{
private:
	struct Node
	{
		T		item;
		Node 	*next;
	};
	
    Node	*head;		// the pointer for the linked list

public:
			        Set		    ( void );
			        Set		    ( const Set<T> &mySet );
		            ~Set		( void );
           void		insert		( const T &item, int index );
           void		remove		( int index );
           int		cardinality	( void ) const;
           bool		isEmpty		( void ) const;
           bool     contains    (const T& item) const;
           bool	    operator==	( void ) const;
           bool     operator<=  ( void ) const;
           Set<T>   operator+	( const Set<T> &mySet ) const;
           Set<T>   operator&   (const Set<T>& mySet) const;
           Set<T>   operator-   (const Set<T>& mySet) const;

}
#include "Set.cpp"
#endif


