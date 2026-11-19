#include "forward_list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        int n = 30;
        ForwardList<int> test_list{n};
        test_list.push_front(20);
        test_list.push_front(10);
        ForwardList<int> test_list_2 = std::move(test_list);
        test_list_2.print();
        test_list.print();
        test_list_2.size();
        test_list.size();
        test_list_2.front();
        test_list.front();
        test_list_2.back();
        test_list.back();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}