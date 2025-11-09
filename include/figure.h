#pragma once

#include <iostream>

#include "vector_Points.h"

class Figure {
public:
    virtual ~Figure() = default;
    
    virtual void write(std::ostream& os) const = 0;
    virtual void read(std::istream& is) = 0;
    virtual Point center() const = 0;
    virtual double area() const = 0;

    virtual explicit operator double() const;

    friend std::istream& operator>>(std::istream& is, Figure& f);
    friend std::ostream& operator<<(std::ostream& os, const Figure& f);
    
    friend bool operator==(const Figure& a, const Figure& b);
    friend bool operator!=(const Figure& a, const Figure& b);

protected:
    VectorPoints vertices;

    double calcArea(const VectorPoints& points) const;
    Point calcCenter(const VectorPoints& points) const;
};