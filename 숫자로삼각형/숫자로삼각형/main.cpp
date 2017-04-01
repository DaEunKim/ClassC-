//
//  main.cpp
//  숫자로삼각형
//
//  Created by 김다은 on 2017. 3. 8..
//  Copyright © 2017년 김다은. All rights reserved.
//

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
    inStream.open("/Users/Dani/Documents/111Coding/C++class/숫자로삼각형/숫자로삼각형/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int n;
    int arr[100][100] = {0, };
    
    for(int i = 0;i < T; i++){
        inStream >> n;
        int count=1;
        
        for(int j = 0; j<n;j++){
            
            for(int z = j; z<n; z++){
                arr[z][j] = count++;
            }

        }
        for(int j = 0; j<n;j++){
            for(int z = 0;z<n;z++){
                if(arr[j][z]==0)
                    break;
                cout << arr[j][z] <<" " ;
                
            }
            cout<<endl;
        }
        
        
    }
    
    inStream.close();
}
