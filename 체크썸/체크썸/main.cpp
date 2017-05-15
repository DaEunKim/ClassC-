//
//  main.cpp
//  체크썸
//
//  Created by 김다은 on 2017. 4. 11..
//  Copyright © 2017년 김다은. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/체크썸/체크썸/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    unsigned int n;
    
    for(int z = 0; z < T; z++){
        inStream >> n;
        int checksum;
        int data1;
        int data2;
        int data3;
        int sum = 0;
        
        int check = 0;
        checksum = 0XFF & n;
        data1 = 0xFF & (n >> 24);
        data2 = 0xFF & (n >> 16);
        data3 = 0xFF & (n >> 8);
        
        
        
        sum = data1 + data2 + data3;
        
        while(sum >= 256){
            sum -= 256;
            check = 255 - sum;
        }
        check = 255 - sum;
        
        
        if(checksum == check)
            cout<< "1" <<endl;
        else
            cout<< "0" <<endl;
        
    }
    inStream.close();
}
