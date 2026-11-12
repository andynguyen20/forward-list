#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
#include <memory>
#include <initializer_list>
#include <cstddef>
#include <utility>

template <typename T>
class ForwardList {
private:
    struct Node {
    public:
        std::unique_ptr<Node> next_node;
        T node_data;
        explicit Node(T data) : node_data(std::move(data)) { }
        ~Node() {std::cout << "Destroying node: " << node_data << '\n';}
        T return_data() {return node_data;}   
    };
    std::unique_ptr<Node> head;
    Node* tail;
    std::size_t size_val = 0;
public:
    ForwardList();
    ForwardList(T head_val);
    Node* return_head() {return head.get();}
    Node* return_tail() {return tail;}
    int size() {return size_val;}
    bool empty() {return !size_val;}
    void push_front(T val);
    void pop_front();
    void print();
    int bytes();
};

template <typename T>
ForwardList<T>::ForwardList()
{

}

template <typename T>
ForwardList<T>::ForwardList(T head_val)
{
    std::unique_ptr<Node> head_temp = std::make_unique<Node>(head_val);
    head = std::move(head_temp);
    tail = head.get();
    size_val++;
}

template <typename T>
void ForwardList<T>::push_front(T val)
{
    std::unique_ptr<Node> node_temp = std::make_unique<Node>(val);
    node_temp.get()->next_node = std::move(head);
    head = std::move(node_temp);
    size_val++;
}

template <typename T>
void ForwardList<T>::pop_front()
{
    std::unique_ptr<Node> node_temp = std::move(head);
    head = std::move(node_temp.get()->next_node);
    size_val--;
}

template <typename T>
void ForwardList<T>::print()
{
    Node* temp = head.get();
    std::cout << "ForwardList<T>::print(): ";

    while (temp) {
        std::cout << temp->return_data() << " -> ";
        temp = temp->next_node.get();
    }
    std::cout << "NULL\n";
}



#endif