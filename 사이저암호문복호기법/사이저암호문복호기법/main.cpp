//
//  main.cpp
//  사이저암호문복호기법
//
//  Created by 김다은 on 2017. 4. 7..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

void cippper(char cipher[], int key){
    unsigned char arr[501] = {0, };
    int size = strlen(cipher);
    
    for(int i = 0;i<size; i++){
        //65~90 97~122
        if(65<=cipher[i] && cipher[i]<=90){
            arr[i] = cipher[i] + key;
            if(arr[i]<65){
                arr[i] = arr[i]+26;
            }
            else if(arr[i]>90){
                arr[i] = arr[i]-26;
            }
        }
        else if(97<=cipher[i] && cipher[i]<=122){
            arr[i] = cipher[i] + key;
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
        cipher[i] = arr[i];
    }
    
}


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/사이저암호문복호기법/사이저암호문복호기법/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        string ci;
        inStream >> ci;
        
        char cipher[501] = {0, };
        int key;
        /*
         A = 8.167
         B = 1.492 C = 2.782 D = 4.253 E = 12.702 F = 2.228 G = 2.015 H = 6.094 I = 6.996
         J = 0.153 K = 0.772 L = 4.025
         M = 2.406
         N = 6.749 O = 7.507
         P = 1.929 Q = 0.095 R = 5.987 S = 6.327
         T = 9.056 U = 2.758 V = 0.978 W = 2.360 X = 0.150 Y = 1.974 Z = 0.074
         */

        double fe[] = {8.167, 1.492, 2.782 , 4.253, 12.702, 2.228, 2.015, 6.094, 6.996, 0.153, 0.772, 4.025, 2.406, 6.749, 7.507, 1.929, 0.095, 5.987 , 6.327, 9.056, 2.758, 0.978, 2.360, 0.150, 1.974,  0.074};
        
        int size = (int)ci.size();
        int freq[501] = {0, };
        int max = -999;
        for(int i = 0;i<size;i++){
            if('A'<= ci.at(i) && ci.at(i)<='Z')
                cipher[i] = ci.at(i) + 32;
            else
                cipher[i] = ci.at(i);
            
        }
        int sum = 0;
        
        for(int i = 0; i<size;i++){
            if('a'<= cipher[i] && cipher[i]<='z'){
                freq[cipher[i]-'a']++;
                sum++;
            }
            
            
        }
        int t = 0;
        for(int i = 0;i<size;i++){
            if(max < freq[i]){
                max = freq[i];
                t = i;
            }
        }
        
        double kai[26] = {0, };
        
        double tmp = 0;
        for(int i = 0;i<26;i++){
            for(int j = 0;j<26;j++){
                tmp = ((double)freq[(i+j)%26]/sum)*100;
                kai[i] += (tmp*tmp)/fe[j];
            }
        }
        
        double min = kai[0];
        key = 0;
        for(int i=1; i<26; i++)
            if(min > kai[i]){
                min = kai[i];
                key = i;
            }
        
        char ans[501] = {0, };
        for(int i=0; i<size; i++)
            ans[i] = ci.at(i);
        
        cippper(ans, -key);
        cout << ans << endl;
        
        

        
    }
    
    inStream.close();
}

