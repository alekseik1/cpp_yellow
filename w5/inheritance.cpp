//
// Created by Aleksei Kozharin on 23.11.2020.
//

#include <iostream>

using namespace std;

class Animal {
public:
    Animal(const string& s): Name(s) {}
    const string Name;
};


class Dog: public Animal {
public:
    Dog(const string& s): Animal(s) {}
    void Bark() {
        cout << Name << " barks: woof!" << endl;
    }
};

