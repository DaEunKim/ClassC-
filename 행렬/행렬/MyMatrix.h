//
//  MyMatrix.hpp
//  행렬
//
//  Created by 김다은 on 2017. 5. 28..
//  Copyright © 2017년 김다은. All rights reserved.
//

#ifndef MyMatrix_h
#define MyMatrix_h

#include <stdio.h>
#include <string>
using namespace std;

class myMatrix
{
public:
    // friend 함수
    friend myMatrix operator *(int value, const myMatrix& mat);
    
    friend ostream &operator << (ostream &outStream, const myMatrix& mat);
    
    friend istream &operator >> (istream &inStream, myMatrix& mat);
    
    // Constructor (생성자)
    myMatrix(int nRows = 1, int nCols = 1);
    myMatrix(int nRows, int nCols, int initValue);
    myMatrix(int nRows, int nCols, int *data);
    myMatrix(int nRows, int nCols, int **data);
    
    // Copy constructor (복사 생성자)
    myMatrix(const myMatrix& mat);
    
    // Destructor (소멸자)
    ~myMatrix();
    
    // Accessor functions (접근자)
    int getRows() const;
    int getCols() const;
    int* operator [](int i) const;
    int& operator ()(int i, int j) const;
    
    // Overloaded binary operators
    myMatrix operator +(const myMatrix& mat) const;
    myMatrix operator -(const myMatrix& mat) const;
    myMatrix operator *(const myMatrix& mat) const;
    myMatrix operator *(int value) const;
    
    // Overloaded assignment operators
    myMatrix& operator =(const myMatrix& mat);
    myMatrix& operator +=(const myMatrix& mat);
    myMatrix& operator -=(const myMatrix& mat);
    myMatrix& operator *=(const myMatrix& mat);
    myMatrix& operator *=(int value);
    
    // Overloading relational operators
    bool operator ==(const myMatrix& mat) const;
    bool operator !=(const myMatrix& mat) const;
    
    // Overloaded unary operators
    myMatrix operator -() const;    // unary minus
    
    // transpose the matrix
    myMatrix& transpose();

private:
    int rows;
    int cols;
    int **pData;
    // number of rows
    // number of columns
    // pointer to actual data

    void allocateMemory(); // allocate memory for pDdata
    void deleteMemory(); // delete memory for pData
    void errorMessage(string msg) const; // print error message and exit
};

#endif /* MyMatrix_h */









