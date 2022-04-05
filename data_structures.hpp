#ifndef __Data_Structures_hpp__
#define __Data_Structures_hpp__

#define USE_ADVANCED_SETTERS

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

    int size() const;                               //++
	bool is_empty() const;                          //++
    void push_back(const T& _value);                //++
    void print() const;                             //++
    Node<T>* find(T _value) const;                  //++
    void delete_first();                            //++
    void delete_last();                             //++
    void delete_concrete(T _value);                 //++
    T& operator[](const int index);                 //++
    list<T>& operator=(const list<T>& copy);        //++
    void insert(const int num, const T& _value);    //++
    int find_index(int num) const;                  //++
    void clear();
    ~list();
    //private:
    Node<T>* first;
    /*Node<T>* last;*/
};

template <typename T>
Node<T>::Node(const T& _value, Node<T>* _next) : value(_value), next(_next) {}

template <typename T>
list<T>::list(Node<T>* _first) : first(_first) {}

template<typename T>
list<T>::list(const list<T>& copy){
    Node<T>* p = copy.first;
    while(p){
        this -> push_back(p -> value);
        p = p -> next;
    }
}

template <typename T>
int list<T>::size() const {                    //возвращает размер списка
    int list_size = 0;
    Node<T>* p = first;
    while(p){
        p = p -> next;
        list_size++;
    }
    return list_size;
}

template <typename T>
bool list<T>::is_empty() const {               //проверяет не является ли список пустым  
    return nullptr == first;
}

template <typename T>
void list<T>::push_back(const T& _value){             //добавляет новый элемент в конец списка
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
void list<T>::print() const {                  //выводит весь список
    Node<T>* current_el = first;
    while(current_el){
        std::cout << current_el -> value << " ";
        current_el = current_el -> next;
    }
    std::cout << std::endl;
}

template <typename T>
Node<T>* list<T>::find(T _value) const {       //поиск элемента по заданному значению(возврашает первый найденный элемент)
    Node<T>* list_el = first;
    while(list_el && list_el -> value != _value){
        list_el = list_el -> next;
    }
    return list_el;
}

template <typename T>
void list<T>::delete_first(){                  //удаляет первый элемент списка
    if(is_empty()){
        return;
    }
    Node<T>* erase_el = first;
    first = erase_el -> next;
    std::cout << "delete_first func 1" << std::endl;
    delete erase_el;
    std::cout << "delete_first func 2" << std::endl;
}

template <typename T>
void list<T>::delete_last(){                   //удаляет последний элемент списка
    if(is_empty()){
        return;
    }
    Node<T>* p = first;
    Node<T>* new_last_element;
    while(nullptr != p -> next){
        new_last_element = p;
        p = p -> next;
    }
    //p -> next = nullptr;
    delete p;
    new_last_element -> next = nullptr;
    //last = p;

}

template <typename T>
void list<T>::delete_concrete(T _value){       //удаляет все элементы с заданным значением
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
T& list<T>::operator[](const int num){                     //добавляет оператор "[]"
    Node<T>* p = first;
    for(int i = 0; i < num && p; i++){
        p = p -> next;
    }
    T& rval = p -> value;
    return rval;
}
/*
template<typename T>
list<T>& list<T>::operator=(const list<T>& copy){
    if(this == &copy){
        return *this;
    }
    Node<T>* p = first;
    while(p){
        p = p -> next;
        delete first;
        first = p;
    }
    p = copy.first;
    while(p){
        this -> push_back(p -> value);
        p = p -> next;
    }
    return *this;
}*/

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
        std::cout << "Argument was empty.";
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

template <typename T>
int list<T>::find_index(int num) const {               //поиск элемента по заданному индексу
    if(is_empty()){
        return 0;
    }
    Node<T>* p = first;
    Node<T>* g;
    for(int i = 0; i < num || i < size(); i++){
        g = p;
        p = p -> next;
        if(i == num - 1){
            std::cout << i << std::endl;
            int rval = g -> value;
            return rval;
        }
    }
    return 0;
}

template<typename T>
list<T>::~list(){
    clear();
}

} //data_structures

#endif
