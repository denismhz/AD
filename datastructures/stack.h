#ifndef __STACK_H__
#define __STACK_H__
//using singly linked list
#include "singlyLinkedList.h"

template<class T>
class Stack{
    public:
        void push(T);
        int pop();
        T peek();
    private:
        LinkedList<T> stack;
        int length;
};

template<typename T>
void Stack<T>::push(T elem){
    stack.addNodeAtIndex(elem, 0);
}

template<typename T>
int Stack<T>::pop(){
    if(!stack){
        return -1;
    }
    stack.removeNodeAtIndex(0);
    return 0;
}

template<typename T>
T Stack<T>::peek(){
    return stack.getDataAtIndex(0);
}

#endif
