#include "Frankenstein_list.h"

template <typename T>
void FList<T>::sort_after_remove(Node* node)
{
    if(node == desc_head) 
    {
        desc_head = node->lesser;
        node->lesser->greater = nullptr;
        return;
    }
    if(node == asc_head) 
    {
        asc_head = node->greater;
        node->greater->lesser = nullptr;
        return; 
    }
    
    node->greater->lesser = node->lesser;
    node->lesser->greater = node->greater;
}

template <typename T>
FList<T>::FList()
{
    size = 0;
    head = nullptr;
    tail = nullptr;
    desc_head = nullptr;
    asc_head = nullptr;
}

template<typename T>
void FList<T>::print()
{
    for(int i = 0; i < size; ++i)
    {
        std::cout << (*this)[i] << " ";
    }
}

template <typename T>
void FList<T>::push_back(T data)
{
    if(tail == nullptr) {
    tail = new Node(data);
    head = tail;
    } 
    else 
    {
        Node* tmp = tail;
        tail = new Node(data,nullptr, tail);
        tmp -> pnext = tail;
    }

    put_sorted(tail);
    ++size;
}


template <typename T>
const T& FList<T>::operator[] (T index)
{
    Node* current = head;
    while(index != 0)
    {
        --index;
        current = current -> pnext;
    }
    return current -> data;
}

template <typename T>
void FList<T>::push_front(T data)
{
    if(head == nullptr) {
    head = new Node(data);
    tail = head;    
    }
    else    
    {
        head = new Node(data, head);
    }
   
    put_sorted(head);
    ++size;
}

template <typename T>
void FList<T>::put_sorted(Node* node)
{
        if (asc_head == nullptr && desc_head == nullptr) {
            asc_head = node;
            desc_head = node;
            return;
        }

    Node* current = asc_head;
    
    while(current->data < node->data && current->greater != nullptr)
    {
        current = current->greater;    
    }
   
    if(current->data < node->data)
    {
        node->greater = current->greater;
        node->lesser = current;
        current->greater = node;
        
        if(node->greater == nullptr) desc_head = node;
    }
    
    else if(current->data >= node->data)
    {
        node->lesser = current->lesser;
        
        if(current->lesser != nullptr)
        {
            current->lesser->greater = node;
        } else
        {
            asc_head = node;
        }
            current->lesser = node;
            node->greater = current;
    }
}

template <typename T>
void FList<T>::print_in_descending_order()
{
    Node* current = desc_head;
    
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->lesser;
    }
}

template <typename T>
void FList<T>::print_in_ascending_order()
{
    Node* current = asc_head;
    int tmp_size = size;
    
    while(tmp_size--)
    {
        std::cout << current->data << " ";
        current = current->greater;
    }

}

template <typename T>
void FList<T>::pop_back()
{
    if(size == 1){delete tail;}

    else {
    Node* tmp = tail;
    tail = tail -> pprev;
    tail -> pnext = nullptr;
    sort_after_remove(tmp);
    delete tmp;
    }
--size;
}

template <typename T>
void FList<T>::pop_front()
{
    if(size == 1){delete head;}

    else {
    Node* tmp = head;
    head = head -> pnext;
    head -> pprev = nullptr;
    sort_after_remove(tmp);
    delete tmp;
    }
    
    --size;
}

template <typename T>
void FList<T>::clear()
{
    while(size){ pop_front(); } 
}

template <typename T>
void FList<T>::insert(int index, T data)
{
    if(index == 0){
        push_front(data);
    } 
    else if(index == (size - 1)) {
        push_back(data);
    }

    Node* current = head;
    while(index != 0)
    {
        --index;
        current = current -> pnext;
    }

    current -> pnext = new Node(data, current->pnext, current);
    put_sorted(current->pnext);
    ++size;
}


template <typename T>
void FList<T>::removeAt(int index)
{
    
    if(index >= size || index < 0) return;
    if(index == 0)
    {
        pop_front();
    }

    else if(index == size - 1)
    {
        pop_back();
        
    }

    else
    {
        Node* current = head;
        for(int i = 0; i < index - 1; ++i)
        {
            current = current -> pnext;
        }
        Node* deleted_element = current -> pnext;
        current -> pnext = current -> pnext -> pnext;
        current -> pnext -> pprev = current;

        sort_after_remove(deleted_element);
        delete deleted_element;
        --size;
    }

}
