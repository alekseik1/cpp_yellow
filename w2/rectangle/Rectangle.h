//
// Created by Aleksei Kozharin on 17.11.2020.
//

#ifndef DECOMP_STARTER_RECTANGLE_H
#define DECOMP_STARTER_RECTANGLE_H

class Rectangle {
public:
    Rectangle(int width, int height);

    int GetArea() const;

    int GetPerimeter() const;

    int GetWidth() const;
    int GetHeight() const;

private:
    int width_, height_;
};
#endif //DECOMP_STARTER_RECTANGLE_H
