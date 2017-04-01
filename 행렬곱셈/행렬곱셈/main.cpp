//
//  main.cpp
//  행렬곱셈
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
    inStream.open("/Users/Dani/Documents/C++class/행렬곱셈/행렬곱셈/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int m_1, n, m_2;
        inStream >> m_1 >>n >> m_2;
        int arr1[101][101]={0, };
        int arr2[101][101]={0, };
        int mul[101][101] ={0, };
        for(int i = 0;i<m_1;i++){
            for(int j = 0;j<n;j++){
                inStream >>arr1[i][j];
                
            }
        }
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m_2;j++){
                inStream >>arr2[i][j];
                
            }
        }
        
        for(int i = 0;i<m_1;i++){
            for(int j = 0;j<n;j++){
                for(int k = 0;k<m_2;k++){
                    
                    mul[i][k] += arr1[i][j]*arr2[j][k];
                }
                
            }
            
        }
        
        
        
        for(int i = 0;i<m_1;i++){
            for(int j = 0;j<m_2;j++){
                cout<< mul[i][j]<<" ";
                
            }
            cout<<endl;
        }
    }
    
    inStream.close();
}
