#pragma once

#include <iostream>

struct Point{
    int x,y;

    Point();
    Point(int x, int y);

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend bool operator==(const Point& a, const Point& b);
    friend bool operator!=(const Point& a, const Point& b);
};