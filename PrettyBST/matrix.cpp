#include "matrix.h"

Matrix::Matrix(const unsigned int rows, const unsigned int columns){
    data.resize(rows);
    for (int r=0; r<rows; r++){
        data.at(r).resize(columns);
    }
}

Matrix::Matrix(const unsigned int rows, const unsigned int columns, int initValue){
    data.resize(rows);
    for (int r=0; r<rows; r++){
        data.at(r).resize(columns, initValue);
    }
}

int Matrix::rows() const { return data.size(); }

int Matrix::columns() const { return data.at(0).size(); }

int& Matrix::at(const unsigned int row, const unsigned int column){
    return data.at(row).at(column);
}

void Matrix::move(const unsigned int row, const unsigned int column, int& orig) {
    data.at(row).at(column) = orig;
    orig = INT_MAX;
}
