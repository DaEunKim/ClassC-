//
//  main.cpp
//  시간계산
//
//  Created by 김다은 on 2017. 3. 7..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/시간계산/시간계산/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int i = 0;i < T; i++){
        int n;//직원 수
        inStream >> n;
        
        int d=0, H, M, S, h, m, s;
        int result_h=0, result_m=0, result_s=0;
        
        for(int j = 0; j < n; j++){
            inStream >> H >> M >> S >> h >> m >> s;
            result_h += h - H;
            result_m += m - M;
            result_s += s - S;
            
            if(result_s<0){
                result_s = 60 + result_s;
                result_m--;
            }
            
            if(result_s>=60){
                result_s = result_s%60;
                result_m++;
            }
            
            if(result_m<0){
                result_m = 60 + result_m;
                result_h--;
            }

            if(result_m>=60){
                result_m = result_m%60;
                result_h++;
            }
            if(result_h>=24){
                d += result_h/24;
                result_h = result_h%24;
            }
        }
        cout << d << " " << result_h << " " << result_m << " " << result_s <<endl;
        
        
    }
    
    inStream.close();
}
