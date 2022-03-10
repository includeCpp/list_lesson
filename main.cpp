#include <iostream>
#include <string>

template <typename T>
struct Node{
    Node(const T& _value, Node<T>* _next = nullptr) : value(_value), next(_next) {}
    T value;
    Node<T>* next;
};

template <typename T>
struct list{
    public:
    list() : first(nullptr), /*last(nullptr)*/ {}

    bool is_empty(){
        return nullptr == first;
    }

    void push_back(T _value){
        Node<T>* new_el = new Node<T>(_value);
        if(is_empty()){
            first = new_el;         
            first -> next = new_el;          /*last = new_el;*/
            return;
        }
        Node<T>* p = first;
        while(nullptr != p){        //while(!p)
            p = p -> next;              
        }
        p = new_el;                 //push fu**ing back
    }

    void print(){
        Node<T>* current_el = first;
        if(is_empty()){
            return;
        }
        while(current_el){
            std::cout << current_el -> value << " ";
            current_el = current_el -> next;
        }
        std::cout << std::endl;
    }

    Node<T>* find(T _value){
        Node<T>* list_el = first;
        if(is_empty()){
            return list_el;
        }
        while(list_el && list_el -> value != _value){           //??????
            list_el = list_el -> next;
        }
        return(list_el && list_el -> value == _value) ? list_el : nullptr;
    }

    void delete_first(){
        if(is_empty()){
            return;
        }
        Node<T>* erase_el = first;
        first = erase_el -> next;
        delete erase_el;
    }

    void delete_last(){
        if(is_empty()){
            return;
        }
        Node<T>* p = first;  
        while(nullptr != p -> next){
            p = p -> next;
        }
        //p -> next = nullptr;
        delete p;
        //last = p;
    }

    void delete_concrete(T _value){
        if(is_empty()){                 //проверка списка на наличие элементов
            return;
        }
        if(first -> value == _value){   //проверка равенства значения первого элемента списка значению _value (зачем нам вытаскивать value если first и first -> value это одно и тоже)
            delete_first();
            return;
        }
        /*else if(last -> value == _value){   //проверка равенства значения последнего элемента списка значению _value
            delete_last();
            return;
        }*/
        else{
            Node<T>* slow = first;                      //создаем указатель на структуру типа Node и присваиваем значение указателя first
            Node<T>* fast = slow -> next;               //создаем указатель на структуру типа Node и присваиваем значение next указателя slow
            while(fast && fast -> value != _value){     //проверка указателя fast и значения value на соответсвие значение _value
                slow = fast;                            
                fast = fast -> next;                    
                if(fast == nullptr){                    //if(!fast) <--- как понимать эту запись?
                    delete fast;                        //по сути fast здесь можно не удалять
                    std::cout << "There is no value " << _value << " in the list." << std::endl;
                    return;
                }
                /*else if(fast == _value){
                    delete fast;
                }*/
                slow -> next = fast -> next;
                delete fast;                            //и здесь fast можно не удалять
            }
        }
    }
    private:
    Node<T>* first;
    /*Node<T>* last;*/
};




int main() {
    list<int> l;
    std::cout << l.is_empty() << std::endl;
    l.push_back(3);
    l.push_back(111);
    l.push_back(23);
    l.push_back(324);
    std::cout << l.is_empty() << std::endl;
    l.print();
    std::cout << l.find(23) << std::endl; //выводит адрес, а не должен
    l.delete_first();
    l.print();
    l.delete_concrete(111);
    l.print();
    l.delete_concrete(111);
    l.print();
return 0;
}
