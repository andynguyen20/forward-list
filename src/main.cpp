#include "forward_list.hpp"
#include <iostream>
#include <stdexcept>

int main()
{
    try {
        int n = 50;
        ForwardList<int> test_list{n};
        test_list.push_front(40);
        ForwardList<int>::Node* index_ptr = test_list.begin();
        test_list.print();
        test_list.insert_after(index_ptr, 45);
        test_list.print();


        
    } catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << '\n';
    }
    return 0;
}