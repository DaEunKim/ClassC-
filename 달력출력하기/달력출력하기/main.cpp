//
//  main.cpp
//  달력출력하기
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
    inStream.open("/Users/Dani/Documents/C++class/달력출력하기/달력출력하기/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0;z<T;z++){
        int Y, M;
        int D = 1;
        inStream >> Y>>M;
        int day = 0;
        int num = 0;
        int arr[31][31]={0, };
        
        for(int i = 1582;i<Y;i++){
            if(isE(i))
                day += 366;
            else
                day += 365;
        }
        
        for(int i = 1;i<M;i++){
            if(i==2){
                if(isE(Y))
                    day +=29;
                else
                    day +=28;
            }
            else if(i==4 || i==6 || i==9 || i==11)
                day +=30;
            else
                day +=31;
        }
        
        day += (D-1);
        num = ((day%7)+5)%7;
        int cnt =0 ;
        
        for(int i = 0;i<num;i++){
            arr[0][i] = 0;
        }
        for(int i = num;i<8;i++)
            arr[1][i] = cnt++;
        
        cout<<Y<<" "<<M<<endl;
        
        for(int i = 2;i<7;i++){
            for(int j = 1;j<8;j++){
                if(M==2){
                    if(isE(Y)){
                        if(cnt<=29)
                            arr[i][j] = cnt++;
                    }
                    else{
                        if(cnt<=28)
                            arr[i][j] = cnt++;
                        
                    }

                }
                else if(M==4 || M==6 || M==9 || M==11){
                    if(cnt<=30)
                        arr[i][j] = cnt++;
                }
                else{
                    if(cnt!=32)
                        arr[i][j] = cnt++;
                }
            }
        }
        
        for(int i = 1;i<7;i++){
            if(i != 1 && arr[i][1] == 0)
                break;
            for(int j = 1;j<8;j++){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
        
    }
    
    inStream.close();
}
