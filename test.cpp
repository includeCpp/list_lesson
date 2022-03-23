#include <iostream>
#include <string>

#include "data_structures.hpp"

template<typename T>
std::string test_1(T value_1, T value_2, T value_3){
	data_structures::list<T> l;
	l.push_back(value_1);
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_3);
	l.push_back(value_3);
	if(l.size() != 5){
		return "Failed. Size test.";
	}
	l.delete_first();
	l.delete_first();
	if(l.size() != 3 || l[0] != value_2){
		return "Failed. Delete_first test.";
	}
	l.delete_last();
	l.delete_last();
	if(l.size() != 1 || l[0] != value_2){
		return "Failed. Delete_last test.";	
	}
	return "Passed";

}

template<typename T>
std::string test_2(T value_1, T value_2){
	int rval = 0;
	data_structures::list<T> l;
	if(l.is_empty()){
		rval++;
	}
	l.push_back(value_1);
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_1);
	l.push_back(value_1);
	if(l.is_empty()){
		rval--;
	}
	if(!l.is_empty()){
		rval++;
	}
	if(rval != 2){
		return "Failed. Empty test.";
	}
	l.delete_concrete(value_2);
	if(l.size() != 4 || l[2] == value_2){
		if(l.size() != 4){
			return "Failed. Size.";
		}
		return "Failed. Delete concrete test.";
	}
	l.insert(1, value_2);
	l.insert(3, value_2);
	if(l.size() != 6 || l[1] != value_2 || l[3] != value_2){
		if(l.size() != 6){
			return "Failed. Size.";
		}
		return "Failed. Insert test.";	
	}
	T val_t;
	l.insert(4, val_t);
	if(l.size() != 7 || l[4] != val_t){
		return "Failed. Find index test.";	
	}
	return "Passed";
}

template<typename T>
std::string test_3(T value_1, T value_2, T value_3, T value_4, T value_5){
	data_structures::list<T> l;
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_3);
	l.push_back(value_4);
	l.push_back(value_5);
	data_structures::list<T> l2;
	l2.push_back(value_5);
	l2.push_back(value_4);
	l2.push_back(value_3);
	l2.push_back(value_2);
	l2.push_back(value_1);
	l = l2;
	l.print();
	if(l[3] != value_2){
		return "Failed";
	}
	return "Passed";
}

template<typename T>
std::string test_4(T value_1, T value_2, T value_3){
	data_structures::list<T> l;
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_3);
	l.push_back(value_2);
	l.push_back(value_3);
	std::cout << std::endl;
	data_structures::Node<T>* rval = l.find(value_3);
	std::cout << rval -> value << std::endl;
	std::cout << l[2] << std::endl;
	std::cout << l.find(value_3) << std::endl;
	std::cout << &l[2] << std::endl;
	return "Passed";
}

int main(){

	std::cout << std::endl;
	std::cout << "Test 1." << std::endl;
	std::cout << "Includes: size(), push_back(), delete_first(), delete_last()." << std::endl;
	std::cout << std::endl;
	std::cout << "test 1.1: "<< test_1(113, 34, 55) << std::endl;
	std::cout << "test 1.2: "<< test_1("test 1", "test 2", "test 3") << std::endl;
	std::cout << "test 1.3: "<< test_1("a", "c", "b") << std::endl;
	std::cout << "test 1.4: "<< test_1(2.03, 14.75, 44.01) << std::endl;
	std::cout << std::endl;
	std::cout << "Test 2." << std::endl;
	std::cout << "Includes: is_empty(), delete_concrete(), insert(), find_index()." << std::endl;
	std::cout << std::endl;
	std::cout << "test 2.1: "<< test_2(15, 277) << std::endl;
	std::cout << "test 2.2: "<< test_2("test 2.1", "test 2.2") << std::endl;
	std::cout << "test 2.3: "<< test_2("g", "p") << std::endl;
	std::cout << "test 2.4: "<< test_2(2.34, 15.89) << std::endl;
	std::cout << std::endl;
	std::cout << "Test 3." << std::endl;
	std::cout << "Includes: print(), test operator \"=\"." << std::endl;
	std::cout << std::endl;
	std::cout << "test 3.1: "<< test_3(1, 2, 3, 4, 5) << std::endl;
	std::cout << "test 3.2: "<< test_3("test 3.1", "test 3.2", "test 3.3", "test 3.4", "test 3.5") << std::endl;
	std::cout << "test 3.3: "<< test_3("a", "b", "c", "d", "e") << std::endl;
	std::cout << "test 3.4: "<< test_3(1.11, 2.22, 3.33, 4.44, 5.55) << std::endl;
	std::cout << "Print test passed." << std::endl;
	std::cout << std::endl;
	std::cout << "Test 4." << std::endl;
	std::cout << "Includes: find()." << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.1: "<< test_4(15, 277, 223) << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.2: "<< test_4("test 4.1", "test 4.2", "test 4.3") << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.3: "<< test_4("g", "p", "r") << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.4: "<< test_4(2.34, 15.89, 13.2) << std::endl;
	std::cout << std::endl;
	return 0;
}