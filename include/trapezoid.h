#pragma once

#include "figure.h"

class Trapezoid: public Figure {
public:
    Trapezoid();
    Trapezoid(const Point& p1, Point& p2, Point& p3, Point& p4);

    double area() const override;
    Point center() const override;
    void read(std::istream& is) override;
    void write(std::ostream& os) const override;
};