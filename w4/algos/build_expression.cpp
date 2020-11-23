//
// Created by Aleksei Kozharin on 23.11.2020.
//
#include <iostream>
#include <deque>

using namespace std;

struct Action {
    char op;
    int rhs;
};

istream& operator>>(istream& is, Action& a) {
    char op;
    int rhs;
    is >> op >> rhs;
    a.op = op;
    a.rhs = rhs;
    return is;
}

int main() {
    int number, total_operations;
    cin >> number >> total_operations;
    deque<Action> actions;
    if (total_operations == 0) {
        cout << number << endl;
        exit(0);
    }
    for(auto i=0; i < total_operations; ++i) {
        Action action; cin >> action;
        // cout << action.op << " " << action.rhs << endl;
        actions.push_back(action);
    }
    for (auto j=0; j < total_operations; ++j) cout << "(";
    cout << number;
    for(auto i=0; i < total_operations; ++i) {
        auto act = actions.front();
        cout << ") " << act.op << " " << act.rhs;
        actions.pop_front();
    }
}

