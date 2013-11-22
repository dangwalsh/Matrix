//
//  main.cpp
//  Matrix
//
//  Created by Daniel Walsh on 11/21/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//
//#define DBG

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
    
private:
    int _rows;
    int _cols;
    vector<vector<int> > _values;
    
public:
    // constructors
    Matrix():_rows(0),_cols(0)
    {
#ifdef DBG
        cout << "default const" << endl;
#endif
    }
    Matrix(int r, int c):
    _rows(r),_cols(c)
    {
#ifdef DBG
        cout << "param const" << endl;
#endif
        vector<int> vec(_cols);
        vector<vector<int> > mat(_rows,vec);
        _values = mat;
    }
    Matrix(vector<vector<int> > v):
    _rows(v.size()),_cols(v[0].size()),_values(v)
    {
#ifdef DBG
        cout << "param const" << endl;
#endif
    }
    Matrix(const Matrix &rhs)
    {
#ifdef DBG
        cout << "copy const" << endl;
#endif
        _rows = rhs._rows;
        _cols = rhs._cols;
        _values = rhs._values;
    }
    
    // destructor
    ~Matrix(){
#ifdef DBG
        cout << "destructor" << endl;
#endif
    }
    
    // accessors
    int Rows() const { return _rows; }
    int Cols() const { return _cols; }
    vector<vector<int> > Values() const { return _values; }
    
    // operator overloads
    Matrix operator+(const Matrix&);
    Matrix operator*(const Matrix&);
    Matrix operator*(const vector<int>&);
    
    // friends
    friend ostream& operator<<(ostream&, const Matrix&);
};



int main()
{
    int col, row, val;
    
    cout << "number of columns for matrix 1: ";
    cin >> col;
    cout << "number of rows for matrix 1: ";
    cin >> row;
    
    vector<vector<int>> mat1;
    vector<int> vec;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j){
#ifdef DBG
            vec.push_back(j+i);
#else
            cout << i << "," << j << ": ";
            cin >> val;
            vec.push_back(val);
#endif
        }
        mat1.push_back(vec);
        vec.clear();
    }
    cout << endl;
    
    Matrix m1(mat1);
    cout << m1 << endl;
    
    cout << "number of columns for matrix 2: ";
    cin >> col;
    cout << "number of rows for matrix 2: ";
    cin >> row;
    
    vector<vector<int>> mat2;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j)
#ifdef DBG
            vec.push_back(j+i);
#else
        cout << i << "," << j << ": ";
        cin >> val;
        vec.push_back(val);
#endif
        mat2.push_back(vec);
        vec.clear();
    }
    cout << endl;
    
    Matrix m2(mat2);
    cout << m2 << endl;
    
    /*
    int col = 3;
    int row = 3;
    
    vector<vector<int>> mat1;
    vector<vector<int>> mat2;
    vector<int> vec;
    
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            vec.push_back(j+i);
        }
        mat1.push_back(vec);
        vec.clear();
    }
    
    for (vector<vector<int> >::iterator it = mat1.begin(); it != mat1.end(); ++it) {
        vector<int> v = *it;
        for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
            cout << *itr << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    for (int i = 0; i < col; ++i) {
        for (int j = 0; j < row; ++j) {
            vec.push_back(j+i);
        }
        mat2.push_back(vec);
        vec.clear();
    }
    
    for (vector<vector<int> >::iterator it = mat2.begin(); it != mat2.end(); ++it) {
        vector<int> v = *it;
        for (vector<int>::iterator itr = v.begin(); itr != v.end(); ++itr) {
            cout << *itr << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    
    Matrix m1(mat1);
    Matrix m2(mat2);
    
    Matrix m3 = m1 + m2;
    cout << m3 << endl;
    
    Matrix m4 = m1 * m2;
    cout << m4 << endl;
    
    for (int i = 0; i < row; ++i)
        vec.push_back(i);
    
    Matrix m5 = m1 * vec;
    cout << m5 << endl;
    */
    
    return EXIT_SUCCESS;
}


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
    if (Rows() != rhs.Cols()) exit(1);
    if (Cols() != rhs.Rows()) exit(1);
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
    if (Rows() != rhs.size()) exit(1);
    
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
            os << *itr << " ";
        }
        os << "\n";
    }
    return os;
}

