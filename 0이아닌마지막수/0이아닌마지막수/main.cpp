//
//  main.cpp
//  0이아닌마지막수
//
//  Created by 김다은 on 2017. 3. 31..
//  Copyright © 2017년 김다은. All rights reserved.
//


#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/0이아닌마지막수/0이아닌마지막수/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int t;
        inStream>>t;
        long long n[101]={0, };
        long long mul = 1;
        int cnt = 0;
        for(int i = 0;i<t;i++){
            inStream >>n[i];
        }
        for(int i = 0;i<t;i++){
            mul *= n[i];
        }
        //cout<<mul<<endl;
        for(int i = 0;i<t;i++){
            if(mul%10==0){
                mul = mul/10;
                cnt++;
            }
        }
        cout<<mul%10<<" "<<cnt<<endl;
    }
    
    inStream.close();
}
