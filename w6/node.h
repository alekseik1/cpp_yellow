#pragma once
#include "date.h"
#include <memory>
#include <string>

using namespace std;

enum Comparison {
    Less = 0,
    LessOrEqual,
    Greater,
    GreaterOrEqual,
    Equal,
    NotEqual
};
enum LogicalOperation {
    Or = 0,
    And
};

class Node {
public:
    virtual bool Evaluate(const Date& date, const string& event) const = 0;
};

class EmptyNode: public Node {
public:
    bool Evaluate(const Date& date, const string& event) const override;
};

class DateComparisonNode: public Node {
public:
    DateComparisonNode(const Comparison& cmp, const Date& date);
    bool Evaluate(const Date& date, const string& event) const override;

protected:
    const Comparison _cmp;
    const Date _date;
};

class EventComparisonNode: public Node {
public:
    EventComparisonNode(const Comparison& cmp, const string& event);
    bool Evaluate(const Date& date, const string& event) const override;

protected:
    const Comparison _cmp;
    const Date _date;
};

class LogicalOperationNode: public Node {
public:
    LogicalOperationNode(const LogicalOperation& op, const shared_ptr<Node>& left, const shared_ptr<Node>& right);
    bool Evaluate(const Date& date, const string& event) const override;

protected:
    const LogicalOperation _op;
    const shared_ptr<Node> _left;
    const shared_ptr<Node> _right;
};