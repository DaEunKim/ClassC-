//
//  main.cpp
//  시험점수분포
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
    inStream.open("/Users/Dani/Documents/C++class/시험점수분포/시험점수분포/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int num;
    for(int z = 0;z < T; z++){
        inStream >>num;
        set<int> s;
        
        int score[101]={0, };
        int count[101]={0, };
        
        for(int i = 0;i<num;i++){
            inStream >> score[i];
            
        }
        for(int i = 0;i<num;i++){
            for(int j = 0;j<num;j++){
                if(score[i] ==score[j])
                    count[i]++;

            }
        }
        for(int i = 0;i<num;i++){
            s.insert(score[i]);
        }
        
        for(set<int>::iterator i = s.begin();i != s.end();i++){
            cout<<*i<<" ";
            
            for(int j = 0;j<num;j++){
                if(*i == score[j]){
                    cout<<count[j]<<" ";
                    break;
                }
            }
        }
        cout<<endl;
    }
    
    inStream.close();
}
