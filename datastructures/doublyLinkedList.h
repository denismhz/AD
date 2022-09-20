#ifndef __DOUBLY_LINKED_LIST_H__
#define __DOUBLY_LINKED_LIST_H__
#include <iostream>

template<class T>
class DoublyLinkedList{
    typedef struct _node{
        T data;
        struct _node* nextNode;
        struct _node* prevNode;
    } node;
    public: 
        DoublyLinkedList();
        int getLength();
        void addNodeAtIndex(T, int);
        void removeNodeAtIndex(int);
        T getDataAtIndex(int);
        bool isEmpty();
        void printList();
    private:
        node* list;
        int length;

};

template<typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
    this->length = 0;
    this->list = NULL;
}

template<typename T>
int DoublyLinkedList<T>::getLength(){
    return this->length;
}

template<typename T>
void DoublyLinkedList<T>::addNodeAtIndex(T data, int index){
    node* newNode = new node;
    newNode->data = data;
    if(index > length){
        std::cout << "Index out of range\n";
        return;
    }
    if(index == 0){
        node* tmp = this->list;
        if(tmp) tmp->prevNode = newNode;
        this->list = newNode;
        newNode->prevNode = NULL;
        newNode->nextNode = tmp;
        ++length;
        return;
    }
    node* prev = list;
    while(index > 1 && index <= length){
        prev = prev->nextNode;
        index--;
    }
    node* tmp = prev->nextNode;
    if(tmp) tmp->prevNode = newNode;
    prev->nextNode = newNode;
    newNode->nextNode = tmp;
    newNode->prevNode = prev;
    ++length;
}

template<typename T>
void DoublyLinkedList<T>::removeNodeAtIndex(int index){
    node* prev = this->list;
    node* tmp = NULL;
    if(index >= length){
        std::cerr << "Index out of bounds\n";
        return;
    }
    if(index == 0){
        this->list = this->list->nextNode;
        this->list->prevNode = NULL;
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
    if(tmp) tmp->nextNode->prevNode = prev;
    --length;
}

template<typename T>
T DoublyLinkedList<T>::getDataAtIndex(int index){
    node* tmp = this->list;
    while(index-- > 0)
        tmp = tmp->nextNode;
    return tmp->data;
}

template<typename T>
bool DoublyLinkedList<T>::isEmpty(){
    return !this->list;
}

template<typename T>
void DoublyLinkedList<T>::printList(){
    auto *list = this->list;
    while(list->nextNode){
        std::cout << list->data << "->";
        list = list->nextNode;
    }
    std::cout << list-> data << "->NULL\n";
    while(list){
        std::cout << list->data << "->";
        list = list->prevNode;
    }
    std::cout << "NULL\n" << this->length <<"\n";
}

#endif
