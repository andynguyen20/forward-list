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
    ForwardList(T head_value);
    Node<T>* return_head() {return head.get();}
    Node<T>* return_tail() {return tail;}
    int return_size() {return size;}
};

template <typename T>
ForwardList<T>::ForwardList()
{

}

template <typename T>
ForwardList<T>::ForwardList(T head_value)
{
    std::unique_ptr<Node<T>> head_temp = std::make_unique<Node<T>>(head_value);
    head = std::move(head_temp);
    size++;
    tail = head.get();
}



#endif