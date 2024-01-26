#include "set.h"

template <class T>
Set<T>::Set()
{
    head = nullptr
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

template <class T>
void Set<T>::insert(const T& item) {
    if (!contains(item)) {
        Node* newNode = new Node;
        newNode->item = item;
        newNode->next = head;
        head = newNode;
    }
}
