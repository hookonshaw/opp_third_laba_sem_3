#include "trapezoid.h"

#include <iostream>

Trapezoid::Trapezoid() {
    vertices.push_back(Point(0, 0));
    vertices.push_back(Point(3, 0));
    vertices.push_back(Point(2, 2));
    vertices.push_back(Point(1, 2));
}

Trapezoid::Trapezoid(const Point& p1, const Point& p2, const Point& p3, const Point& p4) {
    vertices.push_back(p1);
    vertices.push_back(p2);
    vertices.push_back(p3);
    vertices.push_back(p4);
}

double Trapezoid::area() const {
    return calcArea(vertices);
}

Point Trapezoid::center() const {
    return calcCenter(vertices);
}

void Trapezoid::read(std::istream& is) {
    vertices.clean();
    for (int i = 0; i < 4; ++i) {
        Point p;
        is >> p;
        vertices.push_back(p);
    }
}

void Trapezoid::write(std::ostream& os) const {
    os << "Trapezoid";
    for (size_t i = 0; i < vertices.length(); ++i) {
        os << " " << vertices[i]; 
    }
}