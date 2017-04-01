//
//  main.cpp
//  끝자리숫자계산
//
//  Created by 김다은 on 2017. 3. 7..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/끝자리숫자계산/끝자리숫자계산/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int i = 0;i < T; i++){
        
        int n;
        inStream >> n;
        int mul = 1;
        int p = 1;
        int tmp = 0;
        
        
        for(int j = 0;j<n;j++){
            int a;
            inStream >> a;
            tmp = a%10;
            mul = p*tmp;
            p = mul%10;
            
            
        }
        cout << p <<endl;
        
    }
    
    inStream.close();
}
