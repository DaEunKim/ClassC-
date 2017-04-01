//
//  main.cpp
//  삼각형종류1
//
//  Created by 김다은 on 2017. 3. 14..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/삼각형종류1/삼각형종류1/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int a, b, c;
    for(int i = 0;i < T; i++){
        inStream >> a >>b>>c;
        
        if(c>=a+b)
            cout << "0" <<endl;
        else if(a == b and b == c and a==c)
            cout << "1" <<endl;
        else if(a*a+b*b==c*c)
            cout << "2" <<endl;
        else if(a==b or b ==c or c==a)
            cout << "3" <<endl;
        else
            cout << "4" <<endl;
        
    }
    
    inStream.close();
}
