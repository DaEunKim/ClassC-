//
//  main.cpp
//  입체사목게임
//
//  Created by 김다은 on 2017. 5. 13..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/입체사목게임/입체사목게임/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int n;
    for(int z = 0; z < T; z++){
        int arr[42]={0,};
        int even[42]={0,};
        int odd[42]={0,};

        inStream >> n;
        char evenchar = 'e';
        char oddchar ='o';
        
        for(int i = 0;i<n;i++){
            inStream >> arr[i];
        }
        int idx_even = 1;
        int idx_odd = 1;
        
        int total[6][7]={0,};
        
        for(int i = 0;i<n;i++){
            if(i%2==0){
                even[idx_even++] = arr[i];
            }
            else{
                odd[idx_odd++] = arr[i];
            }
        }
        
        for(int i = 1;i<=idx_even;i++){
            cout<<even[i]<<" ";
        }
        cout<<endl;
        for(int i = 1;i<=idx_odd;i++){
            cout<<odd[i]<<" ";
        }
        cout<<endl;
        cout<<endl;
        int x=7, y=6;
        int tmp = 0;
        
        for(int i = 1;i<=idx_even;i++){
            tmp++;
            if(even[i]==tmp){
                total[i][x] = even[i];
                
            }
            else{
                x--;
                
            }
            
            
        }
        x=7;
    
        for(int i = 1;i<=idx_odd;i++){
            tmp++;
            if(odd[i]==tmp){
                total[i][x] = odd[i];
            }
            else
                x--;
            
        }
        
        for(int i = 1;i<=6;i++){
            for(int j = 1;j<=7;j++){
                cout<<total[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
    }
    
    inStream.close();
}

