#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
    public:
        Person(string, string, int);
        int getAge();
        string getName();
        string getLastName();
        string getFirstName();
        void toString();
    private:
        int age;
        string firstName;
        string lastName;
};

int randAge();
string createLastName();
string createFirstName();
Person** createRandPersons(int num);

Person::Person(string firstName, string lastName, int age){
    this->firstName = firstName;
    this->lastName = lastName;
    this->age = age;
}

int Person::getAge(){
    return age;
}

string Person::getName(){
    return firstName + " " + lastName;
}

string Person::getFirstName(){
    return firstName;
}

string Person::getLastName(){
    return lastName;
}

Person** createRandPersons(int num){
    //Create array of random persons
    Person** persons = (Person**) malloc(num*sizeof(Person*));
    for(int i = 0; i < num; i++){
        persons[i] = new Person(createFirstName(), createLastName(), randAge());    
    }
    return persons;
}

void Person::toString(){
    cout << this->firstName << ", " << this->lastName << "\n";
}

int randAge(){
    return rand() % 90;
}

string createFirstName(){
    string name;
    ifstream names;
    names.open("/home/denis/repos/AD/sort/names/first-names.txt");
    int i = rand() % 4945;
    if(names.is_open()){
        while(!names.eof() && i >= 0){
                names >> name;
                i--;
        }
    }
    return name;
}

string createLastName(){
    string name;
    ifstream names;
    names.open("/home/denis/repos/AD/sort/names/names.txt");
    int i = rand() % 21895;
    if(names.is_open()){
        while(!names.eof() && i >= 0){
                names >> name;
                i--;
        }
    }
    return name;
}

#endif
