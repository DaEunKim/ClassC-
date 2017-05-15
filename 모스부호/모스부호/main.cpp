//
//  main.cpp
//  모스부호
//
//  Created by 김다은 on 2017. 5. 9..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/모스부호/모스부호/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        string n;
        inStream >>n;
        
        string alpabet[26]={".-", "-...", "-.-." ,"-..", ".", "..-.",
                            "--.", "....", "..", ".---", "-.-", ".-..",
                            "--", "-.", "---", ".--.", "--.-", ".-.",
                            "...", "-", "..-", "...-", ".--", "-..-",
                            "-.--", "--.."
                            };
        
        char c[2001]={0,};
        
        for(int i = 0;i<n.size();i++){
            c[i] = n.at(i);
            
        }
        string tmp[2001];
        
        int idx = 0;
        for(int i = 0;i<n.size();i++){
            if(c[i]=='#')
                c[i]='_';
        }
        
        char data[2001] = {0,};
        
        for(int i = 0;i<n.size();i++){
            if(c[i]=='_')
                data[idx] ='_';
            if(c[i]!='|' && c[i]!='_'){
                tmp[idx] += c[i];
                
            }
            else{
                idx++;
            }
        }
        
        char hanul[2001] = {0,};
        for(int i = 0;i<=idx;i++){
            for(int j = 0;j<26;j++){
                if(tmp[i]==alpabet[j]){
                    hanul[i] = j + 'A';
                 }
            }
        }
        
        for(int i = 0;i<=idx;i++){
            if(data[i] != 0)
                cout<<hanul[i]<<data[i];
            else
                cout<<hanul[i];
        }
        cout<<endl;
        
    }
    inStream.close();
}
