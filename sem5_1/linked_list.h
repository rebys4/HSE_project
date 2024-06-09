
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <vector>
#include <iostream>
#include "single_node.h"
#include "single_node.cpp"

template <class T>
class LinkedList {
    Node<T> *_root = nullptr;
    Node<T> *_end = nullptr;
    unsigned int _size = 0;

public:
    LinkedList() {

    }

    LinkedList(std::vector<T> &array) {
        for (int i = 0; i < array.size(); i++) {
            this->add_value(array[i]);
        }
        this->_size = array.size();
    }

    ~LinkedList() {
        if (this->_root != nullptr) {
            delete this->_root;
            this->_root = nullptr;
            this->_end = nullptr;
        }
    }
    void add_value(T value) {
        auto *new_node = new Node<T>(value);
        if (this->_root == nullptr) {
            this->_root = this->_end = new_node;
        } else {
            this->_end->append(new_node);
            this->_end = new_node;
        }
        this->_size++;
    }
    void add_value(T value, unsigned int tgt_ind) {
        if (tgt_ind >= this->_size) {
            return add_value(value);
        }
        Node<T>* current = this->_root;
        for (int i = 0; i < tgt_ind - 1; i++) {
            current = current->get_next();
        }
        auto *new_node = new Node<T> (value);
        new_node->append(current->get_next());
        current->append(new_node);
        this->_size++;
    }

    bool remove_value(T value) {
        if (this->_root == nullptr) {
            return false;
        }
        auto current = this->_root;
        if (this-_root->get_value() == value) {
            auto next = this->_root->get_next();
            this->_root->append(nullptr);
            delete this->_root;
            this->_root = next;
            this->_size--;
            return true;
        }
        while (current->get_next() != nullptr) {
            if (current->get_next()->get_value() == value) {
                auto next_next = current->get_next()->get_next();
                current->get_next()->append(nullptr);
                delete current->get_next();
                current->append(next_next);
                this->_size--;
                return true;
            }
            current = current->get_next();
        }


        //TODO: !!!

        return false;
    }
    bool set_value(unsigned int ind, T value);
    T get_value(unsigned int ind);
    void print() {
        auto current = this->_root;
        while (current != nullptr) {
            std::cout << current->get_value() << " ";
            current = current->get_next();
        }
        std::cout << "\n";
    }
};


#endif //LINKED_LIST_H
