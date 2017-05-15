//
//  main.cpp
//  국제표준도서번호
//
//  Created by 김다은 on 2017. 5. 7..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/국제표준도서번호/국제표준도서번호/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        string s;
        inStream>>s;
        char cc[129]={0,};
        int tmp[129]={0,};

        
        
        for(int i = 0;i<s.size();i++){
            cc[i] = s.at(i);
        }
        
        bool flag = true;
        int cnt = 0;
        
        for(int i = 0;i<s.size()-1;i++){
            if(!(cc[i]=='-' || ('0'<=cc[i] && cc[i]<='9'))){
                flag = false;
            }
        }
        
        if(!(cc[s.size()-1] == 'X' || ('0' <= cc[s.size()-1] && cc[s.size()-1] <= '9')))
            flag = false;
        
        for(int i = 0;i<s.size();i++){
            if(cc[i]=='-')
                cnt++;
        }
        
        if(cnt!=3)
            flag = false;
        
        for(int i = 0;i<s.size()-1;i++){
            if(cc[i]=='-' && cc[i+1]=='-')
                flag = false;
        }
        
        if(cc[0] =='-' || cc[s.size()-1]=='-')
            flag = false;
        
        string TT[10];
        int a = 0;
        for(int i=0; i<s.size(); i++){
            if(cc[i] == '-')
                a++;
            else{
                TT[a] += cc[i];
            }
        }
            
        
//        cout << TT[0] << " " << TT[1] << " " << TT[2] << " " << TT[3];

        if(TT[0].size() > 5 || TT[1].size() > 7 || TT[2].size() > 6 || TT[3].size() > 1)
            flag = false;
        
//        if(TT[0] >=100000 || TT[1] >=10000000 || TT[2] >=1000000 || TT[3] >=10)
//            flag = false;
        int ten = 10;
        int save = 0;
        
        int index = 0;
        for(int i = 0;i<s.size()-1;i++){
            if(cc[i]!='-'){
                tmp[index++] = (cc[i]-'0');
                save += tmp[index-1] * (ten--);
                
                if(index == 9)
                    break;
            }
        }
        
        int copy = save;

        while(copy%11 != 0){
            copy++;
        }
        
        if((copy-save)==10 && cc[s.size()-1]=='X'){
        }
        else if((copy-save) != (cc[s.size()-1]-'0'))
            flag = false;
        
        if(save<0)
            flag = false;
        if(cc[s.size()-1]=='x')
            flag = false;

        if(flag==true)
            cout<<"1"<<endl;
        else
            cout<<"0"<<endl;

    }
    
    inStream.close();
}
