//
//  MyRational.hpp
//  유리수
//
//  Created by 김다은 on 2017. 5. 30..
//  Copyright © 2017년 김다은. All rights reserved.
//

#ifndef MyRational_h
#define MyRational_h

#include <iostream>
using namespace std;
class MyRational
{
    friend ostream &operator <<(ostream &outStream, const MyRational& r);
    friend istream &operator >>(istream &inStream, MyRational& r);
//    
    friend MyRational operator +(int num, const MyRational& r);
    friend MyRational operator -(int num, const MyRational& r);
    friend MyRational operator *(int num, const MyRational& r);
    friend MyRational operator /(int num, const MyRational& r);
    
    friend MyRational operator ++(MyRational &);
    friend MyRational operator --(MyRational &);
    
    
public:
    MyRational(long num=0, long den=1);
    MyRational(const MyRational &r);
    
    long getNumerator() const;
    long getDenominator() const;
    MyRational reciprocal() const;
    
    
    MyRational operator +( MyRational& r);
    MyRational operator -(MyRational& r);
    MyRational operator *(MyRational& r);
    MyRational operator /(MyRational& r);
    
    MyRational operator +(int value) ;
    MyRational operator -(int value) ;
    MyRational operator *(int value) ;
    MyRational operator /(int value) ;
    
    MyRational operator++(int);
    MyRational operator--(int);
    
    
    MyRational operator -() const;    // unary minus
    
    bool operator ==(const MyRational& r) const;
    bool operator !=(const MyRational& r) const;
    bool operator >=(const MyRational& r) const;
    bool operator <=(const MyRational& r) const;
    bool operator >(const MyRational& r) const;
    bool operator <(const MyRational& r) const;
    
    MyRational &operator =(int v);
    
    MyRational &operator =(const MyRational& r);
    MyRational &operator +=(MyRational& r);
    MyRational &operator -=(MyRational& r);
    MyRational &operator *=(MyRational& r);
    MyRational &operator /=(MyRational& r);
    
    
    
private:
    // 분수는 항상 내부적으로 기약분수로 표현하며, 또한 항상 _den>0 이다.
    long _num; // numerator 분자
    long _den; // denominator 분모
    
    long gcd(long m, long n); // 최대공약수
    void reduce();
    int* reduceFraction(int bunja, int bunmo);
};

#endif /* MyRational_hpp */
