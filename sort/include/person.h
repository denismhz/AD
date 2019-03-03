#ifndef _PERSON_H_
#define _PERSON_H_
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int randAge();
string createLastName();
string createFirstName();

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

void Person::toString(){
    cout << getName() << ", " << getAge() << "\n";
}

int randAge(){
    return rand() % 90;
}

string createFirstName(){
    string name;
    ifstream names;
    names.open("../names/first-names.txt");
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
    names.open("../names/names.txt");
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
