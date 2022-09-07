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
	data_structures::list<T> l2;
	std::cout << "First case - l > l2(l = l2):" << std::endl;
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_3);
	l2.push_back(value_4);
	l = l2;
	std::cout << std::endl;
	std::cout << "Now l2.delete_first(); 1" << std::endl;
	l2.delete_first();
	std::cout << "Now l2.delete_first(); 2" << std::endl;
	std::cout << "Print l, l2:" << std::endl;
	l.print();
	l2.print();
	//------------
	std::cout << std::endl;
	std::cout << "Second case - l < l2(l = l2):" << std::endl;
	std::cout << "111" << std::endl;
	l.delete_first();
	std::cout << "222" << std::endl;
	std::cout << l2.size() << std::endl;
	std::cout << l2.first << std::endl;
	l2.delete_first();
	std::cout << "333" << std::endl;
	l.push_back(value_1);
	std::cout << "444" << std::endl;
	l2.push_back(value_2);
	std::cout << "555" << std::endl;
	l2.push_back(value_3);
	std::cout << "666" << std::endl;
	l2.push_back(value_4);
	std::cout << "777" << std::endl;
	l = l2;
	std::cout << "Print l, l2:" << std::endl;
	l.print();
	l2.print();
	//------------
	std::cout << std::endl;
	std::cout << "Third case - l == l2:" << std::endl;
	l.delete_first();
	l.delete_first();
	l.delete_first();
	l2.delete_first();
	l2.delete_first();
	l2.delete_first();
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_3);
	l2.push_back(value_1);
	l2.push_back(value_2);
	l2.push_back(value_3);
	l = l2;
	std::cout << "Print l, l2:" << std::endl;
	l.print();
	l2.print();
	//------------
	std::cout << std::endl;
	std::cout << "Fourth case - l == l2 with different values:" << std::endl;
	l.delete_first();
	l.delete_first();
	l.delete_first();
	l2.delete_first();
	l2.delete_first();
	l2.delete_first();
	l.push_back(value_1);
	l.push_back(value_2);
	l.push_back(value_3);
	l2.push_back(value_3);
	l2.push_back(value_1);
	l2.push_back(value_2);
	l = l2;
	std::cout << "Print l, l2:" << std::endl;
	l.print();
	l2.print();
	//------------
	std::cout << std::endl;
	std::cout << "Fifth case - :" << std::endl;
	//if(l[3] != value_2){
	//	return "Failed";
	//}
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
	std::cout << "Test 4." << std::endl;
	std::cout << "Includes: find()." << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.1: "<< test_4(15, 277, 223) << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.2: "<< test_4("test 4.1", "test 4.2", "test 4.3") << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.3: "<< test_4("g", "p", "r") << std::endl;
	std::cout << std::endl;
	std::cout << "test 4.4: "<< std::endl;
	std::cout << std::endl;
	std::cout << std::endl;

	data_structures::list<int> l;
	data_structures::list<int> l2;
	std::cout << std::endl;
	std::cout << "Push back test for array \"l\" and \"l2\": " << std::endl;
	std::cout << std::endl;
	l.push_back(100);
	l.push_back(90);
	l.push_back(80);
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	l2.push_back(40);
	l2.push_back(50);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	std::cout << std::endl;
	std::cout << "operator= test for array \"l\" and \"l2\" (if l2 > l): " << std:: endl;
	std::cout << std::endl;
	l2 = l;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "1st test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "operator= test for array \"l\" and \"l2\" (if l2 < l): " << std:: endl;
	l2.clear();
	l.clear();
	l.push_back(100);
	l.push_back(90);
	l.push_back(80);
	l.push_back(70);
	l.push_back(60);
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	l2 = l;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "2nd test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "operator= test for array \"l\" and \"l2\" (if l2 == l): " << std:: endl;
	l2.clear();
	l.clear();
	l.push_back(100);
	l.push_back(90);
	l.push_back(80);
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	l2 = l;
	l2.print();
	std::cout << "3rd test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "operator= test for array \"l\" and \"l2\" case l.size & l2.size == 1: " << std:: endl;
	l.clear();
	l2.clear();
	l.push_back(100);
	l2.push_back(22);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	l2 = l;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "4th test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "operator= test for array \"l\" and \"l2\" case l2 is empty: " << std:: endl;
	l.clear();
	l2.clear();
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2(empty): " << std::endl;
	l2 = l;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "5th test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "operator= test for array \"l\" and \"l2\" case l is empty: " << std:: endl;
	l2.clear();
	l.clear();
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	std::cout << "list l(empty): ";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	l2 = l;
	l2.print();
	std::cout << "6th test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;
	l2.clear();
	l.clear();

	//exceptions tests

	try{
		std::cout << "l.print(); " << std::endl;
		l.print();
	} catch (const std::bad_alloc& e){
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	try{
		std::cout << std::endl;
		std::cout << "l2.print(); " << std::endl;
		l2.print();
	} catch (const std::bad_alloc& e){
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	l.push_back(13);
	l.push_back(20);
	l.push_back(9);
	try{
		std::cout << std::endl;
		std::cout << "find" << std::endl;
		l.find(11);
	} catch (std::invalid_argument& e){
		std::cout << "Caught expected exception: " << e.what() << std::endl;	
	}

	try{
		std::cout << std::endl;
		std::cout << "operator []" << std::endl;
		std::cout << l[5] << std::endl;
	} catch (std::out_of_range& e){
		std::cout << "Caught expected exception: " << e.what() << std::endl;	
	}

	l.clear();

	try{
		std::cout << std::endl;
		std::cout << "clear" << std::endl;
		l.clear();
	} catch (std::bad_alloc& e){
		std::cout << "Caught expected exception: " << e.what() << std::endl;
		std::cout << std::endl;	
		std::cout << std::endl;	
	}
	return 0;
}