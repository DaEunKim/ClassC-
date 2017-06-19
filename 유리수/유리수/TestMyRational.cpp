//
//  TestMyRational.cpp
//  유리수
//
//  Created by 김다은 on 2017. 5. 30..
//  Copyright © 2017년 김다은. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyRational.h"
using namespace std;

void testSimpleCase();
void testDataFromFile();
void sortDates(MyRational rationals[], int n);

int main(){
    testSimpleCase();
    testDataFromFile();
}
void testSimpleCase()
{
    MyRational frac1(2), frac2(3, 2), frac3(6, 4), frac4(12, 8), frac5, frac6, frac7;
    
    cout << frac1 <<" "<< frac2 << " " << frac3 << " " << frac4 << " " << frac5 << endl;
    
    cout << frac1.getNumerator() << " " << frac1.getDenominator() << endl;
    
    cout << frac1 * frac2 << " " << frac1 + frac3 <<" "<< frac2 - frac1 << " " << frac3 / frac2 << endl;
    
    cout << ((frac1 < frac2) ? 1 : 0) << " "
    << ((frac1 <= frac2) ? 1 : 0) << " "
    << ((frac1 > frac2) ? 1 : 0) << " "
    << ((frac1 >= frac2) ? 1 : 0) << " "
    << ((frac1 == frac2) ? 1 : 0) << " "
    << ((frac1 != frac2) ? 1 : 0) << " "
    << ((frac2 < frac3) ? 1 : 0) << " "
    << ((frac2 <= frac3) ? 1 : 0) << " "
    << ((frac2 > frac3) ? 1 : 0) << " "
    << ((frac2 >= frac3) ? 1 : 0) << " "
    << ((frac2 == frac3) ? 1 : 0) << " "
    << ((frac2 != frac3) ? 1 : 0) << endl;
    
    cout << (frac6 = frac3) << " ";
    cout << (frac6 += frac3) << " ";
    cout << (frac6 -= frac3) << " ";
    
    cout << (frac6 *= frac3) << " ";
    cout << (frac6 /= frac3) << endl;
    cout << (-frac6) << endl;
    
    
    
    frac6 = (++frac4) +2;
    frac7 = 2 + frac4++;
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    
    frac6 = (--frac4) - 2;
    frac7 = 2 - (frac4--);
    
    cout << frac4 << " " << frac6 << " " << frac7 << endl;
    
    
    
    cout << 2 * frac3 << " " << frac3 * 2 << " " << 2 / frac3 << " " << frac3 / 2 << endl;
}

#define MAX_SIZE 100

void testDataFromFile()
{
    ifstream inStream;
    int numCases;
    
    inStream.open("input.txt");
    if (inStream.fail()){ cerr << "opening failed"; }
    inStream >> numCases;
    
    for (int i = 0; i < numCases; i++)
    {
        int j;
        int numData;
        MyRational rationals[MAX_SIZE];
        
        inStream >> numData;
        
        for (j = 0; j < numData; j++)
            inStream >> rationals[j];
        
        sortDates(rationals, numData);
        
        for (j = 0; j < numData; j++)
            cout << rationals[j] << " ";
        cout << endl;
    }
    inStream.close();
}

void sortDates(MyRational rationals[], int n)
{
    for (int i = n - 2; i >= 0; i--)
        for (int j = 0; j <= i; j++)
            if (rationals[j] > rationals[j + 1]){
                MyRational tmp;
                tmp = rationals[j];
                rationals[j] = rationals[j + 1];
                rationals[j + 1] = tmp;
            }
}








