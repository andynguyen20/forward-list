#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include "node.hpp"

#include <memory>
#include <initializer_list>
#include <cstddef>

template <typename T>
class ForwardList {
private:
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    std::size_t size = 0;
public:
    ForwardList();
    explicit ForwardList(std::initializer_list<T> list_values);
};

template <typename T>
ForwardList<T>::ForwardList()
{

}


#endif