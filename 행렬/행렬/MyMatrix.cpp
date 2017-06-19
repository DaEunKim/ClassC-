//
//  MyMatrix.cpp
//  행렬
//
//  Created by 김다은 on 2017. 5. 28..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include "MyMatrix.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

// Constructor
myMatrix::myMatrix(int nRows, int nCols){
    rows = nRows;
    cols = nCols;
    pData = NULL;
    allocateMemory();
    for(int i=0; i<nRows; i++)
        for(int j=0; j<nCols; j++)
            pData[i][j] = 0;
}

myMatrix::myMatrix(int nRows, int nCols, int initValue) : rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = initValue;
}

myMatrix::myMatrix(int nRows, int nCols, int *data) : rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = data[i*cols+j];
}

myMatrix::myMatrix(int nRows, int nCols, int **data) : rows(nRows), cols(nCols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = data[i][j];
}

myMatrix::~myMatrix(){
    if (pData != NULL)
        deleteMemory();
}

// Copy constructor
myMatrix::myMatrix(const myMatrix& mat):rows(mat.rows), cols(mat.cols), pData(NULL){
    allocateMemory();
    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            pData[i][j] = mat.pData[i][j];
}
// Accessor functions
int myMatrix::getRows() const {
    return rows;
}

int myMatrix::getCols() const {
    return cols;
}

int* myMatrix::operator [](int i) const{
    if((i < 0) || (i >= rows))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i];
}

int& myMatrix::operator ()(int i, int j) const{
    if((i < 0) || (i >= rows) || (j < 0) || (j >= cols))
        errorMessage("Accessing out-of-bound value of a matrix");
    return pData[i][j];
    
}
// Overloaded binary operators
myMatrix myMatrix::operator +(const myMatrix& mat) const{
    if ((rows != mat.rows) || (cols != mat.cols))
        errorMessage("cannot add two matrices of different size");
    
    myMatrix newMat(rows,cols);
    
    for(int i = 0;i< rows;i++){
        for(int j = 0;j< cols;j++){
            newMat[i][j] = pData[i][j] + mat[i][j];
        }
    }
    
    return newMat;
}

myMatrix myMatrix::operator -(const myMatrix& mat) const{
    if ((rows != mat.rows) || (cols != mat.cols))
        errorMessage("cannot do subtraction between two matrices of different size");
    
    //
    myMatrix newMat(rows,cols);
    
    for(int i = 0;i< rows;i++){
        for(int j = 0;j< cols;j++){
            newMat[i][j] = pData[i][j] - mat[i][j];
        }
    }
    return newMat;
    
}
myMatrix myMatrix::operator *(const myMatrix& mat) const
{
    if (cols != mat.rows)
        errorMessage("cannot do multiplication between the given two matrices");
    
    myMatrix newMat(rows, mat.cols);
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            for(int k = 0;k <mat.cols;k++){
                newMat[i][k] += pData[i][j]*mat[j][k];
            }
        }
    }
    
    return newMat;
}
myMatrix myMatrix::operator *(int value) const
{
    myMatrix newMat(rows,cols);
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            newMat[i][j] = pData[i][j] * value;
        }
    }
    return newMat;
}
// Assignment operators
myMatrix& myMatrix::operator =(const myMatrix& mat)
{
    if(&mat == this)
        return *this;
    
    rows = mat.rows;
    cols = mat.cols;
    allocateMemory();
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            pData[i][j] = mat[i][j];
        }
    }
    
    return *this;
}
myMatrix& myMatrix::operator +=(const myMatrix& mat)
{
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            pData[i][j] += mat[i][j];
        }
    }
    
    return *this;
    
}
myMatrix& myMatrix::operator -=(const myMatrix& mat)
{
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            pData[i][j] -= mat[i][j];
        }
    }
    return *this;
}
myMatrix& myMatrix::operator *=(const myMatrix& mat)
{
//    myMatrix tmp = *this;
//    cols = mat.cols;
//    allocateMemory();

    *this = (*this * mat);
    
//    for(int i = 0;i<rows;i++){
//        for(int j = 0;j<cols;j++){
//            for(int k = 0;k<mat.cols;k++){
//                pData[i][k] += tmp.pData[i][j]*mat[j][k];
//            }
//        }
//    }
    
    return *this;
}
myMatrix& myMatrix::operator *=(int value)
{
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            pData[i][j] *= value;
        }
    }
    return *this;
}
// Overloading relational operators
bool myMatrix::operator ==(const myMatrix& mat) const{
    if ((rows != mat.rows) || (cols != mat.cols))
        return false;
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            if(pData[i][j] != mat.pData[i][j]){
                return false;
            }
        }
    }
    
    return true;
}
bool myMatrix::operator !=(const myMatrix& mat) const
{
    return !((*this) == mat);
}
// Overloaded unary operators
myMatrix myMatrix::operator -() const
{
    myMatrix tmp = *this;
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            tmp.pData[i][j] *= -1;
        }
    }
    
    return tmp;
}
// transpose the matrix
myMatrix& myMatrix::transpose()
{
    myMatrix tmp = *this;
    rows = tmp.cols;
    cols = tmp.rows;
    allocateMemory();
    
    for(int i = 0;i<rows;i++){
        for(int j = 0;j<cols;j++){
            pData[i][j] = tmp.pData[j][i];
        }
    }
    
    return *this;
}
// private functions
void myMatrix::allocateMemory(){
    if (pData != NULL)
        deleteMemory();
    pData = new int * [rows];
    if(pData == NULL)
        // unary minus
        
        errorMessage("Memory allocation error");
    pData[0] = new int [rows*cols];
    if(pData[0] == NULL)
    {
        delete [] pData;
        errorMessage("Memory allocation error");
    }
    for(int i=1; i<rows; i++)
        pData[i] = pData[0] + i * cols;
}
void myMatrix::deleteMemory()
{
    delete [] pData[0];
    delete [] pData;
    pData = NULL;
}
void myMatrix::errorMessage(string str) const{
    cout << "Error: " << str << endl;
    exit(1);
}
// friend functions
myMatrix operator *(int value, const myMatrix& mat){
    myMatrix tmp(mat.rows, mat.cols);
    
    for(int i = 0;i<tmp.rows;i++){
        for(int j = 0;j<tmp.cols;j++){
            tmp[i][j] = value* mat[i][j];
        }
    }
    return tmp;
}

ostream &operator << (ostream &outStream, const myMatrix& mat)
{
    outStream << mat.rows << "*" << mat.cols << endl;
    
    for(int i=0; i<mat.rows; i++){
        for (int j=0; j<mat.cols; j++)
            outStream << mat[i][j] << " ";
        
        outStream << endl;
    }
    return outStream;
}

istream &operator >> (istream &inStream, myMatrix& mat){
    mat.deleteMemory();
    
    inStream >> mat.rows >> mat.cols;
    mat.allocateMemory();
    for(int i=0; i<mat.rows; i++)
    {
        for (int j=0; j<mat.cols; j++)
            inStream >> mat[i][j];
    }
    return inStream;
}




