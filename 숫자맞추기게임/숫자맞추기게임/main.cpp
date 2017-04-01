//
//  main.cpp
//  숫자맞추기게임
//
//  Created by 김다은 on 2017. 3. 22..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;


int strike_num(int a[], int b[]){
    int count = 0;

    for(int i=0; i<4; ++i)
        if(a[i] == b[i])
            count++;
    
    return count;
    
}

int ball_num(int a[], int b[]){
    int count = 0;

    
    for(int i=0; i<4; ++i)
    {
        if(a[i] == b[i])
            break;
        
        for(int j=0; j<4; ++j)
        {
            if(i == j)
                continue;
            if(a[i] == b[j])
            {
                ++count;
                break;
            }
        }
    }
    
    return count;
}


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/숫자맞추기게임/숫자맞추기게임/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int num;
    int answer[21]={0, };
    int strike[21] = {0, };
    int ball[21] = {0, };
    
    for(int z = 0;z < T; z++){
        inStream >>num;
        
        int arr[10001]={0, };
        int answer_tmp[5] = {0, };
    
        
        
        for(int i = 0;i<num;i++){
            inStream >> answer[i] >> strike[i] >>ball[i];
        }
        for(int i=0; i<10000; ++i){
            arr[3] = i%10;
            arr[2] = i%100/10;
            arr[1] = i%1000/100;
            arr[0] = i%10000/1000;
        }
        for(int i = 0;i<10;i++){
            
            
            for(int r = 0;r<num;r++){
                
                //cout<<"strike_num : "<<strike_num(answer[r],arr_tmp)<<endl;
                if(strike[r]==strike_num(answer,arr) || ball[r]==ball_num(answer,arr)){
                    answer_tmp[r] = strike_num(answer, arr);
                    
                }
                else if(strike[r]==strike_num(&answer[r],arr) && ball[r]!=ball_num(&answer[r],arr)){
                    cout<<"-1"<<endl;
                    break;
                }
                else{
                    cout<<"-2"<<endl;
                    break;
                }

                
            }
            for(int r = 0;r<num;r++){
                cout<<"a : "<<answer_tmp[r]<<endl;

            }
            
            
        }
        
        inStream.close();
    }
}
