//
//  Matrix.h
//  Matrix
//
//  Created by Daniel Walsh on 11/28/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//

#ifndef __Matrix__Matrix__
#define __Matrix__Matrix__

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
    inline int Rows() const { return _rows; }
    inline int Cols() const { return _cols; }
    inline vector<vector<int> > Values() const { return _values; }
    
    // operator overloads
    Matrix operator + (const Matrix&);
    Matrix operator * (const Matrix&);
    Matrix operator * (const vector<int>&);
    
    // friends
    friend ostream& operator << (ostream&, const Matrix&);
};

#endif /* defined(__Matrix__Matrix__) */
