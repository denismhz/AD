#ifndef _H_singlyLinkedList_
#define _H_singlyLinkedList_
#include <iostream>

/*
 * getIndexOfElement(T, (func*)(T,T))
 * func* determines when two objects are the same
 * return index of object if in list
 * retrun -1 if not in list
 */

template<class T>
class LinkedList
{
    typedef struct _node{
        T data;
        struct _node* nextNode;
    } node;
    public:
        LinkedList();
        int getLength();
        void addNodeAtIndex(T, int);
        void removeNodeAtIndex(int);
        T getDataAtIndex(int);
        bool isEmpty();
        void insertSorted(int);
        void printList();
        node* list;
    private:
        int length;
};

template<typename T>
LinkedList<T>::LinkedList(){
    this->length = 0;
    this->list = NULL;
}

template<typename T>
int LinkedList<T>::getLength(){
    return length;
}

template<typename T>
void LinkedList<T>::addNodeAtIndex(T newData, int index){
    node* newNode = new node;
    newNode->data = newData;
    if(index > length){
        std::cout << "Index out of range\n";
        return;
    }
    if(index == 0){
        node* tmp = this->list;
        this->list = newNode;
        this->list->nextNode = tmp;
        ++length;
        return;
    }
    node* prev = list;
    while(index > 1 && index <= length) {
        prev = prev->nextNode;
        --index;
    }
    node* tmp = prev->nextNode;
    prev->nextNode = newNode;
    newNode->nextNode = tmp;
    ++length;
}

template<typename T>
void LinkedList<T>::removeNodeAtIndex(int index){
    node* prev = this->list;
    node* tmp = NULL;
    if(index >= length){
        std::cerr << "Index out of bounds\n";
        return;
    }
    if(index == 0){
        this->list = this->list->nextNode;
        free(prev);
        --length;
        return;
    }
    while(index > 1){
        prev = prev->nextNode;
        index--;
    }
    tmp = prev->nextNode;
    free(prev->nextNode);
    prev->nextNode = tmp->nextNode;
    --length;
}

template<typename T>
T LinkedList<T>::getDataAtIndex(int index){
    node* tmp = this->list;
    while(index-- > 0)
        tmp = tmp->nextNode;
    return tmp->data;
}

template<typename T>
bool LinkedList<T>::isEmpty(){
    return !this->list;
}

template<typename T>
void LinkedList<T>::insertSorted(int elem){
    node* newNode = new node;
    newNode->data = elem;
    node* tmp = this->list;
    if(!tmp || tmp->data >= elem){
        this->list = newNode;
        newNode->nextNode = tmp;
        ++length;
        return;
    }
    node* current = this->list->nextNode;
    node* prev = this->list;
    while(current && current->data < elem){
        prev = current;
        current = current->nextNode;
    }
    newNode->nextNode = current;
    prev->nextNode = newNode;
    ++length;
}

template<typename T>
void LinkedList<T>::printList(){
    auto *list = this->list;
    while(list){
        std::cout << list->data << "->";
        list = list->nextNode;
    }
    std::cout << "NULL\n";
}

#endif
