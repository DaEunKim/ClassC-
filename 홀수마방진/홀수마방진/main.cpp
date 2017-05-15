//
//  main.cpp
//  홀수마방진
//
//  Created by 김다은 on 2017. 5. 13..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/홀수마방진/홀수마방진/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int n;
        inStream >> n;
        int arr[50][50]={0,};
        
        int x=0;
        int y = n/2;
        for(int i = 1;i <= n*n;i++){
            arr[x][y] = i;
            if(i%n==0){
                x +=1;
            }
            else{
                x=x-1;
                y=y+1;
            }
            if(x<0){
                x=n-1;
            }
            if(y>n-1){
                y=0;
            }
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
    }
    
    inStream.close();
}

