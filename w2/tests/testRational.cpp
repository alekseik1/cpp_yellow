#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
    os << "{";
    bool first = true;
    for (const auto& x : s) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << x;
    }
    return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
    os << "{";
    bool first = true;
    for (const auto& kv : m) {
        if (!first) {
            os << ", ";
        }
        first = false;
        os << kv.first << ": " << kv.second;
    }
    return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << " hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void Assert(bool b, const string& hint) {
    AssertEqual(b, true, hint);
}

class TestRunner {
public:
    template <class TestFunc>
    void RunTest(TestFunc func, const string& test_name) {
        try {
            func();
            cerr << test_name << " OK" << endl;
        } catch (exception& e) {
            ++fail_count;
            cerr << test_name << " fail: " << e.what() << endl;
        } catch (...) {
            ++fail_count;
            cerr << "Unknown exception caught" << endl;
        }
    }

    ~TestRunner() {
        if (fail_count > 0) {
            cerr << fail_count << " unit tests failed. Terminate" << endl;
            exit(1);
        }
    }

private:
    int fail_count = 0;
};

/**
class Rational {
public:
    // Вы можете вставлять сюда различные реализации,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный

    Rational();
    Rational(int numerator, int denominator) {
    }

    int Numerator() const {
    }

    int Denominator() const {
    }
};
*/


void testEmpty() {
    Rational empty = Rational();
    AssertEqual(empty.Numerator(), 0);
    AssertEqual(empty.Denominator(), 1);
}

void testZeroNumerator() {
    Rational empty = Rational(0, 34638);
    AssertEqual(empty.Numerator(), 0);
    AssertEqual(empty.Denominator(), 1);
}

void testPositivePositive() {
    for (int num : {1, 5, 12384}) {
        for (int denom : {5, 234, 123}) {
            Rational r = Rational(num, denom);
            Assert(r.Numerator() > 0, "Numerator is positive");
            Assert(r.Denominator() > 0, "Denominator is positive");
        }
    }
}

void testPositiveNegative() {
    for (int num : {-3, -52, -132384}) {
        for (int denom : {-55, -3234, -3123}) {
            Rational r = Rational(num, denom);
            Assert(r.Numerator() > 0, "Numerator is positive");
            Assert(r.Denominator() > 0, "Denominator is positive");
        }
    }
}

void testSimplify() {
    vector<tuple<int, int, int, int>> test_data = {
            make_tuple(10, 2, 5, 1),
            make_tuple(50, 100, 1, 2),
            make_tuple(7, 21, 1, 3),
            make_tuple(-13, -39, 1, 3),
            make_tuple(-8, 40, -1, 5)
    };
    for (auto& data : test_data) {
        Rational r = Rational(get<0>(data), get<1>(data));
        AssertEqual(r.Numerator(), get<2>(data));
        AssertEqual(r.Denominator(), get<3>(data));
    }
}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(testEmpty, "Empty");
    runner.RunTest(testZeroNumerator, "Zero numerator");
    runner.RunTest(testPositivePositive, "Positive all");
    runner.RunTest(testPositiveNegative, "Negative becomes positive");
    runner.RunTest(testSimplify, "Simplification");
    return 0;
}