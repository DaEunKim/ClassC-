//
//  main.cpp
//  요일계산하기
//
//  Created by 김다은 on 2017. 3. 30..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

bool isE(int i){
    if(i%400==0)//윤년
        return 1;
    else if(i%100==0)
        return 0;
    else if(i%4==0)
        return 1;
    else//평년
        return 0;
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/요일계산하기/요일계산하기/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0;z<T;z++){
        int Y, M, D;
        inStream >> Y>>M>>D;
        int num = 0;
        int check = 0;
        
        for(int i = 1582;i<Y;i++){
            if(isE(i))
                check += 366;
            else
                check += 365;
        }
        
        for(int i = 1;i<M;i++){
            if(i==2){
                if(isE(Y))
                    check+=29;
                else
                    check+=28;
            }
            else if(i==4 || i==6 || i==9 || i==11)
                check +=30;
            else
                check +=31;
        }
        
        check += (D-1);
        
        num = ((check%7)+5)%7;
        cout<<num<<endl;
        
    }
    
    inStream.close();
}
