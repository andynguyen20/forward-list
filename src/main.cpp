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
        int m = 10;
        ForwardList<int> test_list_2 {m};
        test_list_2.push_front(20);
        test_list_2.push_front(30);
        test_list_2.push_front(40);
        test_list_2.push_front(50);
        test_list.print();
        test_list_2.print();
        test_list_2.size();
        std::cout << "head value: " << test_list_2.front() << '\n';
        std::cout << "tail value: " << test_list_2.back() << '\n';
        test_list_2 = test_list;
        test_list_2.print();
        std::cout << "head value: " << test_list_2.front() << '\n';
        std::cout << "tail value: " << test_list_2.back() << '\n';
        test_list_2.size();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}