//
// Created by Aleksei Kozharin on 24.11.2020.
//
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <iomanip>
#include <math.h>

using namespace std;

class Figure {
public:
    virtual string Name() = 0;
    virtual double Perimeter() = 0;
    virtual double Area() = 0;
    virtual ~Figure() = default;
};

class Triangle: public Figure {
public:
    Triangle(double& a, double& b, double& c): a_(a), b_(b), c_(c) {};
    string Name() override { return "TRIANGLE"; }
    double Perimeter() override { return a_ + b_ + c_; }
    double Area() override {
        double half_p = 0.5*(a_ + b_ + c_);
        return sqrt(half_p * (half_p - a_) * (half_p - b_) * (half_p - c_));
    }

protected:
    const double a_, b_, c_;
};

class Rect: public Figure {
public:
    Rect(double width, double height): width_(width), height_(height) {}
    string Name() override { return "RECT"; }
    double Perimeter() override { return 2*(width_ + height_); }
    double Area() override { return width_ * height_; }

protected:
    const double width_, height_;
};

class Circle: public Figure {
public:
    explicit Circle(double r): r_(r) {}
    string Name() override { return "CIRCLE"; }
    double Perimeter() override { return 2 * 3.14 * r_; }
    double Area() override { return 3.14 * r_ * r_; }

protected:
    const double r_;
};

shared_ptr<Figure> CreateFigure(istream& is) {
    string fig_name; is >> fig_name;
    if (fig_name == "RECT") {
        double width, height;
        is >> width >> height;
        return make_shared<Rect>(width, height);
    } else if (fig_name == "TRIANGLE") {
        double a, b, c;
        is >> a >> b >> c;
        return make_shared<Triangle>(a, b, c);
    } else if (fig_name == "CIRCLE") {
        double r;
        is >> r;
        return make_shared<Circle>(r);
    }
    return nullptr;
}

int main() {
    vector<shared_ptr<Figure>> figures;
    for (string line; getline(cin, line); ) {
        istringstream is(line);

        string command;
        is >> command;
        if (command == "ADD") {
            // Пропускаем "лишние" ведущие пробелы.
            // Подробнее об std::ws можно узнать здесь:
            // https://en.cppreference.com/w/cpp/io/manip/ws
            is >> ws;
            figures.push_back(CreateFigure(is));
        } else if (command == "PRINT") {
            for (const auto& current_figure : figures) {
                cout << fixed << setprecision(3)
                     << current_figure->Name() << " "
                     << current_figure->Perimeter() << " "
                     << current_figure->Area() << endl;
            }
        }
    }
    return 0;
}