//
//  main.cpp
//  시이저암호기법
//
//  Created by 김다은 on 2017. 4. 9..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/시이저암호기법/시이저암호기법/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int num;
        string ci;
        char cipher[101] = {0, };
        inStream >> num;
        inStream >> ci;
        
        int size = (int)ci.size();
        for(int i = 0;i<size;i++){
            
            cipher[i] = ci.at(i);
        }
        
        unsigned char arr[101] = {0, };
        for(int i = 0;i<size; i++){
            //65~90 97~122
            if(65<=cipher[i] && cipher[i]<=90){
                arr[i] = cipher[i] + num;
                if(arr[i]<65){
                    arr[i] = arr[i]+26;
                }
                else if(arr[i]>90){
                    arr[i] = arr[i]-26;
                }
            }
            else if(97<=cipher[i] && cipher[i]<=122){
                arr[i] = cipher[i] + num;
                if(arr[i]<97){
                    arr[i] = arr[i]+26;
                    
                }
                else if(arr[i]>122){
                    arr[i] = arr[i]-26;
                }

            }
            else
                arr[i] = cipher[i];
        }
        for(int i = 0;i<size;i++){
            cout<< arr[i];
        }
        cout<<endl;
        
        
        
        
    }
    
    inStream.close();
}
