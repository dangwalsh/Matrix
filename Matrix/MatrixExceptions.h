//
//  MatrixExceptions.h
//  Matrix
//
//  Created by Daniel Walsh on 11/28/13.
//  Copyright (c) 2013 Daniel Walsh. All rights reserved.
//

#ifndef __Matrix__MatrixExceptions__
#define __Matrix__MatrixExceptions__

#include <iostream>

using namespace std;

namespace MatrixExceptions {
    
    class IncompatibleDimensions {
        
    protected:
        string _message;
        
    public:
        IncompatibleDimensions( ) :
            _message("Matrix dimensions are incompatible for this operation.")
        {
#ifdef _DEBUG
            cout << "default except const\n";
#endif
        }
        IncompatibleDimensions(string m) :
            _message(m)
        {
#ifdef _DEBUG
            cout << "param except const\n";
#endif
        }
        inline string Message( ) const { return _message; }
    };
}

#endif /* defined(__Matrix__MatrixExceptions__) */
