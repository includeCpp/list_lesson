#ifndef __Data_Structures_hpp__                                         
#define __Data_Structures_hpp__

#include <exception>

namespace data_structures {

template <typename T>
struct Node{
public:
    Node(const T& _value, Node<T>* _next = nullptr);
    T value;
    Node<T>* next;
};

template <typename T>                                                   
struct list{
    public:
    list(Node<T>* _first = nullptr);
    list(const list<T>& copy);
    list(list<T>&& _value);
    int size() const;                               
	bool is_empty() const;                          
    void push_back(const T& _value);                
    void print() const;                             
    Node<T>* find(const T& _value) const;                  
    void delete_first();                            
    void delete_last();                             
    void delete_value(const T& _value);                 
    T& operator[](const int index);
    const T& operator[](const int index)const;                 
    list<T>& operator=(const list<T>& copy);
    list<T>& operator=(list<T>&& move);      
    void insert(const int num, const T& _value); 
    void clear();                
    ~list();
    private:
    Node<T>* first;
};                                                                      

template <typename T>
Node<T>::Node(const T& _value, Node<T>* _next) : value(_value), next(_next) {}

template <typename T>
list<T>::list(Node<T>* _first) : first(_first) {}

template<typename T>
list<T>::list(const list<T>& copy){
    Node<T>* p = copy.first;
    try{
        while(p){
            push_back(p -> value);
            p = p -> next;
        }
    } catch(...){
        clear();
        throw;
    }                                                                   
}

template<typename T>
list<T>::list(list<T>&& _value) : first(_value.first){
	_value.first = nullptr;
}

template <typename T>
int list<T>::size() const{
    int list_size = 0;
    Node<T>* p = first;
    while(p){
        p = p -> next;
        list_size++;
    }
    return list_size;
}
                                                                        
template <typename T>
bool list<T>::is_empty() const{
    return nullptr == first;
}

template <typename T>
void list<T>::push_back(const T& _value){
    Node<T>* new_el = new Node<T>(_value);
    if(is_empty()){
        first = new_el;         
        return;
    }
    Node<T>* p = first;
    while(nullptr != p -> next){                                       
        p = p -> next;
    }
    p -> next = new_el;
}

template <typename T>
void list<T>::print() const {
    Node<T>* current_el = first;
    while(current_el){
        std::cout << current_el -> value << " ";
        current_el = current_el -> next;
    }                                                                  
    std::cout << std::endl;
}

template <typename T>
Node<T>* list<T>::find(const T& _value) const{
    Node<T>* list_el = first;
    while(list_el && list_el -> value != _value){
        list_el = list_el -> next;
    }
    return list_el;
}

template <typename T>
void list<T>::delete_first(){
    if(is_empty()){
        return;
    }
    Node<T>* erase_el = first;
    first = erase_el -> next;
    delete erase_el;
}

template <typename T>
void list<T>::delete_last(){
    if(is_empty()){
        return;
    }
    Node<T>* p = first;
    Node<T>* new_last_element;
    while(nullptr != p -> next){
        new_last_element = p;
        p = p -> next;
    }
    delete p;
    new_last_element -> next = nullptr;
}

template <typename T>
void list<T>::delete_value(const T& _value){
    if(is_empty()){
        return;
    }
    while(first -> value == _value){
        delete_first();
    }
    if(!is_empty()){
        Node<T>* slow = first;
        Node<T>* fast = slow -> next;
        while(fast){       
            if(fast -> value == _value){
                slow -> next = fast -> next;
                delete fast;
                fast = slow -> next;
            }
            else{
                slow = fast;
                fast = fast -> next;
            }                   
        }
    }
}

template <typename T>
T& list<T>::operator[](const int num){
    Node<T>* p = first;
    for(int i = 0; i < num && p; i++){
        p = p -> next;
    }
    T& rval = p -> value;
    return rval;
}

template <typename T>
const T& list<T>::operator[](const int num) const{
    return const_cast<const T&>((*this)[num]);
}


template<typename T>
void list<T>::clear(){
    Node<T>* p = first;
    while(p){
        p = p -> next;
        delete first;
        first = p;
    }
}

template<typename T>
list<T>& list<T>::operator=(const list<T>& copy){
    if(this == &copy){
        return *this;
    }
    if(!first || !copy.first){
        if(!first){
            Node<T>* m = copy.first;
            while(m){
                push_back(m -> value);
                m = m -> next;
            }
            return *this;
        }
        clear();
        std::cout << "The argument was empty.";
        return *this;
    }
    Node<T>* p = first;
    Node<T>* m = copy.first;
    Node<T>* last = p;
    while(m && p){
        p -> value = m -> value;
        last = p;
        p = p -> next;
        m = m -> next;
    }
    while(p){
        Node<T>* j = p;
        p = p -> next;
        delete j;
    }
    if(last){
        last -> next = nullptr;
    }
    while(m){
        last -> next = new Node<T>(m -> value);
        last = last -> next;
        m = m -> next;
    }
    return *this;
}

template<typename T>
list<T>& list<T>::operator=(list<T>&& move){
	clear();
	first = move.first;
	move.first = nullptr;
	return *this;
}

template <typename T>
void list<T>::insert(int num, const T& _value){
    Node<T>* p = first;
    for(int i = 0; i < num - 1; i++){
        p = p -> next;
    }
    Node<T>* t = new Node<T>(_value, p -> next);
    p -> next = t;
    return;
}

template<typename T>
list<T>::~list(){
	std::cout << "Destructor" << std:: endl;
    clear();
}

} //data_structures

#endif


