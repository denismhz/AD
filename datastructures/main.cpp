#include "singlyLinkedList.h"
#include "doublyLinkedList.h"
#include "../sort/include/person.h"
#include <iostream>

/*
 * gcc -Iincludepath
 */

int main(void){
    /*LinkedList<int>* list = new LinkedList<int>();

    list->addNodeAtIndex(3, 0);
    list->addNodeAtIndex(2, 0);
    list->addNodeAtIndex(1, 0);
    list->addNodeAtIndex(3, 3);
    list->addNodeAtIndex(4, 3);
    std::cout << "Data at index 3:" <<list->getDataAtIndex(3) << "\n";
    list->printList();
    list->removeNodeAtIndex(0);
    list->removeNodeAtIndex(1);
    list->removeNodeAtIndex(list->getLength()-1);
    std::cout << "Num items:" << list->getLength() << "\n";
    list->printList();

    std::cout << "\n";
    LinkedList<Person*>* personList = new LinkedList<Person*>;
    for(int i = 0; i < 10; i++){
        personList->addNodeAtIndex(new Person(createFirstName(), 
                    createLastName(),randAge()), i);
    }
    personList->printList();
    for(int i = 0; i < 10; i++){
        (personList->getDataAtIndex(i))->toString();
    }
    for(int i = 0; i < 10; i+=2){
        personList->removeNodeAtIndex(i);
    }
    std::cout << "\n";
    for(int i = 0; i < personList->getLength(); i++){
        (personList->getDataAtIndex(i))->toString();
    }
    */
    DoublyLinkedList<int>* list = new DoublyLinkedList<int>();
    std::cout << list->isEmpty() << endl;
    list->addNodeAtIndex(2, 0);
    list->addNodeAtIndex(3, 1);
    list->addNodeAtIndex(4, 2);
    list->addNodeAtIndex(5, 1);
    list->addNodeAtIndex(6, 2);
    list->addNodeAtIndex(8, 5);
    list->addNodeAtIndex(9, 0);
    list->printList();
    std::cout << endl;
    for(int i = 0; i < list->getLength(); i++)
        std::cout << list->getDataAtIndex(i);
    std::cout << endl;
    list->removeNodeAtIndex(0);
    list->removeNodeAtIndex(0);
    list->removeNodeAtIndex(3);
    list->printList();
    for(int i = 0; i < list->getLength(); i++){
        list->removeNodeAtIndex(i);
    }
    free(list);

    DoublyLinkedList<int> list2;
    list2.addNodeAtIndex(3,0);
    list2.addNodeAtIndex(5,0);
    list2.printList();
    
}
