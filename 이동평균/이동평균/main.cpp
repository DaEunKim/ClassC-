//
//  main.cpp
//  이동평균
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
    inStream.open("/Users/Dani/Documents/C++class/이동평균/이동평균/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    for(int z = 0; z < T; z++){
        int t;
        inStream >>t;
        int arr[257]={0, };
        int k;
        int sum[257] = {0, };
        int avg[257] = {0, };
        int cnt = 0;
        for(int i = 0;i<t;i++){
            inStream >> arr[i];
        }
        inStream >> k;
        
        for(int i = 0;i<t-k+1;i++){
            for(int j = i;j<k+i;j++){
                sum[i] += arr[j];
                
            }
        }
        
        for(int i = 0;i<t-k+1;i++){
            avg[i] = sum[i]/k;
            cnt++;

        }
        cout<<cnt<<" ";
        for(int i = 0;i<t-k+1;i++)
            cout<<avg[i]<<" ";
        cout<<endl;
    }
    
    
    inStream.close();
}
