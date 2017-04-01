//
//  main.cpp
//  수직수평의교차
//
//  Created by 김다은 on 2017. 3. 20..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

void swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Document/C++class/수직수평의교차/수직수평의교차/input.txt");
    
    int T;
    inStream >> T;
    
    int x1, y1, x2, y2;
    int xx1, yy1, xx2, yy2;
    
    for(int i = 0;i < T; i++){
        inStream >> x1 >> y1 >> x2 >> y2;
        inStream >> xx1 >> yy1 >> xx2 >> yy2;
        
        //x1 x2 y1 y2 수직
        if(x1==x2){
            if(xx1 > xx2)
                swap(&xx1, &xx2);
            if(y1 > y2)
                swap(&y1, &y2);
            
            if(xx1<x1 && x1<xx2 && y1<yy1 && yy1<y2)
                cout<<"1"<<endl;
            else if(x1<xx1 || xx2<x1 || yy1<y1 || y2<yy1)
                cout<<"0"<<endl;
            else
                cout<<"2"<<endl;
        }
        
        //xx1이 수직일때
        if(y1==y2){
            if(x1 > x2) swap(&x1, &y1);
            if(yy1 > yy2) swap(&yy1, &yy2);
            
            if(x1<xx1 && xx1<x2 && yy1<y1 && y1<yy2)
                cout<<"1"<<endl;
            else if(xx1<x1 || x2<xx1 || y1<yy1 || yy2<y1)
                cout<<"0"<<endl;
            else
                cout<<"2"<<endl;
        }
    }
    inStream.close();
}
