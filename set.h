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
					// Destructor 
					// Pre-condition A set exists
					// Post-condition: The set is destroyed
		                ~Set		( void );
					// Methosd for insertion into set
					// Pre-condition a valid item of type T
					// Post-condition the item is added to the set if it's not already present
           void		    insert		( const T &item);
		// Method to remove an item from the set
		// Pre-condition: A valid item of type T
		// Post-condtion: The item is removed
           void		    remove		( const T &item );
		// Method to get the number of item in the set
		// Pre-condition: None
		// Post-condtion: Returns the number of items in the set
           int		    cardinality	( void ) const;
		// Method to check if the set is empty
		// Pre-condition: None
		// Post-condtion: Returns true if the set is empty but otherwise false
           bool		    empty		( void ) const;
		// Method to check if a n item is in the set
		// Pre-condition: A valid item of type T
   		// Post-condition: Returns true if the item is in the set, otherwise false
           bool         contains    (const T& item) const;
		// Method for overloaded == operator to compare two sets
    		// Pre-condition: A valid Set object is provided
    		// Post-condition: Returns true if both sets are equal, otherwise false
           bool	        operator==	( const Set<T>& mySet ) const;
		// Method to check if the current set is a subset of another set
    		// Pre-condition: A valid Set object is provided
    		// Post-condition: Returns true if the current set is a subset of the provided set, otherwise false
           bool         operator<=  ( const Set<T>& mySet ) const;
		// Method to overloaded + operator for the union of two sets
    		// Pre-condition: A valid Set object is provided
    		// Post-condition: Returns a new set that is the union of the current set and the provided set
           Set<T>     operator+	( const Set<T> &mySet ) const;
		// Method to overloaded & operator for the intersection of two sets
    		// Pre-condition: A valid Set object is provided
    		// Post-condition: Returns a new set that is the intersection of the current set and the provided set
           Set<T>     operator&   (const Set<T>& mySet) const;
           Set<T>     operator-   (const Set<T>& mySet) const;
           void         clear       ( void );
           std::string  to_string   ( void ) const;
};

#endif
