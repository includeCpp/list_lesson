#include <iostream>
#include <string>

#include "data_structures.hpp"


int main() {
    data_structures::list<int> l;
    data_structures::list<int> l2; 
    std::cout << l.is_empty() << std::endl;
    l.push_back(111);
    l.push_back(3);
    l.push_back(111);
    l.push_back(23);
    l.push_back(324);
    l.push_back(111);
    std::cout << l.is_empty() << std::endl;
    l.print();
    std::cout << l.find(23) << std::endl;
    l.delete_first();
    l.print();
    l.delete_concrete(111);
    l.print();
    std::cout << l.size() << std::endl;
    l.push_back(224);
    l.push_back(112);
    l.push_back(38);
    l.push_back(21);
    std::cout << l.size() << std::endl;
    l.print();
    l.insert(5, 44);
    std::cout << l.size() << std::endl;
    l.print();
    std::cout << l.find_index(5) << std::endl;
    l2.push_back(44);
    l2.push_back(34);
    l2.push_back(67);
    l2.print();
    l2 = l;
    l2.print();
    l2.insert(4, 55);
    l2.print();
    l2.delete_concrete(112);
    l2.print();
    l.delete_first();
    l.delete_first();
    l.print();
    l2.delete_last();
    l2.delete_last();
    std::cout << l.size() << std::endl;
    std::cout << l2.size() << std::endl;
    std::cout << l2.is_empty() << std::endl;
return 0;
}
