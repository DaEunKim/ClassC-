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
#include <vector>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/0이아닌마지막수/0이아닌마지막수/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int t;
        inStream >> t;
        int n[101]={0, };
        vector<int> v;
        
        vector<int> two;
        vector<int> five;
        int mul = 1;
        int count = 0;
        int cnt2 = 0;
        int cnt5 = 0;
        
        for(int i = 0;i<t;i++){
            inStream >> n[i];
            v.push_back(n[i]);
        }

        for(int i = 0;i<v.size();i++){
            
            while (v[i]%2==0) {
                ++cnt2;
                v[i] /= 2;
            }
        }
        
        for(int i = 0;i<v.size();i++){
            
            while (v[i]%5==0) {
                ++cnt5;
                v[i] /= 5;
                
            }
        }
        if(cnt2<cnt5){
            count = cnt2;
        }
        else{
            count = cnt5;
        }
        
        
        for(int i = 0;i<v.size();i++){
            
            mul *= v[i]%10;
            mul = mul%10;
        }
        
        
        if(cnt2>cnt5){
            for(int i = 1;i<=(cnt2-count);i++){
                mul *= 2;
                mul %= 10;
            }
        }
        else{
            for(int i = 1;i<=(cnt5-count);i++){
                mul *= 5;
                mul %= 10;
            }
            
        }
        cout<<mul<<" "<<count<<endl;

    }
    
    inStream.close();
}
