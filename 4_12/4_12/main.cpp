//
//  main.cpp
//  4_12
//
//  Created by 김다은 on 2017. 4. 12..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
using namespace std;


int calculateCircle(int r);
int calculateRectangle(int w, int h);
int calculateTriangle(int w, int h);

int main(void){
    int r;
    cout<< "반지름을 쓰시오 : ";
    cin>>r;
    
    cout << calculateCircle(r)<<endl;
    int w, h;
    cout<<"사각형 및 삼각형의 넓이와 높이를 쓰시오 :";
    cin >> w >> h;
    cout<< calculateRectangle(w, h)<<endl;
    cout<< calculateTriangle(w, h)<<endl;
    
    
    return 0;
    
}

int calculateCircle(int r){
    return r*r*3.14;
    
}
int calculateRectangle(int w, int h){
    return w*h;
}
int calculateTriangle(int w, int h){
    return (w*h)/2;
    
}



//class Avg{
//public:
//    int sum;
//    int average;
//    int computeAvg(int *grade, int students){
//        cout<< sizeof(grade)<<endl;
//
//        for(int i = 0;i<students;i++){
//            sum += grade[i];
//        }
//
//        average = sum/students;
//        return average;
//    }
//
//};
