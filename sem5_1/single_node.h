//
// Created by Andrey Ignatov on 14.05.2024.
//

#ifndef SINGLE_NODE_H
#define SINGLE_NODE_H

template <class T>
class Node {
    // private:
    T _value;
    Node *_next = nullptr;

public:
    Node(T value); //  { this->_value = value; };
    ~Node();
    void append(Node *next);
    T get_value(); // { return this->_value; };
    Node* get_next();
};

#endif //SINGLE_NODE_H
