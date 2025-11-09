#include "figure.h"

#include <cmath>


double Figure::calcArea(const VectorPoints& points) const {
    if (points.length() < 3) return 0.0;
    
    double total = 0.0;
    size_t n = points.length();
    
    for (size_t i = 0; i < n; ++i) {
        size_t next = (i + 1) % n;
        total += points[i].x * points[next].y;
        total -= points[next].x * points[i].y;
    }
    
    return std::abs(total) / 2.0;
}

Point Figure::calcCenter(const VectorPoints& points) const {
    if (points.IsEmpty()) {
        return Point(0, 0);
    }
    
    int cen_x = 0;
    int cen_y = 0;
    for (size_t i = 0; i < points.length(); ++i) {
        cen_x += points[i].x;
        cen_y += points[i].y;
    }
    
    return Point(cen_x / static_cast<int>(points.length()), cen_y / static_cast<int>(points.length()));
}

Figure::operator double() const {
    return static_cast<double>(area());
}

std::istream& operator>>(std::istream& is, Figure& f) {
    f.read(is);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Figure& f) {
    f.write(os);
    return os;
}

bool operator==(const Figure& a, const Figure& b) {
    if (a.vertices.length() != b.vertices.length()) {
        return false;
    }
    
    for (size_t i = 0; i < a.vertices.length(); ++i) {
        if (a.vertices[i] != b.vertices[i]) {
            return false;
        }
    }
    return true;
}

bool operator!=(const Figure& a, const Figure& b) {
    return !(a == b);
}