#include "rectangle.h"

#include <iostream>

Rectangle::Rectangle() {
    vertices.push_back(Point(0, 0));
    vertices.push_back(Point(4, 0));
    vertices.push_back(Point(4, 2));
    vertices.push_back(Point(0, 2));
}

Rectangle::Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices.push_back(p1);
    vertices.push_back(p2);
    vertices.push_back(p3);
    vertices.push_back(p4);
}

double Rectangle::area() const {
    return calcArea(vertices);
}

Point Rectangle::center() const {
    return calcCenter(vertices);
}

void Rectangle::read(std::istream& is) {
    vertices.clean();
    for (int i = 0; i < 4; ++i) {
        Point p;
        is >> p;
        vertices.push_back(p);
    }
}

void Rectangle::write(std::ostream& os) const {
    os << "Rectangle";
    for (size_t i = 0; i < vertices.length(); ++i) {
        os << " " << vertices[i]; 
    }
}