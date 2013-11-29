//
//  Matrix.cpp
//  Matrix
//
//  Created by Daniel Walsh on 11/28/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//

#include "Matrix.h"
#include "MatrixExceptions.h"

Matrix Matrix::operator+(const Matrix &rhs)
{
    vector<int> tempv(Cols());
    vector<vector<int> > tempvv(Rows(),tempv);
    
    for (int i = 0; i < Rows(); ++i) {
        for (int j = 0; j < Cols(); ++j) {
            tempvv.at(i).at(j) = Values().at(i).at(j) + rhs.Values().at(i).at(j);
        }
    }
    return Matrix(tempvv);
}

Matrix Matrix::operator*(const Matrix &rhs)
{
    if (Rows() != rhs.Cols()) throw MatrixExceptions::IncompatibleDimensions();
    if (Cols() != rhs.Rows()) throw MatrixExceptions::IncompatibleDimensions();
    
    vector<int> tempv(Rows());
    vector<vector<int> > tempvv(rhs.Cols(),tempv);
    
    for (int i = 0; i < Rows(); ++i) {
        for (int j = 0; j < rhs.Cols(); ++j) {
            for (int k = 0; k < rhs.Rows(); ++k) {
                tempvv.at(i).at(j) += Values().at(i).at(k) * rhs.Values().at(k).at(j);
            }
        }
    }
    return Matrix(tempvv);
}

Matrix Matrix::operator*(const vector<int> &rhs)
{
    if (Rows() != rhs.size()) throw MatrixExceptions::IncompatibleDimensions();
    
    vector<int> tempv(Rows());
    vector<vector<int> > tempvv(Cols(),tempv);
    
    for (int i = 0; i < Rows(); ++i) {
        for (int j = 0; j < Cols(); ++j) {
            tempvv.at(i).at(j) = Values().at(i).at(j) * rhs.at(j);
        }
    }
    return Matrix(tempvv);
}

ostream& operator<<(ostream &os, const Matrix &rhs)
{
    vector<vector<int>> vv = rhs.Values();
    for (vector<vector<int>>::iterator it = vv.begin(); it != vv.end(); ++it) {
        vector<int> v = *it;
        for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
            os << *itr << '\t';
        }
        os << '\n';
    }
    return os;
}
