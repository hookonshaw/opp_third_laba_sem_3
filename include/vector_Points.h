#pragma once

#include "Point.h"

class VectorPoints {
private:
    size_t size;
    size_t capacity;
    Point* data;

    void resize(size_t new_capacity);

public:
    VectorPoints();
    VectorPoints(size_t n);
    VectorPoints(VectorPoints&& other) noexcept;
    VectorPoints(const VectorPoints& other);
    ~VectorPoints();

    size_t length() const;
    bool IsEmpty() const;

    void push_back(const Point& p);
    void pop_back();
    void set(size_t index, const Point& p);
    void clean();

    Point& operator[](size_t index);
    const Point& operator[](size_t index) const;
};