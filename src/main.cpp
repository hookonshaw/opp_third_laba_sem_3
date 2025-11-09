#include <iostream>

#include "figure.h"
#include "square.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "vector-figure.h"

int main() {
    VectorFigure figures;
    int count;
    
    std::cout << "write type of figure: ";
    std::cin >> count;
    std::cout << "1 is  square, 2 is Rectangle, 3 is Trapezoid\n";

    for (int i = 0; i < count; ++i) {
        char type;
        std::cin >> type;
        Figure* figure = nullptr;

        if (type == '1') {
            figure = new Square();
        } else if (type == '2') {
            figure = new Rectangle();
        } else if (type == '3') {
            figure = new Trapezoid();
        } else {
            std::cout << "Invalid figure type\n";
            continue;
        }

        figure->read(std::cin);
        figures.push_back(figure);
    }

    std::cout << "\nFigures info:\n";
    for (size_t i = 0; i < figures.length(); ++i) {
        const Figure* fig = figures[i];
        std::cout << "figure " << i << ": ";
        fig->write(std::cout);
        std::cout << " area: " << fig->area();
        std::cout << " center: " << fig->center();
        std::cout << std::endl;
    }

    std::cout << "all area: " << figures.all_area() << std::endl;

    if (!figures.IsEmpty()) {
        std::cout << "\nwrite erase index: ";
        size_t index;
        std::cin >> index;

        if (index < figures.length()) {
            figures.erase(index);
            std::cout << "erased successfully\n";
        } else {
            std::cout << "Invalid index\n";
        }
    }

    std::cout << ": " << figures.length() << std::endl;
    return 0;
}