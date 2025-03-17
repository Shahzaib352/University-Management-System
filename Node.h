#ifndef NODE_H
#define NODE_H

template<typename T>
// structure of Node
    class Node{
        public::
        // Attributes
        T data;
        Node* next;

        // Constructor
        Node(T value) : data(value), next(nullptr) {}
    };

#endif