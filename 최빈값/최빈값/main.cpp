//
//  main.cpp
//  최빈값
//
//  Created by 김다은 on 2017. 3. 22..
//  Copyright © 2017년 김다은. All rights reserved.
//
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/최빈값/최빈값/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int n;
    int arr[101]={0, };
    
    
    for(int z = 0; z < T; z++){
        inStream >> n;
        set<int> s;
        
        int count[101] = {0, };
        int max = 0;
        int cnt = 0;
        for(int i = 0;i<n;i++){
            inStream >> arr[i];
            
        }
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(arr[i]==arr[j])
                    count[i]++;
            }
        }
        
        
        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                if(max<count[i])
                    max = count[i];
            }
        }
        
        for(int i = 0;i<n;i++){
            if(count[i] ==max)
                cnt++;
        }
        
        for(int i = 0;i<n;i++){
            if(max==count[i])
                s.insert(arr[i]);

        }
        
        cout <<cnt/max<< " " << max;
        
        for(set<int>::iterator i = s.begin(); i != s.end(); i++)
            cout<< " "<<*i;
        cout << endl;
        
    }
    
    inStream.close();
}
