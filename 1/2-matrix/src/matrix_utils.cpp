#include "matrix_utils.h"
#include <iostream>
#include <iomanip>

void print(const Matrix &matrix)
{
    for(unsigned i = 0; i < dims; i++) {
        for(unsigned j = 0; j < dims; j++) {
            std::cout << std::setw(3) << std::setfill(' ');
            std::cout << matrix.get(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

void rand(Matrix &matrix)
{
    for(unsigned i = 0; i < dims; i++)
        for(unsigned j = 0; j < dims; j++)
            matrix.set(i, j, rand() % 10);
}