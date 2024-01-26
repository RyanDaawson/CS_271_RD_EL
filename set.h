#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#ifndef SET_H
#define SET_H

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
           void		    insert		( const T &item);
           void		    remove		( const T &item );
           int		    cardinality	( void ) const;
           bool		    empty		( void ) const;
           bool         contains    (const T& item) const;
           bool	        operator==	( const Set<T>& mySet ) const;
           bool         operator<=  ( const Set<T>& mySet ) const;
           //Set<T>     operator+	( const Set<T> &mySet ) const;
           //Set<T>     operator&   (const Set<T>& mySet) const;
           //Set<T>     operator-   (const Set<T>& mySet) const;
           void         clear       ( void );
           std::string  to_string   ( void ) const;


};

#endif