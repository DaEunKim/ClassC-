//
//  main.cpp
//  빙고게임
//
//  Created by 김다은 on 2017. 5. 16..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/빙고게임/빙고게임/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int arr[5][5]={0,};
        int save[5][5] = {0,};
        
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                inStream >> arr[i][j];
            }
        }
        int num[75]={0,};
        for(int i = 0;i<75;i++){
            inStream >>num[i];
        }
        
        bool flag = false;
        
        
        int x;
        int y;
        int cnt = 0;
        
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                for(int k = 0;k<75;k++){
                    if(arr[i][j]==num[k]){
                        flag = true;
                        save[i][j] = flag;
                        x = i;
                        y = j;
                        
                    }
                }
            }
        }
        
        for(int i = 0;i<5;i++){
            if(save[x][y]==true){
                if(save[i][y]==true){
                    
                }
            }
            
            
        }
        for(
/*
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                if(arr[i][j]==76){
                    
 
                }
            }
        }
        
        for(int i = 0;i<5;i++){
            for(int j = 0;j<5;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
  */
        
        
        
        
    }
    
    inStream.close();
}

