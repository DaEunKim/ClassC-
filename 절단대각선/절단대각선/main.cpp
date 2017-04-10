//
//  main.cpp
//  절단대각선
//
//  Created by 김다은 on 2017. 4. 6..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/절단대각선/절단대각선/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int size;
        inStream >> size;

        int arr1[101][101]={0, };
        vector<int> v;
        
        for(int i = 0;i<size;i++){
            for(int j = 0;j<size;j++){
                inStream >>arr1[i][j];
            }
        }
        
        if (size == 1){
            cout << arr1[0][0] << endl;
            continue;
        }
            
        
        
        //정방향
        for(int i = 1;i<size;i++){
            int sum = 0;
            for(int j = 0;j<size-i;j++)
                sum += arr1[i+j][j];
                
            for(int j = 0;j<i;j++)
                sum += arr1[j][size-i+j];
            v.push_back(sum);
        }
    
        //역방향
        for(int i = 1;i<size;i++){
            int sum = 0;
            for(int j = 0;j<size-i;j++)
                sum += arr1[size-i-1-j][j];

            for(int j = 0;j<i;j++)
                sum += arr1[size-1-j][size-i+j];

            v.push_back(sum);
        }
        
        int sum = 0;
        for(int i = 0;i<size;i++)
            sum += arr1[i][i];
        v.push_back(sum);
        
        
        sum = 0;
        for(int i = 0;i<size;i++)
            sum += arr1[i][size-1-i];
        v.push_back(sum);
        
        sort(v.begin(), v.end());
        
        cout<< v.back() <<endl;
        
    }
    
    inStream.close();
}
