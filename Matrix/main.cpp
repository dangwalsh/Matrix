//
//  main.cpp
//  Matrix
//
//  Created by Daniel Walsh on 11/21/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//
//#define _DEBUG

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "MatrixExceptions.h"

using namespace std;

int main()
{
    int col, row, val;
    
    cout << "Number of columns for matrix A: ";
    cin >> col;
    cout << "Number of rows for matrix A: ";
    cin >> row;
    
    vector<vector<int> > matA;
    vector<int> vec;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j){
#ifdef _DEBUG
            vec.push_back(j+i);
#else
            cout << i << "," << j << ": ";
            cin >> val;
            vec.push_back(val);
#endif
        }
        matA.push_back(vec);
        vec.clear();
    }
    cout << endl;
    
    Matrix A(matA);
    cout << "Matrix A:\n" << A << endl;
    
    cout << "Number of columns for matrix B: ";
    cin >> col;
    cout << "Number of rows for matrix B: ";
    cin >> row;
    
    vector<vector<int> > matB;
    for (int i = 1; i <= row; ++i) {
        for (int j = 1; j <= col; ++j){
#ifdef _DEBUG
            vec.push_back(j+i);
#else
        cout << i << "," << j << ": ";
        cin >> val;
        vec.push_back(val);
#endif
        }
        matB.push_back(vec);
        vec.clear();
    }
    cout << endl;
    
    Matrix B(matB);
    cout << "Matrix B:\n" << B << endl;
    
    try {
        Matrix C(A * B);
        cout << "Matrix C: [A × B]\n" << C << endl;
    } catch (MatrixExceptions::IncompatibleDimensions e) {
        cerr << e.Message() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}

