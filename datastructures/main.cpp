#include "singlyLinkedList.h"
#include "doublyLinkedList.h"
#include "stack.h"
#include "../sort/include/person.h"
#include <iostream>
#include <string>
#include <algorithm>

/*
 * gcc -Iincludepath
 */

int isPalyndrome(string);

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

    Stack<int> stack;
    stack.push(1);
    stack.push(8);
    stack.push(2);
    std::cout << stack.peek();
    stack.pop();
    std::cout << stack.peek();
    
    
    LinkedList<int> list3;
    list3.insertSorted(1);
    list3.insertSorted(1);
    list3.insertSorted(1);

    list3.insertSorted(6);
    list3.insertSorted(4);
    list3.insertSorted(3);
    list3.insertSorted(5);
    list3.printList();
    */
    std::cout << isPalyndrome("helo");
    std::cout << isPalyndrome("racecar");
    std::cout << isPalyndrome("I did, did I?");
    std::cout << isPalyndrome("Don't nod");
    std::cout << isPalyndrome("Was it a car or a cat I saw?");

    return 0;
}

int isPalyndrome(string s){
    Stack<char> stack;
    std::transform(s.begin(), s.end(), s.begin(), ::tolower);
    int i = 0;
    int l = 0;
    for(i = 0; s[i] != '\0'; i++){
        l++;
        if(s[i] >= 'a' && s[i] <= 'z')
            stack.push(s[i]);
    }
    for(int j = 0; j < l; j++){
        if(s[j] >= 'a' && s[j] <= 'z')
            if(stack.pop() != s[j]) return 0;
    }
    return 1;
}
