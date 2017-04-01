//
//  main.cpp
//  삼각형종류2
//
//  Created by 김다은 on 2017. 3. 15..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;

void swap(double *a, double *b){
    double tmp = *a;
    *a = *b;
    *b = tmp;
}

double scope(int ax, int ay, int bx, int by)
{
    if(ax == bx)
        return -1;
    else
        return double(ay-by)/double(ax-bx);
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/삼각형종류2/삼각형종류2/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int ax, ay, bx, by, cx, cy;
    double a, b, c;
    
    for(int z = 0;z < T; z++){
        inStream >> ax >> ay >> bx >> by >> cx >> cy;
        a = (ax-bx)*(ax-bx)+(ay-by)*(ay-by);
        b = (ax-cx)*(ax-cx)+(ay-cy)*(ay-cy);
        c = (bx-cx)*(bx-cx)+(by-cy)*(by-cy);
        
        if(a > b) swap(&a, &b);
        if(b > c) swap(&b, &c);

        if(scope(ax, ay, bx, by) == scope(bx, by, cx, cy)  or sqrt(a)+sqrt(b)<=sqrt(c))
            cout << "0" <<endl;
        else if(a+b == c)
            cout << "1" << endl;
        else if(a+b < c)
            cout << "2" << endl;
        else if(a+b > c)
            cout << "3" << endl;
    }
    
    inStream.close();
}
