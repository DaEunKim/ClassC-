//
//  main.cpp
//  실수표현
//
//  Created by 김다은 on 2017. 4. 6..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/실수표현/실수표현/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0;z < T; z++){
        double s;
        inStream >> s;
        if(s!=0)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;
        
//
        
    }
    
    inStream.close();
}
