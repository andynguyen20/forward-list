#include "forward_list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        int n = 50;
        ForwardList<int> test_list;
        ForwardList<int> test_list_2{n};
        test_list_2.push_front(40);
        test_list_2.push_front(30);
        test_list_2.push_front(20);
        test_list_2.push_front(10);
        test_list_2.print();
        test_list_2.front();
        test_list_2.back();
        test_list.print();
        test_list = std::move(test_list_2);
        test_list_2.print();
        test_list.print();
        test_list.front();
        test_list.back();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}