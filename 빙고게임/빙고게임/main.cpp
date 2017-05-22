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

int board[5][5];
bool done[5][5];
int X, Y;

bool checkCross(){
    bool flag = 1;
    for(int i=0; i<5; ++i)
        if(!done[i][i])
            flag = 0;
    
    if(flag)
        return 1;
    
    flag = 1;
    for(int i=0; i<5; ++i)
        if(!done[i][4-i])
            flag = 0;
    
    if(flag)
        return 1;
    
    return 0;
}

bool checkPlus(int x, int y){
    bool flag = 1;
    for(int i=0; i<5; ++i)
        if(!done[i][x])
            flag = 0;
    
    if(flag)
        return 1;
    
    flag = 1;
    for(int i=0; i<5; ++i)
        if(!done[y][i])
            flag = 0;
    
    if(flag)
        return 1;
    
    return 0;
}

bool checkPoint(){
    if(done[0][0] && done[0][4] && done[4][0] && done[4][4])
        return 1;
    return 0;
}

bool isDone(int x, int y){
    done[y][x] = 1;
    
    if(checkCross() || checkPlus(x, y) || checkPoint())
        return 1;
    return 0;
}

int searchPoint(int num){
    for(int i=0; i<5; ++i)
        for(int j=0; j<5; ++j)
            if(board[i][j] == num){
                X = j, Y = i;
                return 1;
            }
    return 0;
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/빙고게임/빙고게임/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    while(T--){
        for(int i=0; i<5; ++i)
            for(int j=0; j<5; ++j)
                inStream >> board[i][j], done[i][j] = 0;
        
        done[2][2] = 1;
        
        int callNum[75];
        for(int i=0; i<75; ++i)
            inStream >> callNum[i];
        
        int count = 1;
        for(int i=0; i<75; ++i){
            if(searchPoint(callNum[i])){
                if(isDone(X, Y)){
                    cout << count << "\n";
                    break;
                }
            }
            
            count++;
        }
    }
}

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
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
     */
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
        
    
/*
    inStream.close();
}
*/
