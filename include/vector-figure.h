#pragma once

#include "figure.h"

class VectorFigure {
private:
    size_t size;
    size_t capacity;
    Figure** data;

    void resize(size_t new_capacity);

public:
    VectorFigure();
    VectorFigure(size_t n);
    VectorFigure(VectorFigure&& other) noexcept;
    VectorFigure(const VectorFigure& other);
    ~VectorFigure();

    size_t length() const;
    bool IsEmpty() const;
    double all_area() const;

    void push_back(const Point& p);
    void pop_back();
    void erase(size_t index);
    void clean();

    Figure& operator[](size_t index);
    const Figure& operator[](size_t index) const;
};