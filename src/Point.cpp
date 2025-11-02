#include "Point.h"

Point::Point() : x(0), y(0) {

}

Point::Point(int x_p, int y_p) : x(x_p), y(y_p) {

}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

bool operator==(const Point& a, const Point& b) {
    return a.x == b.x && a.y == b.y;
}

bool operator!=(const Point& a, const Point& b) {
    return !(a == b);
}