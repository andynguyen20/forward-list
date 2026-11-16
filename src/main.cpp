#include "forward_list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        int n = 50;
        ForwardList<int> test_list{n};
        test_list.push_front(40);
        test_list.push_front(30);
        test_list.push_front(20);
        test_list.push_front(10);
        test_list.clear();
        std::cout << "I cleared before this print statement\n";
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}