//
//  main.cpp
//  신용카드번호
//
//  Created by 김다은 on 2017. 5. 7..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/신용카드번호/신용카드번호/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        string n;
        inStream >>n;
        
        char cc[21]={0,};
        int c[21]={0,};
        unsigned long size = n.size();
        
        for(int i = 0;i<size;i++){
            cc[i] = n.at(i);
        }
        for(int i = 0;i<size;i++){
            c[i] = cc[i]-'0';
            
            
        }
        
        bool flag = true;
        
        if(c[0]==3){
            if(!(size==15 || size==14))
                flag = false;
        }
        else if(c[0]==4){
            if(!(size==13 || size ==16))
                flag = false;
            //13 16
            
        }
        else if(c[0]==5 || c[0]==6){
            if(size!=16)
                flag = false;
        }
        else
            flag = false;
        
        int sum = 0;
        
        for(long i = 0;i<size-1;i++){
            if(i%2 == 0){
                c[size-2-i] = c[size-2-i]*2;
            }
        }
        
        for(int i = 0;i<size-1;i++){
            if(c[i]>=10)
                c[i] = c[i]-9;
        }

        
        for(int i = 0;i<size-1;i++){
            sum +=c[i];
        }
        
        int save = sum;
        
        while(save%10!=0)
            save++;
        
        int check = save - sum;
        
        if(c[size-1] != check)
            flag = false;
        
        if(flag == false)
            cout<<"0"<<endl;
        else
            cout<<"1"<<endl;
    }
    inStream.close();
}
