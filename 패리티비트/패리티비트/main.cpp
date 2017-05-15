//
//  main.cpp
//  패리티비트
//
//  Created by 김다은 on 2017. 3. 22..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/classCpp/패리티비트/패리티비트/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    unsigned long long n;
    
    for(int z = 0; z < T; z++){
        inStream >> n;
        
        int count=0;
        unsigned long long original = n;
        
        for(int i = 0;i<32;i++){
            if(n!=0){
                if(n%2==1)
                    count++;
                n = n/2;
            }
        }
        
        if(count%2 == 1)
            original += 2147483648;
        
        cout<<original<<endl;
    }
    
    inStream.close();
}
