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
		T		item; // Value for the node
		Node 	*next; // Pointer for the node in the set
	};
	
    Node	*head; // Pointer to the first node

public:
	// Default constructor
	// Pre-condition: None
	// Post-condition: Creates an empty set
			            Set		    ( void );
					// Copy constructor
					// Pre-condition: A valid Set object is given.
					// Post-condition: Creates a new set that copys the given set
			            Set		    ( const Set<T> &mySet );
		                ~Set		( void );
           void		    insert		( const T &item);
           void		    remove		( const T &item );
           int		    cardinality	( void ) const;
           bool		    empty		( void ) const;
           bool         contains    (const T& item) const;
           bool	        operator==	( const Set<T>& mySet ) const;
           bool         operator<=  ( const Set<T>& mySet ) const;
           Set<T>     operator+	( const Set<T> &mySet ) const;
           Set<T>     operator&   (const Set<T>& mySet) const;
           Set<T>     operator-   (const Set<T>& mySet) const;
           void         clear       ( void );
           std::string  to_string   ( void ) const;
};

#endif
