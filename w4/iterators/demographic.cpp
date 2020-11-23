//
// Created by Aleksei Kozharin on 18.11.2020.
//
#include <vector>
#include <iostream>
#include <algorithm>

/**
enum class Gender {
    FEMALE,
    MALE
};

struct Person {
    int age;
    Gender gender;
    bool is_employed;
};

template <typename InputIt>
int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
    if (range_begin == range_end) {
        return 0;
    }
    std::vector<typename InputIt::value_type> range_copy(range_begin, range_end);
    auto middle = begin(range_copy) + range_copy.size() / 2;
    nth_element(
            begin(range_copy), middle, end(range_copy),
            [](const Person& lhs, const Person& rhs) {
                return lhs.age < rhs.age;
            }
    );
    return middle->age;
}
 */

void PrintStats(std::vector<Person> persons) {
    std::cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << std::endl;

    std::vector<Person> females;
    std::copy_if(persons.begin(), persons.end(), std::back_inserter(females),
                 [](const Person& p) {return p.gender == Gender::FEMALE;});
    std::cout << "Median age for females = " << ComputeMedianAge(females.begin(), females.end()) << std::endl;

    std::vector<Person> males;
    std::copy_if(persons.begin(), persons.end(), std::back_inserter(males),
                 [](const Person& p) {return p.gender == Gender::MALE;});
    std::cout << "Median age for males = " << ComputeMedianAge(males.begin(), males.end()) << std::endl;

    std::vector<Person> employed_females;
    std::copy_if(females.begin(), females.end(), std::back_inserter(employed_females),
                 [](const Person& p) {return p.is_employed;});
    std::cout << "Median age for employed females = " <<
    ComputeMedianAge(employed_females.begin(), employed_females.end()) << std::endl;

    std::vector<Person> unemployed_females;
    std::copy_if(females.begin(), females.end(), std::back_inserter(unemployed_females),
                 [](const Person& p) {return !p.is_employed;});
    std::cout << "Median age for unemployed females = " <<
              ComputeMedianAge(unemployed_females.begin(), unemployed_females.end()) << std::endl;

    std::vector<Person> employed_males;
    std::copy_if(males.begin(), males.end(), std::back_inserter(employed_males),
                 [](const Person& p) {return p.is_employed;});
    std::cout << "Median age for employed males = " <<
              ComputeMedianAge(employed_males.begin(), employed_males.end()) << std::endl;

    std::vector<Person> unemployed_males;
    std::copy_if(males.begin(), males.end(), std::back_inserter(unemployed_males),
                 [](const Person& p) {return !p.is_employed;});
    std::cout << "Median age for unemployed males = " <<
              ComputeMedianAge(unemployed_males.begin(), unemployed_males.end()) << std::endl;
}


/**
int main() {
    std::vector<Person> persons = {
            {31, Gender::MALE, false},
            {40, Gender::FEMALE, true},
            {24, Gender::MALE, true},
            {20, Gender::FEMALE, true},
            {80, Gender::FEMALE, false},
            {78, Gender::MALE, false},
            {10, Gender::FEMALE, false},
            {55, Gender::MALE, true},
    };
    PrintStats(persons);
    return 0;
}
 */