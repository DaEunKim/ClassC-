//
//  main.cpp
//  정수연산
//
//  Created by 김다은 on 2017. 3. 6..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/정수연산/정수연산/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int i = 0;i < T; i++){
    
        int a; int b;
        
        inStream >> a >> b;
       

        int plus = a+b;
        int minus = a-b;
        int abss = abs(minus);
        int mul = a*b;
        int div = a/b;
        int rest = a%b;
        int big = (a>b) ? a : b;
        int num = (a==b) ? 1 :0;
        
        cout << plus << " " << minus << " " << abss << " " << mul << " " << div<< " " << rest << " " << big << " " <<num << endl;
    }
    
    inStream.close();
}
