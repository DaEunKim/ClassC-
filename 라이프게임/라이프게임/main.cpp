//
//  main.cpp
//  라이프게임
//
//  Created by 김다은 on 2017. 5. 13..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;



int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/라이프게임/라이프게임/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int m, n;
        inStream >> m >> n;
        int g;
        inStream >> g;
        
        char arr[101][101]={0,};
        char save[101][101]={0,};
        
        int count;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                inStream >> arr[i][j];
            }
        }
        
        
        for(int k = 0;k<g;k++){
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){

                    count=0;
                    if(arr[i-1][j-1]=='O') count ++;
                    if(arr[i-1][j]=='O') count++;
                    if(arr[i-1][j+1]=='O') count++;
                    if(arr[i][j+1]=='O') count++;
                    if(arr[i+1][j+1]=='O') count++;
                    if(arr[i+1][j]=='O') count++;
                    if(arr[i+1][j-1]=='O') count++;
                    if(arr[i][j-1]=='O') count++;
                    
                    if(arr[i][j]=='O' && count<=1){
                        save[i][j]='X';
                    }
                    else if(arr[i][j]=='O' && count>=4){
                        save[i][j] = 'X';
                    }
                    else if(arr[i][j]=='O' && (count==2 || count==3)){
                        save[i][j]='O';
                    }
                    
                    else if(arr[i][j]=='X' && count==3){
                        save[i][j]='O';
                    }
                    else
                        save[i][j]='X';
                    
                }
            }
            
        
    
            for(int i = 0;i<m;i++){
                for(int j = 0;j<n;j++){
                    arr[i][j] = save[i][j];
                }
            }
        }
        
        int live = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                if(arr[i][j]=='O'){
                    live++;
                }
            }
        }
        cout<<live<<endl;
        
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                cout<<arr[i][j];
            }
            cout<<endl;
        }
        
        
        
        
    }
    inStream.close();
}
