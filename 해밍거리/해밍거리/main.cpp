//
//  main.cpp
//  해밍거리
//
//  Created by 김다은 on 2017. 5. 5..
//  Copyright © 2017년 김다은. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;


void weight(int num){
    int twozin[32] = {0,};
    int i = 0;

    while(num >=2){
        twozin[i] = num%2;
        num = num/2;
        i++;
    }
    twozin[i++] = num%2;

    int w = 0;

    for(int j = i;j>=0;j--){
        if(twozin[j]==1)
            w++;
    }
    cout<<w<<" ";
    
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/해밍거리/해밍거리/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int m, n;
    for(int z = 0; z < T; z++){
        inStream >>m>>n;
        weight(m);
        weight(n);
        int twozin_m[32] = {0, };
        int twozin_n[32] = {0, };
        int i_m = 0;
        int i_n = 0;
        while(m >=2){
            twozin_m[i_m] = m%2;
            m = m/2;
            i_m++;
        }
        twozin_m[i_m++] = m%2;
        
        while(n >=2){
            twozin_n[i_n] = n%2;
            n = n/2;
            i_n++;
        }
        twozin_n[i_n++] = n%2;
        
        int i = 0;
        if(i_n>i_m)
            i = i_n;
        else
            i = i_m;
        int cnt = 0;
        for(int j = i;j>=0;j--){
            if(twozin_m[j]!=twozin_n[j])
                cnt++;
        }
        cout<<cnt;
        cout<<endl;
        
        
    }
    
    inStream.close();
}
