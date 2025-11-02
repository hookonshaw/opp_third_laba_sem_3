#include "square.h"

#include <iostream>

Square::Square() {
    vertices.push_back(Point(0, 0));
    vertices.push_back(Point(2, 0));
    vertices.push_back(Point(2, 2));
    vertices.push_back(Point(0, 2));
}

Square::Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices.push_back(p1);
    vertices.push_back(p2);
    vertices.push_back(p3);
    vertices.push_back(p4);
}

double Square::area() const {
    return calcArea(vertices);
}

Point Square::center() const {
    return calcCenter(vertices);
}

void Square::read(std::istream& is) {
    vertices.clean();
    for (int i = 0; i < 4; ++i) {
        Point p;
        is >> p;
        vertices.push_back(p);
    }
}

void Square::write(std::ostream& os) const {
    os << "Square";
    for (size_t i = 0; i < vertices.length(); ++i) {
        os << " " << vertices[i]; 
    }
}