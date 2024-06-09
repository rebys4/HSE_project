//
// Created by Andrey Ignatov on 14.05.2024.
//

#include "single_node.h"

template <class T>
Node<T>::Node(T value) {
    this->_value = value;
}

template <class T>
void Node<T>::append(Node *next) {
    this->_next = next;
}

template <class T>
T Node<T>::get_value() {
    return this->_value;
}

template <class T>
Node<T>::~Node() {
    if (this->_next != nullptr) {
        delete this->_next;
        this->_next = nullptr;
    }
    // delete this->_value;
}

template <class T>
Node<T>* Node<T>::get_next() {
    return this->_next;
}
