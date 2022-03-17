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
    list(Node<T>* first = nullptr);

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

} //data_structures

#endif