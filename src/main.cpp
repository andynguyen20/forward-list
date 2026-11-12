#include "forward_list.hpp"
#include <iostream>

int main()
{
    int n = 30;
    ForwardList<int> test_list{n};
    std::cout << test_list.return_head() << '\n';
    std::cout << test_list.size() << '\n';
    test_list.push_front(10);
    std::cout << test_list.return_head() << '\n';
    std::cout << test_list.size() << '\n';
}