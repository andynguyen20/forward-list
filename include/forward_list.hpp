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
        Node(const Node& node) {node_data = node.node_data; 
                                next_node = std::make_unique<Node>(node.next_node->node_data);} 
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
    ~ForwardList();
    ForwardList(const T& head_val);
    ForwardList(const ForwardList& list);
    ForwardList(ForwardList&& list);
    ForwardList& operator=(ForwardList& list);
    ForwardList& operator=(ForwardList&& list);
    Node* begin() {return head.get();}
    Node* end() {return tail;}
    int size();
    bool empty();
    void push_front(const T& val);
    void pop_front();
    void print();
    T& front();
    T& back();
    void insert_after(Node* pos, const T& val);
    void print_ptr();
    void erase_after(Node* pos);
    void clear();
};

template <typename T>
ForwardList<T>::ForwardList()
{

}

template <typename T>
ForwardList<T>::~ForwardList()
{
    clear();
    std::cout << "ForwardList<T>::~ForwardList() destructed\n";
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
ForwardList<T>::ForwardList(const ForwardList& list)
{
    if (!list.head.get()) {
        return;
    }
    Node* copy_ptr = list.head.get();
    head = std::make_unique<Node>(*copy_ptr);
    Node* it_ptr = head.get();
    copy_ptr = copy_ptr->next_node.get();
    while (copy_ptr->next_node.get()) {
        it_ptr->next_node = std::make_unique<Node>(*copy_ptr);
        it_ptr = it_ptr->next_node.get();
        copy_ptr = copy_ptr->next_node.get();
    }
    tail = list.tail;
    size_val = list.size_val;
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList& list)
{
    this->clear();
    if (!list.head.get()) {
        return *this;
    }
    Node* copy_ptr = list.head.get();
    head = std::make_unique<Node>(*copy_ptr);
    Node* it_ptr = head.get();
    copy_ptr = copy_ptr->next_node.get();
    while (copy_ptr->next_node.get()) {
        it_ptr->next_node = std::make_unique<Node>(*copy_ptr);
        it_ptr = it_ptr->next_node.get();
        copy_ptr = copy_ptr->next_node.get();
    }
    tail = list.tail;
    size_val = list.size_val;
    return *this;
}

template <typename T>
ForwardList<T>::ForwardList(ForwardList&& list)
{
    if (!list.head.get()) {
        list.clear();
        return;
    }
    tail = list.tail;
    size_val = list.size_val;
    list.tail = nullptr;
    list.size_val = 0;
    head = std::move(list.head);
}

template <typename T>
ForwardList<T>& ForwardList<T>::operator=(ForwardList&& list)
{
    if (!list.head.get()) {
        list.clear();
        return *this;
    }
    tail = list.tail;
    size_val = list.size_val;
    list.tail = nullptr;
    list.size_val = 0;
    head = std::move(list.head);
    return *this;
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
    std::cout << "ForwardList<T>::front(): front = " << head.get()->node_data << '\n';
    return head.get()->node_data;
}

template <typename T>
T& ForwardList<T>::back()
{
    if (!tail) {
        throw std::runtime_error{"ForwardList<T>::back(): List is empty"};
    }
    std::cout << "ForwardList<T>::back(): back = " << tail->node_data << '\n';
    return tail->node_data;
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

template <typename T>
void ForwardList<T>::erase_after(Node* pos)
{
    Node* curr_node = head.get();
    while (curr_node != pos && curr_node != nullptr) {
        curr_node = curr_node->next_node.get();
    }
    if (!curr_node) {
        throw std::runtime_error{"ForwardList<T>::insert_after: could not find Node*."};
    }
    std::unique_ptr destructed_node = std::move(curr_node->next_node);
    curr_node->next_node = std::move(destructed_node->next_node);
}

template <typename T>
void ForwardList<T>::clear()
{
    if (!head.get()) {
        return;
    }
    std::unique_ptr<Node> curr_node = std::move(head);
    std::unique_ptr<Node> next = std::move(curr_node->next_node);
    while (curr_node && next) {
        curr_node.reset();
        curr_node = std::move(next);
        next = std::move(curr_node->next_node);
    }
    size_val = 0;
    tail = nullptr;
}

#endif