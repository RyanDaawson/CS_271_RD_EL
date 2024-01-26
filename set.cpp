#include "set.h"

// Default constructor
template <class T>
Set<T>::Set()
{
    head = nullptr; // Initializes the head of the linked list to nullptr.
}

// Copy constructor
template <class T>
Set<T>::Set(const Set<T> &mySet)
{
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
    clear(); // Clears the set
}

// For insert into set
template <class T>
void Set<T>::insert(const T &item)
{
    if (!contains(item)) //  checking to see if it is not already in set
    {
        Node *newNode = new Node; // Creates the new node
        newNode->item = item; // Assigns the node
        newNode->next = head; // points to the new node in the head
        head = newNode; // Makes the new node the new head for the list
    }
}

// For removeing an item in the set
template <class T>
void Set<T>::remove(const T &item)
{
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
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (currentNode->item == item) {
            return true;
        }
        currentNode = currentNode->next;
    }
    return false;
}

//empty
template <class T>
bool Set<T>::empty() const {
    return head == nullptr;
}

//==operator
template <class T>
bool Set<T>::operator==(const Set<T>& mySet) const {
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

//subset
template <class T>
bool Set<T>::operator<=(const Set<T>& mySet) const {
    Node* currentNode = head;
    while (currentNode != nullptr) {
        if (!mySet.contains(currentNode->item)) {
            return false;
        }
        currentNode = currentNode->next;
    }
    return true;
}

//union
template <class T>
Set<T> Set<T>::operator+(const Set<T>& mySet) const {
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

//intersection
template <class T>
Set<T> Set<T>::operator&(const Set<T>& mySet) const{
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

//clear
template <class T>
void Set<T>::clear()
{
    Node *currentNode = head;
    while (currentNode != nullptr)
    {
        Node *nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = nullptr;
}


// to_string
template <class T>
std::string Set<T>::to_string() const
{
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
