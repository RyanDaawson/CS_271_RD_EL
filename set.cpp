#include <string>
#include <iostream>
#include "Set.h"

template <class T>
Set<T>::Set()
{
    head = nullptr;
    Node* currentNode = mySet.head;
    while (currentNode != nullptr) {
        insert(currentNode->item);
        currentNode = currentNode->next;
    }
}
