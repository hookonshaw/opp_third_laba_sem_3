#include "vector_Points.h"

#include <algorithm>

VectorPoints::VectorPoints() : size(0), capacity(4), data(new Point[capacity]) {

}

VectorPoints::VectorPoints(size_t n) : size(n), capacity(n * 2), data(new Point[capacity]) {

}

VectorPoints::VectorPoints(const VectorPoints& other) : size(other.size), capacity(other.capacity), data(new Point[capacity]) {
    std::copy(other.data, other.data + size, data);
}

VectorPoints::VectorPoints(VectorPoints&& other) noexcept : size(other.size), capacity(other.capacity), data(other.data) {
    other.size = 0;
    other.capacity = 0;
    other.data = nullptr;
}

VectorPoints::~VectorPoints() {
    delete[] data;
}

size_t VectorPoints::length() const {
    return size;
}

bool VectorPoints::IsEmpty() const {
    return size == 0;
}

void VectorPoints::resize(size_t new_capacity) {
    capacity = new_capacity;
    Point* new_data  = new Point[capacity];
    std::copy(data, data + size, new_data);
    delete[] data;
    data = new_data;
}

void VectorPoints::push_back(const Point& p) {
    if (size >= capacity) {
        resize(capacity * 2);
    }
    data[size++] = p;
}

void VectorPoints::pop_back() {
    if (size > 0){
        --size;
    }
}

void VectorPoints::set(size_t index, const Point& p) {
    if (index < size) {
        data[index] = p;
    }
}


void VectorPoints::clean() {
    size = 0;
}

Point& VectorPoints::operator[](size_t index) {
    return data[index];
}

const Point& VectorPoints::operator[](size_t index) const {
    return data[index];
}