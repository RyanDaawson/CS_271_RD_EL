#include "set.h"

template <class T>
Set<T>::Set()
{
    head = nullptr;
}

template <class T>
Set<T>::Set(const Set<T> &mySet)
{
    head = nullptr;
    Node *currentNode = mySet.head;
    while (currentNode != nullptr)
    {
        insert(currentNode->item);
        currentNode = currentNode->next;
    }
}

template <class T>
Set<T>::~Set()
{
    clear();
}

// insert
template <class T>
void Set<T>::insert(const T &item)
{
    if (!contains(item))
    {
        Node *newNode = new Node;
        newNode->item = item;
        newNode->next = head;
        head = newNode;
    }
}

// remove
template <class T>
void Set<T>::remove(const T &item)
{
    Node *currentNode = head, *prevNode = nullptr;
    while (currentNode != nullptr)
    {
        if (currentNode->item == item)
        {
            if (prevNode == nullptr)
            {
                head = currentNode->next;
            }
            else
            {
                prevNode->next = currentNode->next;
            }
            delete currentNode;
            return;
        }
        prevNode = currentNode;
        currentNode = currentNode->next;
    }
}

//cardinality
template <class T>
int Set<T>::cardinality() const {
    int count = 0;
    Node* currentNode = head;
    while (currentNode != nullptr) {
        count++;
        currentNode = currentNode->next;
    }
    return count;
}


//contains
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
    Set<T> resultSet;
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
    return resultSet;
}

//intersection


//difference
template <class T>
Set<T> Set<T>::operator-(const Set<T>& mySet) const {
    Set<T> newSet;
    Node* currentNode = head;
    while (currentNode != NULL){
        if (!mySet.contains(currentNode->item)){
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