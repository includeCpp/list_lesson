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
    list() : first(nullptr) /*last(nullptr)*/ {}

    int size(){
    	int list_size = 0;
    	Node<T>* p = first;
    	while(p){
    		p = p -> next;
    		list_size++;
    	}
    	return list_size;
    }

    bool is_empty(){
        return nullptr == first;
    }

    void push_back(T _value){
        Node<T>* new_el = new Node<T>(_value);
        if(is_empty()){
            first = new_el;         /*last = new_el;*/
            return;
        }
        Node<T>* p = first;
        while(nullptr != p -> next){        //while(!p)
            p = p -> next;              
        }
        p -> next = new_el;               //push fu**ing back
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
        return list_el;
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

    void delete_concrete(T _value){
        if(is_empty()){                 //проверка списка на наличие элементов
            return;
        }
        while(first -> value == _value){   //проверка равенства значения первого элемента списка значению _value (зачем нам вытаскивать value если first и first -> value это одно и тоже)
            delete_first();
        }
        /*else if(last -> value == _value){   //проверка равенства значения последнего элемента списка значению _value
            delete_last();
            return;
        }*/
        if(!is_empty()){
            Node<T>* slow = first;                      //создаем указатель на структуру типа Node и присваиваем значение указателя first
            Node<T>* fast = slow -> next;               //создаем указатель на структуру типа Node и присваиваем значение next указателя slow
            while(fast){     //проверка указателя fast и значения value на соответсвие значение _value                 
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
    private:
    Node<T>* first;
    /*Node<T>* last;*/
};




int main() {
    list<int> l;
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
return 0;
}
