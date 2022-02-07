#include <iostream>
  
template <typename T>
class FList
{
public:
    FList();
    ~FList(){clear();}
    int get_size() const{return this -> size;}
    void push_back(T);
    void push_front(T);
    void pop_back();
    void pop_front();
    void insert(int, T);
    void removeAt(int);
    const T& operator[] (T);
    bool check_input(T) const;
    void clear();
    void print_in_descending_order();
    void print_in_ascending_order();
    void print();

private:
    class Node
{
public:
    Node* pnext;
    Node* pprev;
    Node* greater;
    Node* lesser;
    T data;

Node(T data = T(), Node* pnext = nullptr, Node* pprev = nullptr,Node* greater = nullptr, Node* lesser = nullptr)
{
    this -> data = data;
    this -> pnext = pnext;
    this -> pprev = pprev;
}

};

private:    
    void put_sorted(Node*);
    void sort_after_remove(Node*);
    int size;
    Node* head;
    Node* tail;
    Node* asc_head;
    Node* desc_head;
};
