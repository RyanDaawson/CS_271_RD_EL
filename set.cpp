#include "set.h"

// Default constructor
template <class T>
Set<T>::Set()
{
    // Pre-condition: none
    // Post-condition: creates an empty set with head initialized to nullptr.
    head = nullptr; 
}

// Copy constructor
template <class T>
Set<T>::Set(const Set<T> &mySet)
{
    // Pre-condition: mySet is a valid set object.
    // Post-condition: creates a new set that is a copy of mySet.
    head = nullptr;
    Node *currentNode = mySet.head;  // Starts from the head of the set to be copied
    while (currentNode != nullptr)
    {
        insert(currentNode->item);  // Moves item from original set into the new set
        currentNode = currentNode->next; // Moves to the next node of the original set
    }
}

// Destructor
template <class T>
Set<T>::~Set()
{
    // Pre-condition: The Set object is initialized
    // Post-condition: Removes all the nodes
    clear(); 
}

// For insert into set
template <class T>
void Set<T>::insert(const T &item)
{
    // Pre-condition: The item is of the same type as the set elements.
    // Post-condition: Moves the item into the set if it is not already present
    
    if (!contains(item)) 
    {
        Node *newNode = new Node; 
        newNode->item = item; 
        newNode->next = head; 
        head = newNode; 
    }
}

// For removeing an item in the set
template <class T>
void Set<T>::remove(const T &item)
{
    // Pre-condition: The item is the same type as the set elements
    // Post-condition: Removes the item from the set if it is present
    
    Node *currentNode = head, *prevNode = nullptr;
    while (currentNode != nullptr)
    {
        if (currentNode->item == item) // Checks if the current node contains the item
        {
            if (prevNode == nullptr) // If the item is at the head of the list
            {
                head = currentNode->next; // Moves the head to the next node
            }
            else
            {
                prevNode->next = currentNode->next; // Links the node to the next node
            }
            delete currentNode;
            return;
        }
        prevNode = currentNode; // Moves to the next node in the list
        currentNode = currentNode->next;
    }
}

// For counting the number of items in a set 
template <class T>
int Set<T>::cardinality() const {
    
    // Pre-condition: None
    // Post-condition: Returns the number of elements in the set
    
    int count = 0;
    Node* currentNode = head;
    while (currentNode != nullptr) {
        count++; // Increments the count for the nodes 
        currentNode = currentNode->next; // Moves to the next 
    }
    return count;
}


// To check if an item is in the set
template <class T>
bool Set<T>::contains(const T& item) const {

    // Pre-condition: The item is of the same type as the set elements
    // Post-condition: Returns true if the item is in the set, false otherwise
    
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->item == item) {
            return true; // Returns if the item is found 
        }
        currentNode = currentNode->next;
    }
    return false; // Returns if the item is not found
}

// Checks if the set is empty 
template <class T>
bool Set<T>::empty() const {
    // Pre-condition: none
    // Post-condition: Returns true if the set is empty, false otherwise.
    return head == nullptr; 
}

// The == operator for comparing two sets
template <class T>
bool Set<T>::operator==(const Set<T>& mySet) const {

    // Pre-condition: mySet is a set object.
    // Post-condition: Returns true if the sets are equal, false otherwise.
    
    if (cardinality() != mySet.cardinality()) {
        return false;
    }
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (!mySet.contains(currentNode->item)) {
            return false;
        }
        currentNode = currentNode->next;
    }
    return true;
}

// To check if the current set is a subset
template <class T>
bool Set<T>::operator<=(const Set<T>& mySet) const {

    // Pre-condition: mySet is a set object.
    // Post-condition: Returns true if current set is a subset of mySet, false otherwise.
    
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (!mySet.contains(currentNode->item)) {
            return false;
        }
        currentNode = currentNode->next;
    }
    return true;
}

// For the Overloaded + operator for the two sets
template <class T>
Set<T> Set<T>::operator+(const Set<T>& mySet) const {
    
    // Pre-condition: mySet is a set object.
    // Post-condition: Returns a new set that is the union of the current set and mySet.
    
    Set<T> new;
    Node* currentNode = head;
    while (currentNode != nullptr) {
        newSet.insert(currentNode->item);
        currentNode = currentNode->next;
    }
    currentNode = mySet.head;
    while (currentNode != nullptr) {
        newSet.insert(currentNode->item);
        currentNode = currentNode->next;
    }
    return new;
}

// Overleaded & operator for the two sets
template <class T>
Set<T> Set<T>::operator&(const Set<T>& mySet) const{

    // Pre-condition: mySet is a set object.
    // Post-condition: Returns a new set that is the current set and mySet.
    
    Set<T> newSet;
    Node* currentNode = head;
    while (currentNode !=NULL){
        if (mySet.contains(currentNode->item))
        {
            newSet.insert(currentNode->item);
        }
        currentNode = currentNode -> next;
    }
    return newSet;
}

//difference
template <class T>
Set<T> Set<T>::operator-(const Set<T>& mySet) const {

    // Pre-condition: mySet is a set object.
    // Post-condition: Returns a new set that is difference of current and mySet
    
    Set<T> newSet;
    Node* currentNode = head;
    while (currentNode != NULL)
    {
        if (!mySet.contains(currentNode->item))
        {
            newSet.insert(currentNode->item);
        }
        currentNode = currentNode->next;
    }
    return newSet;
}

// For the clear
template <class T>
void Set<T>::clear()
{

    // Pre-condition: None
    // Post-condioton: Clears the set and deleting all its elements
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
}


// For converting the set to the string representation
template <class T>
std::string Set<T>::to_string() const
{
    // Pre-condition: None
    // Post-condtion: Returns a string representation of the set.
    std::stringstream ss;
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        ss << currentNode->item;
        if (currentNode->next != nullptr)
        {
            ss << " ";
        }
        currentNode = currentNode->next;
    }
    return ss.str();
}
