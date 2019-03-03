#include "../include/sort.h"
#include "../include/person.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>

void sortByLastName();
void sortByAge();
void testIfSorted();
void prarr(int *arr, int , int e);
Person** createRandPersons(int num);

template<typename T>
int ageCompare(T a, T b);

int main(){
    srand(time(NULL));
    std::cout << "----Sorting by last Name:\n";
    sortByLastName();
    std::cout << "----Sorting by Age:\n";
    sortByAge();
    /*int a[10] = {0};
    std::string ss[5] = 
        {"bcdef", "dbaqc", "abcde", "omadd", "bbbbb"};
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }
    //prarr(a, 0, 9);
    printf("\n");
    for(int i = 0; i < 5; i++){
        std::cout << ss[i] << ", ";
    }
    printf("\n");
    s->radixSort(persons, ss, 26, 5, 5);
    for(int i = 0; i < 5; i++){
        std::cout << ss[i] << ", ";
    }
    //prarr(a, 0,9);
    //printf("\n");
    //printf("%d\n", test(a, 10));*/
    return 0;
}

template<typename T>
int ageCompare(T a, T b){
  if(a->getAge() > b->getAge()) return 1;
  if(b->getAge() > a->getAge()) return -1;
  return 0;
}

void sortByLastName(){
    Person** persons = createRandPersons(10);
    //Create array of lastnames
    std::string arr[10];
    for(int i = 0; i < 10; i++){
        arr[i] = persons[i]->getLastName();
        //print before sorting
        persons[i]->toString();
    }
    std::cout << "\n";
    Sort<Person*>* s = new Sort<Person*>();

    //sort by lastname
    s->radixSort(persons, arr, 26, 10);

    //print after sorting
    for(int i = 0; i < 10; i++){
        persons[i]->toString();
    }
    std::cout << "\n";
}

void sortByAge(){
    Person** persons = createRandPersons(11);
    
    //print before sorting
    for(int i = 0; i < 10; i++){
        persons[i]->toString();
    }
    std::cout << "\n";

    //function pointer to int ageCompare()
    int (*fct)(Person*, Person*) = ageCompare;
    Sort<Person*>* s = new Sort<Person*>(fct);
    s->quickSort(persons, 0, 9);

    //print after sorting
    for(int i = 0; i < 10; i++){
        persons[i]->toString();
    }
    std::cout << "\n";
}

int testIfSorted(int* p, int l){
    for(int i = 0; i < l; i++){
        if(p[i] > p[i+1] && i+1 < l) return -1;
    }
    return 1;
}

void prarr(int *arr, int s, int e){
  for(int i = s; i <= e; ++i)
    printf("%d%s", arr[i], i == e ? "\n" : ", ");
}

Person** createRandPersons(int num){
    //Create array of random persons
    Person** persons = (Person**) malloc(num*sizeof(Person*));
    for(int i = 0; i < num; i++){
        persons[i] = new Person(createFirstName(), createLastName(), randAge());
    }
    return persons;
}
