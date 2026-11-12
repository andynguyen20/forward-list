#include "forward_list.hpp"
#include <iostream>

int main()
{
    int n = 50;
    ForwardList<int> test_list{n};
    test_list.push_front(40);
    test_list.push_front(30);
    test_list.push_front(20);
    test_list.push_front(10);
    test_list.print();
}