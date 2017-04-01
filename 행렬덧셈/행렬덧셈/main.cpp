//
//  main.cpp
//  행렬덧셈
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
    inStream.open("/Users/Dani/Documents/C++class/행렬덧셈/행렬덧셈/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int m, n;
        inStream >> m >>n;
        int arr1[101][101]={0, };
        int arr2[101][101]={0, };
        int sum[101][101] ={0, };
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                inStream >>arr1[i][j];
                
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                inStream >>arr2[i][j];
                
            }
        }
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                sum[i][j] = arr1[i][j]+arr2[i][j];
            }
        }
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<< sum[i][j]<<" ";
                
            }
            cout<<endl;
        }
    }
    
    inStream.close();
}
