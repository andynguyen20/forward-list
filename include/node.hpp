#ifndef NODE_H
#define NODE_H

#include <memory>

template <typename T>
class Node {
private:
    std::unique_ptr<T> next_node;
    T node_data;
public:
    Node(T data);
    T return_data() {return node_data;}
};

template <typename T>
Node<T>::Node(T data)
    : node_data(data)
{

}


#endif