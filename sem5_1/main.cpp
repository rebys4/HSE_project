#include <iostream>
#include "linked_list.h"
//#include "single_node.h"
//#include "single_node.cpp"

int main()
{
    auto list1 = new LinkedList<int>();
    list1->add_value(1);
    list1->add_value(1);
    list1->add_value(1);
    list1->add_value(1);
    list1->add_value(1);
    list1->add_value(2, 3);
    list1->add_value(0, 123123);

    list1->print();

    delete list1;
//    Node<int> *node1 = new Node<int>(5);
//    Node<int> *node2 = new Node<int>(0.5);
//
//    std::cout << node2->get_value() << std::endl;
//    node1->append(node2);
//
//    delete node1;
//    // delete node2;

    return 0;
}
