#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <memory>
#include <initializer_list>
#include <cstddef>
#include <utility>

template <typename T>
class ForwardList {
private:
    template <typename T>
    struct Node {
    private:
        std::unique_ptr<Node<T>> next_node;
        T node_data;
    public:
        explicit Node(T data) : node_data(std::move(data)) { }
        T return_data() {return node_data;}   
    };
    std::unique_ptr<Node<T>> head;
    Node<T>* tail;
    std::size_t size_val = 0;
public:
    ForwardList();
    ForwardList(T head_val);
    Node<T>* return_head() {return head.get();}
    Node<T>* return_tail() {return tail;}
    int size() {return size_val;}
    bool empty() {return !size_val;}
    void push_front(T val);
};

template <typename T>
ForwardList<T>::ForwardList()
{

}

template <typename T>
ForwardList<T>::ForwardList(T head_val)
{
    std::unique_ptr<Node<T>> head_temp = std::make_unique<Node<T>>(head_val);
    head = std::move(head_temp);
    size_val++;
    tail = head.get();
}

template <typename T>
void ForwardList<T>::push_front(T val)
{
    std::unique_ptr<Node<T>> node_temp = std::make_unique<Node<T>>(val);
    node_temp.next_node = std::move(head);
    head = std::move(node_temp);
    size_val++;
}

#endif