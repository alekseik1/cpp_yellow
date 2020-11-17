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

bool IsPalindrom(const string& str) {
    // Вы можете вставлять сюда различные реализации функции,
    // чтобы проверить, что ваши тесты пропускают корректный код
    // и ловят некорректный
}

void testEmpty() {
    Assert(IsPalindrom(""), "Empty string");
}

void testOneSymbol() {
    vector<string> strings = {
            "a",
            "3",
            "j",
            "h",
            "-",
    };
    for (string& s : strings)
        Assert(IsPalindrom(s), s);
}

void testNonSpace() {
    vector<pair<string, bool>> test_data = {
            //make_pair("лазерборехеробрезал", true),
            make_pair("1jhugiheguio3qhuiolewfhbcuakjbdshgcbsfhsfkgbalsvdqwdjhqwdjqwgfkerwghlkfhsuidavhuirhvbiuernvdsa;klvkopewuqfi43uyt7ughweruoiavhvaiourewhgu7tyu34ifquwepokvlk;asdvnreuibvhriuhvadiushfklhgwrekfgwqjdwqhjdwqdvslabgkfshfsbcghsdbjkaucbhfweloiuhq3oiugehiguhj1", true),
            make_pair("1jhugiheguio3qhui3lewfhbcuakjbdshgcbsfhsfkgbalsvdqwdjhqwdjqwgfkerwghlkfhsuidavhuirhvbiuernvdsa;klvkopewuqfi43uyt7ughweruoiavhvaiourewhgu7tyu34ifquwepokvlk;asdvnreuibvhriuhvadiushfklhgwrekfgwqjdwqhjdwqdvslabgkfshfsbcghsdbjkaucbhfweloiuhq3oiugehiguhj1", false),
            make_pair("fgiejg wefde wiufhg sdg s gs.    kpfjqiofhgw3u4ogh3u i.    ghejlrwkghewrlghlkergnwejrklghui34g. g wghow37hergogreh73wohgw g .g43iuhglkrjewngreklhglrwehgkwrljehg    .i u3hgo4u3wghfoiqjfpk    .sg s gds ghfuiw edfew gjeigf", true),
            make_pair("fgiejg wefde wi4444 sdg s gs.    kpfjqiofhgw3u4ogh3u i.    ghejlrwkghewrlghlkergnwejrklghui34g. g wghow37hergogreh73wohgw g .g43iuhglkrjewngreklhglrwehgkwrljehg    .i u3hgo4u3wghfoiqjfpk    .sg s gds ghfuiw edfew gjeigf", false),
            make_pair("pi32jrpto34t[].   asd]efw+_+!@)#_+!%()#%*@$)(%+)*@)(%&@$*)%@&#$ )_+@!()#_)+!&@*HDJICOUJNVADBUI{EBPVH *(F Y!(*#FYU@&*#FGH@*) y3278fh202hf8723y )*@HGF#*&@UYF#*(!Y F(* HVPBE{IUBDAVNJUOCIJDH*@&!+)_#)(!@+_) $#&@%)*$@&%()@*)+%()$@*%#)(%!+_#)@!+_+wfe]dsa   .][t43otprj23ip", true),
            make_pair("pi32jrpto34t[].   asd]efw+_+!@)#_+!%(0)#%*@$)(%+)*@)(%&@$*)%@&#$ )_+@!()#_)+!&@*HDJICOUJNVADBUI{EBPVH *(F Y!(*#FYU@&*#FGH@*) y3278fh202hf8723y )*@HGF#*&@UYF#*(!Y F(* HVPB2{IUBDAVNJUOCIJDH*@&!+)_#)(!@+_) $#&@%)*$@&%()@*)+%()$@*%#)(%!+_#)@!+_+wfe]dsa   .][t43otprj23ip", false),
            make_pair("         pi32jrpto34t[].   asd]efw+_+!@)#_+!%()#%*@$)(%+)*@)(%&@$*)%@&#$ )_+@!()#_)+!&@*HDJICOUJNVADBUI{EBPVH *(F Y!(*#FYU@&*#FGH@*) y3278fh202hf8723y )*@HGF#*&@UYF#*(!Y F(* HVPBE{IUBDAVNJUOCIJDH*@&!+)_#)(!@+_) $#&@%)*$@&%()@*)+%()$@*%#)(%!+_#)@!+_+wfe]dsa   .][t43otprj23ip         ", true),
            make_pair("        pi32jrpto34t[].   asd]efw+_+!@)#_+!%()#%*@$)(%+)*@)(%&@$*)%@&#$ )_+@!()#_)+!&@*HDJICOUJNVADBUI{EBPVH *(F Y!(*#FYU@&*#FGH@*) y3278fh202hf8723y )*@HGF#*&@UYF#*(!Y F(* HVPBE{IUBDAVNJUOCIJDH*@&!+)_#)(!@+_) $#&@%)*$@&%()@*)+%()$@*%#)(%!+_#)@!+_+wfe]dsa   .][t43otprj23ip         ", false),
            make_pair("         pi32jrpto34t[].   asd]efw+_+!@)#_+!%()#%*@$)(%+)*@)(%&@$*)%@&#$ )_+@!()#_)+!&@*HDJICOUJNVADB{EBPVH *(F Y!(*#FYU@&*#FGH@*) y3278fh202hf8723y )*@HGF#*&@UYF#*(!Y F(* HVPBE{IUBDAVNJUOCIJDH*@&!+)_#)(!@+_) $#&@%)*$@&%()@*)+%()$@*%#)(%!+_#)@!+_+wfe]dsa   .][t43otprj23ip         ", false),
            make_pair("aba", true),
            make_pair("cac", true),
            make_pair("acac", false),
            make_pair("caac", true),
            make_pair("caAc", false),
            make_pair("caAC", false),
            make_pair("CAac", false),
            make_pair("Caac", false),
            make_pair("caaC", false),
            make_pair("baac", false),
    };
    for (auto& p : test_data) {
        string s = p.first;
        bool expected = p.second;
        AssertEqual(IsPalindrom(s), expected, s);
    }
}

int main() {
    TestRunner runner;
    // добавьте сюда свои тесты
    runner.RunTest(testEmpty, "Empty");
    runner.RunTest(testOneSymbol, "One symbol");
    runner.RunTest(testNonSpace, "Non space");
    return 0;
}