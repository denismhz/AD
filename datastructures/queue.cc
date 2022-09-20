#include "singlyLinkedList.h"

template<class T>
class Queue{
    public:
        Queue();
        void enqueue(T);
        T dequeue();
        T peek();
    private:
        int length;
        LinkedList<T> queue;

};
