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
        ForwardList<int> test_list_2 = test_list;
        test_list.print();
        std::cout << "I made it here\n";
        test_list_2.print();
        std::cout << "done\n";
        test_list.print();
        test_list.size();
        test_list_2.size();
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}