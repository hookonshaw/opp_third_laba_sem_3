#pragma once

#include "figure.h"

class Square: public Figure {
public:
    Square();
    Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

    double area() const override;
    Point center() const override;
    void read(std::istream& is) override;
    void write(std::ostream& os) const override;
};