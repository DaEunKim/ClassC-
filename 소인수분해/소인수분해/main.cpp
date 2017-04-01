//
//  main.cpp
//  소인수분해
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
    inStream.open("/Users/Dani/Documents/C++class/소인수분해/소인수분해/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    for(int z = 0; z < T; z++){
        int n;
        inStream >>n;
        int i = 1;
        int arr[10000]={0, };
        
        for(int i = 1;i<=n;i++){
            if(n%i==0){
                arr[i] = n/i;
                n = n/i;
            }
            
            
        }
        for(int i = 1;i<=n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        
    
    }
    
    
    inStream.close();
}
