//
//  main.cpp
//  주어진정수합
//
//  Created by 김다은 on 2017. 3. 6..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <algorithm>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/주어진정수합/주어진정수합/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int i = 0;i < T; i++){
        int n;
        inStream >> n;
        int sum;
        int tmp =0;
        for(int j = 0; j < n; j++){
            inStream >> sum;
            tmp += sum;
        }
        cout << tmp <<endl;
    }
    
    inStream.close();
}
