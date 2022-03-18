#include <iostream>
#include <string>

#include "data_structures.hpp"


int main() {
    data_structures::list<int> l;
    std::cout << l.is_empty() << std::endl;
    l.push_back(111);
    l.push_back(111);
    l.push_back(111);
    l.push_back(3);
    l.push_back(111);
    l.push_back(23);
    l.push_back(324);
    l.push_back(111);
    l.push_back(111);
    l.push_back(447);
    l.push_back(111);
    l.push_back(111);
    std::cout << l.is_empty() << std::endl;
    l.print();
    std::cout << l.find(23) << std::endl; //выводит адрес, а не должен
    l.delete_first();
    l.print();
    l.delete_concrete(111);
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
return 0;
}
