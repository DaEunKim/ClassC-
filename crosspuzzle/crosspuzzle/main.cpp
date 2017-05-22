//
//  main.cpp
//  crosspuzzle
//
//  Created by 김다은 on 2017. 5. 16..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

const int max_size = 201;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/crosspuzzle/crosspuzzle/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        char board[max_size][max_size] = { 0, };
        char word[max_size][max_size] = { NULL };
        int row, col, w_num;
        
        inStream >> row >> col;
        for (int j = 0; j < row; j++)
            inStream >> board[j];
        
        inStream >> w_num;
        for (int j = 0; j < w_num; j++)
            inStream >> word[j];
        
        
        for (int j = 0; j < w_num; j++)
        {
            int k = 0, wcnt = 0;
            while (word[j][k] != 0)
                wcnt++;
            
            int ans;
            for (int a = 0; a < row; a++){
                for (int b = 0; b < col; b++){
                    if (word[j][0] == board[a][b]){
                        int cnt = 1;
                        for (int c = 1; c < wcnt; c++){
                            if ((a <= a - wcnt)&&word[j][c] == board[a + c][b]) cnt++;
                            if (cnt == wcnt) ans = 4;
                        }
                        
                        cnt = 1;
                        for (int c = 1; c < wcnt; c++){
                            if ((a <= wcnt) && word[j][c] == board[a][b + c]) cnt++;
                            if (cnt == wcnt) ans = 2;
                        }
                        
                    }
                }
            } 
        }
        
        cout << board[0] << endl;
        
    }
    
    inStream.close();
    return 0;
}
            
