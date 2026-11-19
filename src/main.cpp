#include "forward_list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        int n = 100;
        ForwardList<int> test_list{n};
        test_list.push_front(90);
        test_list.push_front(80);
        test_list.push_front(70);
        test_list.push_front(60);
        test_list.push_front(50);
        test_list.push_front(40);
        test_list.push_front(30);
        test_list.push_front(20);
        test_list.push_front(10);
        std::cout << "first loop: " << '\n';
        for (auto it = test_list.begin(); it != test_list.end(); ++it) {
            std::cout << *it << '\n';
        }
        std::cout << "second loop: " << '\n';
        for (const auto& value : test_list) {
            std::cout << value << '\n';
        }
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}