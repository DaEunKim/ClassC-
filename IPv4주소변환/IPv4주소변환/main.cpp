//
//  main.cpp
//  IPv4주소변환
//
//  Created by 김다은 on 2017. 5. 6..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <string>
using namespace std;


char toChar(int n){
    if (n < 10)
        return n + '0';
    return 'a' + (n-10);
}

int Mul(int a, int b){ //a^b
    int mul = 1;
    for(int i = 0; i<b; i++){
        mul *= a;
    }
    return mul;
}
int main(void){
    FILE *f = fopen("/Users/Dani/Documents/ClassCpp/IPv4주소변환/IPv4주소변환/input.txt", "r");
    int T;
    fscanf(f, "%d", &T);
    
    for(int z = 0; z < T; z++){
        int k;
        string ns;
        unsigned int n=0;
        fscanf(f, "%d", &k);
        
        int twozin[32]={0,};
        
        if(k==1){
            unsigned int ip[4] ={0,};

            fscanf(f, "%d.%d.%d.%d", ip, ip+1, ip+2, ip+3);
            
            
            cout<< ((ip[0] << 24) + (ip[1] << 16) + (ip[2] << 8) + (ip[3]))<<endl;

            
        }
        else if(k==2){
            fscanf(f, "%d", &n);

            int q = 0;
            
            while(n >=2){
                twozin[q] = n%2;
                n = n/2;
                q++;
            }
            twozin[q++] = n%2;
            
            int ten = 0;
            for(int j = 31;j>=24;j--){
                if(twozin[j]==1){
                    ten += Mul(2, j-24);
                }
            }
            cout<<ten;
            ten = 0;
            cout<<".";
            
            for(int j = 23;j>=16;j--){
                if(twozin[j]==1){
                    ten += Mul(2, j-16);
                }
            }
            cout<<ten;
            ten = 0;
            cout<<".";

            for(int j = 15;j>=8;j--){
                if(twozin[j]==1){
                    ten += Mul(2, j-8);
                }
            }
            cout<<ten;
            ten = 0;
            cout<<".";
            
            for(int j = 7;j>=0;j--){
                if(twozin[j]==1){
                    ten += Mul(2, j);
                    
                }
            }
            cout<<ten;
            ten = 0;
            cout<<endl;
            
        }
        
        
        
    }
    
}
