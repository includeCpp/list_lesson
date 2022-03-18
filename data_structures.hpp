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

    int size() const;
	bool is_empty() const;
    void push_back(T _value);
    void print() const;
    Node<T>* find(T _value) const;
    void delete_first();
    void delete_last();
    void delete_concrete(T _value);
    T& operator[](const int index);
    void insert(const int num, const T& _value);
    int find_index(int num) const;
    private:
    Node<T>* first;
    /*Node<T>* last;*/
};

template <typename T>
Node<T>::Node(const T& _value, Node<T>* _next) : value(_value), next(_next) {}

template <typename T>
list<T>::list(Node<T>* _first) : first(_first) {}

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
void list<T>::push_back(T _value){             //добавляет новый элемент в конец списка
    Node<T>* new_el = new Node<T>(_value);
    if(is_empty()){
        first = new_el;         
        return;
    }
    Node<T>* p = first;
    while(nullptr != p -> next){        //while(!p)
        p = p -> next;
    }
    p -> next = new_el;               //push fu**ing back
}

template <typename T>
void list<T>::print() const {                  //выводит весь список
    Node<T>* current_el = first;            
    /*if(is_empty()){                       //здесь возможно проверка не нужна 
        return;                             //если current_el равен nullptr то цикл не будет выполняться
    }*/
    while(current_el){
        std::cout << current_el -> value << " ";
        current_el = current_el -> next;
    }
    std::cout << std::endl;
}

template <typename T>
Node<T>* list<T>::find(T _value) const {       //поиск элемента по заданному значению(возврашает первый найденный элемент)
    Node<T>* list_el = first;
    /*if(is_empty()){                       //здесь проверка тоже не нужна т.к. если list_el = nullptr то цикл не выполниться
        return list_el;
    }*/
    while(list_el && list_el -> value != _value){           //??????
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
    delete erase_el;
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
    if(is_empty()){                         //проверка списка на наличие элементов
        return;
    }
    while(first -> value == _value){        //проверка равенства значения первого элемента списка значению _value (зачем нам вытаскивать value если first и first -> value это одно и тоже)
        delete_first();
    }
    /*else if(last -> value == _value){     //проверка равенства значения последнего элемента списка значению _value
        delete_last();
        return;
    }*/
    if(!is_empty()){
        Node<T>* slow = first;                      //создаем указатель на структуру типа Node и присваиваем значение указателя first
        Node<T>* fast = slow -> next;               //создаем указатель на структуру типа Node и присваиваем значение next указателя slow
        while(fast){                                //проверка указателя fast и значения value на соответсвие значение _value                 
            if(fast -> value == _value){
                slow -> next = fast -> next;
                delete fast;
                fast = slow -> next;
            }
            else{
                slow = fast;
                fast = fast -> next; 
            /*else if(fast == _value){
                delete fast;
            }*/ 
            }                      
        }
    }
}

template <typename T>
T& list<T>::operator[](const int num){                     //требуется объяснение         добавляет оператор "[]"
    Node<T>* p = first;
    for(int i = 0; i < num && p; i++){
        p = p -> next;
    }
    T& ret_val = p -> value;
    return ret_val;
}

template <typename T>
void list<T>::insert(int num, const T& _value){            //здесь ошибка
    Node<T>* p = first;
    for(int i = 0; i < num - 1; i++){
        p = p -> next;
    }
    // p - соответствует индексу num - 1
    // p -> next - соответствует индексу num
    Node<T>* t = new Node<T>(_value, p -> next);
    // t необходимо подставить на место элемента с индексом num
    // необходимо сдвинуть хвост списка 
    p -> next = t;
    

    /*if(num > ){
        //delete num;     ??не работает
        first -> push_back(value_1);
        return;
    }
    for(int i = 0; i < num; i++){
        p = p -> next;
        if(i == num - 1){               //if(i = num - 1) :))
            Node<T>* save = p;
            p -> value = value_1;
            p -> next = save;
            delete save;                    //можно не удалять?
            return;
        }
    }*/
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

} //data_structures

#endif