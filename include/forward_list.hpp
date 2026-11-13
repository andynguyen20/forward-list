#ifndef FORWARD_LIST_H
#define FORWARD_LIST_H

#include <iostream>
#include <memory>
#include <initializer_list>
#include <cstddef>
#include <utility>
#include <stdexcept>

template <typename T>
class ForwardList {
public:
    struct Node {
    public:
        std::unique_ptr<Node> next_node;
        T node_data;
        explicit Node(const T& data) : node_data(std::move(data)) { }
        ~Node() {std::cout << "Destroying node: " << node_data << '\n';}
        T return_data() {return node_data;}   
    };
private:
    std::unique_ptr<Node> head;
    Node* tail;
    std::size_t size_val = 0;
public:
    ForwardList();
    ForwardList(const T& head_val);
    Node* begin() {return head.get();}
    Node* end() {return tail;}
    int size();
    bool empty();
    void push_front(const T& val);
    void pop_front();
    void print();
    T& front();
    void insert_after(Node* pos, const T& val);
    void print_ptr();
};

template <typename T>
ForwardList<T>::ForwardList()
{

}

template <typename T>
ForwardList<T>::ForwardList(const T& head_val)
{
    std::unique_ptr<Node> head_temp = std::make_unique<Node>(head_val);
    head = std::move(head_temp);
    tail = head.get();
    size_val++;
}

template <typename T>
void ForwardList<T>::push_front(const T& val)
{
    std::unique_ptr<Node> node_temp = std::make_unique<Node>(val);
    node_temp.get()->next_node = std::move(head);
    head = std::move(node_temp);
    size_val++;
}

template <typename T>
void ForwardList<T>::pop_front()
{
    if (size_val == 0) {
        throw std::runtime_error{"ForwardList<T>::pop_front(): List is empty, cannot pop any elements"};
    }
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

template <typename T>
int ForwardList<T>::size() 
{
    std::cout << "ForwardList<T>::size(): size = " << size_val << '\n';
    return size_val;
}

template <typename T>
bool ForwardList<T>::empty() 
{
    if (size_val == 0) {
        std::cout << "ForwardList<T>::empty: List is empty\n";
        return true;
    } else {
        std::cout << "ForwardList<T>::empty: List is not empty\n";
        return false;
    }
}

template <typename T>
T& ForwardList<T>::front()
{
    if (!head) {
        throw std::runtime_error{"ForwardList<T>::front(): List is empty"};
    }
    return head.get()->node_data;
}

template <typename T>
void ForwardList<T>::insert_after(Node* pos, const T& val)
{
    Node* curr_node = head.get();
    while (curr_node != pos && curr_node != nullptr) {
        curr_node = curr_node->next_node.get();
    }
    if (!curr_node) {
        throw std::runtime_error{"ForwardList<T>::insert_after: could not find Node*."};
    }
    std::cout << "I also made it here\n";
    std::unique_ptr node_temp = std::make_unique<Node>(val);
    node_temp->next_node = std::move(curr_node->next_node);
    curr_node->next_node = std::move(node_temp);
}

template <typename T>
void ForwardList<T>::print_ptr()
{
    Node* curr_node = head.get();
    while (curr_node) {
        std::cout << "Value: " << curr_node->node_data << " | Address: " << curr_node << '\n';
        curr_node = curr_node->next_node.get();
    }
}
#endif