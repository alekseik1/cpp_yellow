//
// Created by Aleksei Kozharin on 23.11.2020.
//
#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

struct Action {
    char op;
    int rhs;
};

istream& operator>>(istream& is, Action& a) {
    is >> a.op >> a.rhs;
    return is;
}

bool needBrackets(const char& op1, const char& op2) {
    return ((op1 == '-') || (op1 == '+')) && ((op2 == '*') || (op2 == '/'));
}

bool bracketsPredicate(const Action& op) {
    static char prev = '*';
    bool result = needBrackets(prev, op.op);
    prev = op.op;
    return result;
}

int main() {
    int number, total_operations;
    cin >> number >> total_operations;
    vector<Action> actions(total_operations);
    if (total_operations == 0) {
        cout << number << endl;
        exit(0);
    }
    for(auto& op : actions) cin >> op;
    auto numOfBrackets = count_if(actions.begin(), actions.end(), bracketsPredicate);
    for (auto j=0; j < numOfBrackets; ++j) cout << '(';
    cout << number;
    char prev = '*';
    for(const auto& action : actions) {
        if (needBrackets(prev, action.op)) cout << ')';
        prev = action.op;
        cout << ' ' << action.op << ' ' << action.rhs;
    }
}