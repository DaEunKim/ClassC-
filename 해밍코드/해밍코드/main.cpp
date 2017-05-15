//
//  main.cpp
//  해밍코드
//
//  Created by 김다은 on 2017. 5. 5..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int Mul(int a, int b){
    int mul = 1;
    for(int i = 0; i<b; i++){
        mul *= a;
    }
    return mul;
}

int toTen(int n[])
{
    int sum = 0;
    
    for(int i=1; i<32;i++){
        int mul = Mul(n[i], i);
        
        sum += mul;
    }
    
    return sum;
}


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/해밍코드/해밍코드/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int k, n;
    for(int z = 0; z < T; z++){
        inStream >>k>>n;
        int twozin[32] = {0,};
        int two[32] = {0,};
        int i = 0;
        int P1 = 0, P2=0, P4=0, P8=0, P16=0;
        
        while(n >=2){
            twozin[i] = n%2;
            n = n/2;
            i++;
        }
        twozin[i] = n%2;
        
        int cnt1 = 0;
        int cnt2 = 0;
        int cnt4 = 0;
        int cnt8 = 0;
        int cnt16 = 0;
        
        for(int j = 0 ;j<i;j++){
            two[j] = twozin[i-j];
            cout<<two[j];
        }
        
        for(int j = 0;j<i;j++){
            if(j%2==1){
                if(two[j]==1)
                    cnt1++;
            }
            else if(j%2==0){
                for(int k = 0;k<2;k++){
                    if(two[j+k]==1)
                        cnt2++;
                }
            }
            else if(j%4==0){
                for(int k = 0;k<4;k++){
                    if(two[j+k]==1)
                        cnt4++;
                }

            }
            else if(j%8==0){
                for(int k = 0;k<8;k++){
                    if(two[j+k]==1)
                        cnt8++;
                }

            }
            else if(j%16==0){
                for(int k = 0;k<16;k++){
                    if(two[j+k]==1)
                        cnt16++;
                }
                
            }
            
            if(cnt1%2==0) P1 =0;
            else P1=1;
            if(cnt2%2==0) P2 =0;
            else P2=1;
            if(cnt4%2==0) P4 =0;
            else P4=1;
            if(cnt8%2==0) P8 =0;
            else P8=1;
            if(cnt16%2==0) P16 =0;
            else P16=1;

    
        }
        cout<<endl;
        cout<<toTen(two);
//        
//        P1 = 0xFF & (n >> 1);
//        P2 = 0xFF & (n >> 2);
//        P4 = 0xFF & (n >> 4);
//        P8 = 0xFF & (n >> 8);
//        P16 = 0xFF & (n >> 16);
//        
        cout<< P1 <<endl;
        cout<< P2 <<endl;
        cout<< P4 <<endl;
        cout<< P8 <<endl;
        cout<< P16 <<endl;
        cout<<endl;
        
//        for(int i = 0;i<32;i++){
//            if(n!=0){
//                if(n%2==1)
//                    count++;
//                n = n/2;
//            }
//        }
//        
//        if(count%2 == 1)
//            original += 2147483648;
        
//        cout<<original<<endl;
        
        
        
    }
    
    inStream.close();
}
