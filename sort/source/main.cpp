#include "../include/sort.h"
#include "../include/person.h"
#include <stdlib.h>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>

void sortByLastName();
void sortByAge();
void prarr(int *, int , int );

int ageCompare(Person* a, Person* b);

int compare(int a, int b){
    return a>b?1:(a==b?0:-1);
}

int main(){
    srand(time(NULL));
    std::cout << "----Sorting by last Name:\n";
    sortByLastName();
    std::cout << "----Sorting by Age:\n";
    sortByAge();

    //Sort int array
    int (*fct)(int a, int b) = compare;
    Sort<int>* s = new Sort<int>(fct);
    int a[10] = {0};
    for(int i = 0; i < 10; i++){
        a[i] = rand() % 100;
    }
    prarr(a, 0, 9);
    s->quickSort(a, 0, 9);
    prarr(a, 0,9);
    return 0;
}

int ageCompare(Person* a, Person* b){
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
    s->bubbleSort(persons, 10);

    //print after sorting
    for(int i = 0; i < 10; i++){
        persons[i]->toString();
    }
    std::cout << "\n";
}

void prarr(int *arr, int s, int e){
  for(int i = s; i <= e; ++i)
    printf("%d%s", arr[i], i == e ? "\n" : ", ");
}

