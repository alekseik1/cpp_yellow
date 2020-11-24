#include "node.h"
#include "date.h"

bool EmptyNode::Evaluate(const Date& date, const string& event) const { return true; }
DateComparisonNode::DateComparisonNode(
        const Comparison &cmp, const Date &date
        ): _cmp(cmp), _date(date) {}
bool DateComparisonNode::Evaluate(const Date &date, const string &event) const {
    switch (_cmp) {
        case Comparison::Less:
            return date < _date;
        case Comparison::LessOrEqual:
            return date <= _date;
        case Comparison::Greater:
            return date > _date;
        case Comparison::GreaterOrEqual:
            return date >= _date;
        case Comparison::Equal:
            return date == _date;
        case Comparison::NotEqual:
            return date != _date;
        default:
            throw invalid_argument("Wrong operator for comparison. Should be one of <, <=, >, >=, ==, !=");
    }
}

LogicalOperationNode::LogicalOperationNode(
        const LogicalOperation &op, const shared_ptr<Node> &left, const shared_ptr<Node> &right
        ): _op(op), _left(left), _right(right) {}

bool LogicalOperationNode::Evaluate(const Date &date, const string &event) const {
    switch (_op) {
        case LogicalOperation::Or:
            return _left->Evaluate(date, event) || _right->Evaluate(date, event);
        case LogicalOperation::And:
            return _left->Evaluate(date, event) && _right->Evaluate(date, event);
        default:
            throw invalid_argument("Wrong logical operator. Should be one of AND, OR");
    };
}
