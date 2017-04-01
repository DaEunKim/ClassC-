//
//  main.cpp
//  해밍수
//
//  Created by 김다은 on 2017. 3. 27..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/해밍수/해밍수/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    set<int> s;
    
    int arr[8000]={1, };
    
    for(int i = 0;i<1351;i++){
        s.insert(arr[i]*2);
        s.insert(arr[i]*3);
        s.insert(arr[i]*5);
        arr[i+1] = *(s.begin());
        s.erase(s.begin());
        
    }
    
    for(int z = 0;z < T; z++){
        int k;
        inStream >> k;
        cout<< arr[k-1] <<endl;
        
      }
    
    inStream.close();
}
