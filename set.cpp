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

// clear
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
