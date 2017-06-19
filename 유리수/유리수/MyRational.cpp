//
//  MyRational.cpp
//  유리수
//
//  Created by 김다은 on 2017. 5. 30..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include "MyRational.h"
#include <cstdlib>

MyRational operator +(int num, const MyRational& r){
    MyRational tmp(r);
    
    tmp._num += num*tmp._den;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}

MyRational operator -(int num, const MyRational& r){
    MyRational tmp(num, 1);
    
    tmp._num *= r._den;
    tmp._den = r._den;
    
    tmp._num -= r._num;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}

MyRational operator *(int num, const MyRational& r){
    MyRational tmp(r);
    
    tmp._num *= num;
    
//    reduceFraction(tmp._num, tmp._den);
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}

MyRational operator /(int num, const MyRational& r){
    MyRational tmp(r._den, r._num);
    
    tmp._num *= num;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}














MyRational::MyRational(long num, long den){
    long tmp = gcd(num, den);
    
    _num = num/tmp;
    _den = den/tmp;
}

MyRational::MyRational(const MyRational &r)
{
    _num = r._num;
    _den = r._den;
}

long MyRational::getDenominator() const {
    return _den;
}
long MyRational::getNumerator() const{
    return _num;
}
MyRational MyRational::reciprocal() const{
    MyRational tmp(_den, _num);
    return tmp;
}


MyRational MyRational::operator +(MyRational& r){
    MyRational tmp(_num, _den);
    tmp._num = (tmp._num*r._den + tmp._den*r._num);
    tmp._den *= r._den;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}

MyRational MyRational::operator -(MyRational& r){
    MyRational tmp(_num, _den);
    tmp._num = (tmp._num*r._den - tmp._den*r._num);
    tmp._den *= r._den;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}

MyRational MyRational::operator *(MyRational& r){
    MyRational tmp(_num, _den);
    tmp._num *= r._num;
    tmp._den *= r._den;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}

MyRational MyRational::operator /(MyRational& r){
    
    MyRational tmp(_den, _num);
    
    
//    MyRational tmp(_num, _den);
//    tmp._num *= r._num ;
//    
//    tmp._den *= r._den;
//
    
    tmp *= *this;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
//    if(tmp._den==0 || tmp._num==0)
//        return 0;
    
    return tmp;
}
//num분자
MyRational MyRational::operator +(int value) {
    MyRational tmp(_num, _den);
    tmp._num = (tmp._num*1 + tmp._den*value);
    tmp._den *= 1;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}


MyRational MyRational::operator -(int value) {
    MyRational tmp(_num, _den);
    tmp._num = (tmp._num*1 - tmp._den*value);
    tmp._den *= 1;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}
MyRational MyRational::operator *(int value) {
    MyRational tmp(_num, _den);
    tmp._num *= value;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    return tmp;
}
MyRational MyRational::operator /(int value) {
    MyRational tmp(_num, _den);
    tmp._den *= value;
    
    long gcd = tmp.gcd(tmp._num, tmp._den);
    
    tmp._den /= gcd;
    tmp._num /= gcd;
    
    if(tmp._den==0 || tmp._num==0)
        return 0;
    
    return tmp;

}
//MyRational& MyRational::operator ++() {
//    MyRational tmp(_num, _den);
//    tmp._num = _den;
//    tmp._den = _den;
//    
//    _num += tmp._num;
//    _den = tmp._den;
//    
//    long gcd = this->gcd(_num, _den);
//    
//    _den /= gcd;
//    _num /= gcd;
//    
//    return tmp;
//
//}

//MyRational& MyRational::operator --(){
//    
//    MyRational tmp(_num, _den);
//    tmp._num = _den;
//    tmp._den = _den;
//    
//    _num -= tmp._num;
//    _den = tmp._den;
//    
//    long gcd = this->gcd(_num, _den);
//    
//    _den /= gcd;
//    _num /= gcd;
//    
//    return tmp;
//
//}

MyRational MyRational::operator ++(int){
    MyRational tmp(_num, _den);
    
    _num += _den;
  
    long gcd = this->gcd(_num, _den);
    
    _num /= gcd;
    _den /= gcd;
    
    return tmp;
}

MyRational MyRational::operator --(int){
    MyRational tmp(_num, _den);
    
    _num -= _den;
    long gcd = this->gcd(_num, _den);
    
    _num /= gcd;
    _den /= gcd;
    
    return tmp;
}

MyRational operator ++(MyRational &r){
    r._num += r._den;
    
    long gcd = r.gcd(r._num, r._den);
    
    r._num /= gcd;
    r._den /= gcd;
    
    return r;
}

MyRational operator --(MyRational &r){
    r._num -= r._den;
    long gcd = r.gcd(r._num, r._den);
    
    r._num /= gcd;
    r._den /= gcd;
    
    return r;
}

MyRational MyRational::operator -() const
{
    MyRational tmp(_num, _den);
    
    tmp._num *= -1;
    
    return tmp;
}

bool MyRational::operator ==(const MyRational& r) const{
    if ((_num != r._num) || (_den != r._den))
        return false;
    
    return true;
}

bool MyRational::operator !=(const MyRational& r) const
{
    return !(*this == r);
}

//
bool MyRational::operator >=(const MyRational& r) const
{
    MyRational tmp(_num, _den);
    MyRational tmp2(_num, _den);
    tmp._num = r._den*_num;
    tmp2._num =_den*r._num;
    
    tmp._den = r._den * _den;
    tmp2._den = r._den * _den;
    
    
    if(tmp._num < tmp2._num )
        return false;
    
    return true;
}

bool MyRational::operator <=(const MyRational& r) const
{
    MyRational tmp(_num, _den);
    MyRational tmp2(_num, _den);
    tmp._num = r._den*_num;
    tmp2._num =_den*r._num;
    
    tmp._den = r._den * _den;
    tmp2._den = r._den * _den;
    
    
    if(tmp._num > tmp2._num )
        return false;
    
    return true;
}


bool MyRational::operator >(const MyRational& r) const
{
//    MyRational tmp(_num, _den);
//    MyRational tmp2(_num, _den);
//    tmp._num = r._den*_num;
//    tmp2._num =_den*r._num;
//    
//    tmp._den = r._den * _den;
//    tmp2._den = r._den * _den;
//    
//    
//    if(tmp._num <= tmp2._num )
//        return false;
//    
//    return true;
//
//
    
    return ((double)_num/_den) > ((double)r._num/r._den);
}

bool MyRational::operator <(const MyRational& r) const
{
//    MyRational tmp(_num, _den);
//    MyRational tmp2(_num, _den);
//    
//    tmp._num = tmp._num*r._den;
//    tmp2._num = tmp._den*r._num;
//    tmp._den *= r._den;
//    
//    
//    if(tmp._num >= tmp2._num)
//        return false;
//    
//    return true;
    
    return ((double)_num/_den) < ((double)r._num/r._den);
}

MyRational &MyRational::operator +=(MyRational& r){
    _num = (_num*r._den + _den*r._num);
    _den *= r._den;
    
    long gcd = this->gcd(_num, _den);
    
    _den /= gcd;
    _num /= gcd;
    
    return *this;
}



MyRational &MyRational::operator -=(MyRational& r) {
    _num = (_num*r._den - _den*r._num);
    _den *= r._den;
    
    return *this;
}

MyRational &MyRational::operator *=(MyRational& r) {
    _num *= r._num;
    _den *= r._den;
    
    long gcd = this->gcd(_num, _den);
    
    _den /= gcd;
    _num /= gcd;
    
    return *this;
}

MyRational &MyRational::operator /=(MyRational& r) {
    MyRational tmp(r._den, r._num);
    
    _num *= r._den;
    _den *= r._num;
    
    long gcd = this->gcd(_num, _den);
    
    _den /= gcd;
    _num /= gcd;
    
    
//    if(_den==0 || _num==0)
//        return 0;
    
    return *this;
    
}


MyRational &MyRational::operator =(const MyRational& r){
    if(&r == this)
        return *this;
    
    _num = r._num;
    _den = r._den;
    
    long gcd = this->gcd(_num, _den);
    
    _den /= gcd;
    _num /= gcd;
    
    return *this;
    
}

MyRational &MyRational::operator =(int v){
    
    if(v== _num || _den==1)
        return *this;
    _num = v ;
    _den = 1;
    
    long gcd = this->gcd(_num, _den);

    _den /= gcd;
    _num /= gcd;

    return *this;
}






ostream &operator <<(ostream &outStream, const MyRational& r)
{
    if (r._num == 0)
        outStream << 0;
    else if (r._den == 1)
        outStream << r._num;
    else
        outStream << r._num << "/" << r._den ;
    return outStream;
}

istream &operator >>(istream &inStream, MyRational& r)
{
    inStream >> r._num >> r._den;
    if (r._den == 0)
    {
        r._num = 0;
        r._den = 1;
    }
    r.reduce();
    return inStream;
}




long MyRational::gcd(long m, long n)
{
    if(m == 0 || n == 0)
        return 1;
    
    m = abs(m);
    n = abs(n);

    if (m == n)
        return n;
    else if (m < n)
        return gcd(m, n-m);
    else
        return gcd(m-n, n);
}


//int* reduceFraction(int bunja, int bunmo) {
//    static int frac[2];
//    frac[0] = bunja;
//    frac[1] = bunmo;
//    
//    if (frac[1] == 0) { // 분모가 0일 경우에 에러 반환
//        frac[0] = NULL;
//        frac[1] = NULL;
//        
//        return frac;
//    }
//    
//    // 함수와 변수명을 모두 gcd 로 하면 "error C2064: term does not evaluate to a function taking 2 arguments" 이러 에러 발생함
//    int gcd_result = gcd(frac[0], frac[1]);
//    
//    frac[0] = frac[0] / gcd_result;
//    frac[1] = frac[1] / gcd_result;
//    
//    return frac;
//}


void MyRational::reduce()
{
    if (_num == 0 || _den == 0)
    {
        _num = 0;
        _den = 1;
        return;
    }
    if (_den < 0)
    {
        _den *= -1;
        _num *= -1;
    }
    if (_num == 1)
        return;
    
    int sgn = (_num < 0 ? -1 : 1);
    long g = gcd(sgn * _num, _den);
    
    _num /= g;
    _den /= g;
}









