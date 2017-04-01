//
//  main.cpp
//  약수의합구하기
//
//  Created by 김다은 on 2017. 3. 15..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/약수의합구하기/약수의합구하기/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int n;
    
    for(int z = 0;z < T; z++){
        inStream >> n;
        
        int count = 0;
        int sum = 0;
        for(int i = 2;i<=n;i++){
            
            if(n%i==0){
                sum +=n/i;
                count++;
            }
        
        }
        cout<<count<<" "<<sum<<endl;
        
        
    }
    
    inStream.close();
}
