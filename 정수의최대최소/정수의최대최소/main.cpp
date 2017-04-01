//
//  main.cpp
//  정수의최대최소
//
//  Created by 김다은 on 2017. 3. 7..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/정수의최대최소/정수의최대최소/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int i = 0;i < T; i++){
        
        int n;
        inStream >> n;
        int value;
        int max =-999;
        int min = 20135179;
        
        for(int j = 0; j < n; j++){
            inStream >> value;
            
            if(max < value)
                max = value;
            if(min > value)
                min = value;
            
            
            
        }
        cout << max<<" "<< min <<endl;
    }
    
    inStream.close();
}
