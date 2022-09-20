#ifndef __STACK_H__
#define __STACK_H__
//using singly linked list
#include "singlyLinkedList.h"

template<class T>
class Stack{
    public:
        Stack();
        void push(T);
        T pop();
        T peek();
    private:
        LinkedList<T> stack;
        int length;
};

template<typename T>
Stack<T>::Stack(){
    this->length = 0;
}

template<typename T>
void Stack<T>::push(T elem){
    stack.addNodeAtIndex(elem, 0);
    this->length++;
}

template<typename T>
T Stack<T>::pop(){
    if(length == 0){
        return -1;
    }
    T data = stack.getDataAtIndex(0);
    stack.removeNodeAtIndex(0);
    this->length--;
    return data;
}

template<typename T>
T Stack<T>::peek(){
    return stack.getDataAtIndex(0);
}

#endif
