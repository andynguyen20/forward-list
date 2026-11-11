#include "forward_list.hpp"
#include <iomanip>
#include <iostream>

int main()
{
    int n = 30;
    ForwardList<int> test_list{n};
    std::cout << "&n: " << &n << " = n: " << n << '\n';
    std::cout << "&head: " << test_list.return_head() << " = head: " << test_list.return_head()->return_data() << '\n';
    std::cout << "&tail: " << test_list.return_tail() << " = tail: " << test_list.return_tail()->return_data() << '\n';    
    std::cout << "size: " << test_list.return_size() << '\n';
    
}