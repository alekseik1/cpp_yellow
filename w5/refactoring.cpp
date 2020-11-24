#include <iostream>
#include <utility>
#include <vector>

using namespace std;

class Person {
public:
    const string name;
    const string type;

    explicit Person(string name, string type): name(std::move(name)), type(std::move(type)) {};

    virtual void Walk(const string& destination) const {
        cout << type << ": " << name << " walks to: " << destination << endl;
    }
};

class Student: public Person {
public:
    Student(string name, string favouriteSong)
      : Person(std::move(name), "Student"), FavouriteSong(std::move(favouriteSong)) {}
    void Learn() {
        cout << "Student: " << name << " learns" << endl;
    }

    void Walk(const string& destination) const override {
        Person::Walk(destination);
        cout << "Student: " << name << " sings a song: " << FavouriteSong << endl;
    }

    void SingSong() {
        cout << "Student: " << name << " sings a song: " << FavouriteSong << endl;
    }

    string FavouriteSong;
};


class Teacher: public Person {
public:
    Teacher(string name, string subject): Person(std::move(name), "Teacher"), subject(std::move(subject)) {}

    void Teach() {
        cout << "Teacher: " << name << " teaches: " << subject << endl;
    }
    string subject;
};


class Policeman: public Person {
public:
    explicit Policeman(string name): Person(std::move(name), "Policeman") {}
    void Check(const Person& p) {
        cout << "Policeman: " << name << " checks " << p.type << ". " << p.type <<"'s name is: " << p.name << endl;
    }
};


void VisitPlaces(const Person& t, const vector<string>& places) {
    for (const auto& p : places) t.Walk(p);
}

int main() {
    Teacher t("Jim", "Math");
    Student s("Ann", "We will rock you");
    Policeman p("Bob");

    VisitPlaces(t, {"Moscow", "London"});
    p.Check(s);
    VisitPlaces(s, {"Moscow", "London"});
    return 0;
}
