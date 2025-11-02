#include "vector-figure.h"

#include <algorithm>
#include <stdexcept>

VectorFigure::VectorFigure(): size(0), capacity(4), data(new Figure*[capacity]) {

}

VectorFigure::VectorFigure(const VectorFigure& other): size(other.size), capacity(other.capacity), data(new Figure*[capacity]) {
    std::copy(other.data, other.data + size, data);
}

VectorFigure::VectorFigure(VectorFigure&& other) noexcept: size(other.size), capacity(other.capacity), data(other.data) {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

VectorFigure::~VectorFigure() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    delete[] data;
}

void VectorFigure::resize(size_t new_capacity) {
    capacity = new_capacity;
    Figure** new_data = new Figure*[capacity];
    std::copy(data, data + size, new_data);
    delete[] data;
    data = new_data;
}

void VectorFigure::push_back(Figure* figure) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = figure;
}

void VectorFigure::pop_back() {
    if (size > 0) {
        delete data[--size];
    }
}

void VectorFigure::erase(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    
    delete data[index];
    for (size_t i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    --size;
}

void VectorFigure::clean() {
    for (size_t i = 0; i < size; ++i) {
        delete data[i];
    }
    size = 0;
}

Figure* VectorFigure::operator[](size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const Figure* VectorFigure::operator[](size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

size_t VectorFigure::length() const {
    return size;
}

bool VectorFigure::IsEmpty() const {
    return size == 0;
}

double VectorFigure::all_area() const {
    double total = 0.0;
    for (size_t i = 0; i < size; ++i) {
        total += data[i]->area();
    }
    return total;
}