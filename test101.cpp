#include <iostream>
#include <string>

#include "data_structures.hpp"

int main(){
	data_structures::list<int> l;
	data_structures::list<int> l2;
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
	l2 = l;
	std::cout << "l2 print(l2 > l):" << std::endl;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "1st test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

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
	std::cout << "l2 print(l2 < l):" << std::endl;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "2nd test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

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
	std::cout << "l2 print(l2 == l):" << std::endl;
	l2.print();
	std::cout << "3rd test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	l.clear();
	l2.clear();
	l.push_back(100);
	l2.push_back(22);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	std::cout << "l && l2 == 1(size)" << std::endl;
	l2 = l;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "4th test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	l.clear();
	l2.clear();
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);
	std::cout << "list l: ";
	l.print();
	std::cout << "list l2 is empty." << std::endl;
	l2 = l;
	std::cout << l2.size() << std::endl;
	l2.print();
	std::cout << "5th test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;

	l2.clear();
	l.clear();
	l2.push_back(10);
	l2.push_back(20);
	l2.push_back(30);
	std::cout << "list l is empty.";
	l.print();
	std::cout << "list l2: ";
	l2.print();
	l2 = l;
	l2.print();
	std::cout << "6th test is finished.";
	std::cout << std::endl;
	std::cout << std::endl;


	l.clear();
	l2.clear();
	
	for(int i = 0; i < 2; i++){
		int value;
		std::cin >> value;
		try{
			if(value == 0){
				std::string str = "Exception caught.";
				throw str;
			}
		} catch(std::string x){
			std::cout << x << std::endl;
		}
		l.push_back(value);
	}










	return 0;
}