
    head = nullptr;
    Node* currentNode = mySet.head;
    while (currentNode != nullptr) {
        insert(currentNode->item);
        currentNode = currentNode->next;
    }
}

