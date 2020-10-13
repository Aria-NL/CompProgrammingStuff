#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
#include <climits>

class Matrix{
    public:
        Matrix(const unsigned int rows, const unsigned int columns);
        Matrix(const unsigned int rows, const unsigned int columns, int initValue);
        int& at(const unsigned int row, const unsigned int column);
        int rows() const;
        int columns() const;
    private:
        std::vector< std::vector<int> > data;
};
#endif
