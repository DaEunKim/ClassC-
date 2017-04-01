//
//  main.cpp
//  다각형면적
//
//  Created by 김다은 on 2017. 3. 20..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/다각형면적/다각형면적/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int t;
    int ax, ay;
    int x_arr[201]={0, };
    int y_arr[201]={0, };
    for(int z = 0;z < T; z++){
        inStream >>t;
        int sum = 0;
        int Area = 0;//2배한 면적
        
        for(int i = 0;i<t;i++){
            inStream >> ax >> ay;
            x_arr[i] = ax;
            y_arr[i] = ay;
            
            
            
        }
        for(int i = 0; i<t; i++){
            x_arr[t] = x_arr[0];
            y_arr[t] = y_arr[0];
            Area = (x_arr[i]+x_arr[i+1])*(y_arr[i+1]-y_arr[i]);
            sum +=Area;
            
        }
        
        if(sum<0)
            cout<< abs(sum) <<" "<<"-1"<<endl;
        else if(sum>0)
            cout<< abs(sum) <<" "<<"1"<<endl;
        else
            cout<< abs(sum) <<" "<<"0"<<endl;
        
    }
    
    inStream.close();
}
