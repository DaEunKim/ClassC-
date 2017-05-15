//
//  main.cpp
//  숫자진법변환
//
//  Created by 김다은 on 2017. 4. 11..
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

int toInt(char c){
    if('0' <= c && c <= '9')
        return c - '0';
    else if('A'<=c && c<='Z')
        return c - 'A' + 10;
    return c - 'a' + 10;
}

char toChar(int n){
    if (n < 10)
        return n + '0';
    return 'a' + (n-10);
}

int toTen(string n, int s)
{
    int sum = 0;
    int len = (int)n.size();
    
    for(int i=0; i<len;i++){
        char c = n.at(i);
        int toint = toInt(c);
        int mul = Mul(s, len-i-1);
        
        sum += toint*mul;
    }
    
    return sum;
}

void printZinSu(int n, int t){
    
    int rest[32]={0,};
    int i = 0;
    while(n>=t){
        rest[i] = n%t;
        n = n/t;
        i++;
    }
    rest[i++] = n%t;
    
    for(int j = i-1;j>=0;j--){
        char c = toChar(rest[j]);
        cout<<c;
    }
    cout<<endl;
    
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/숫자진법변환/숫자진법변환/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0; z < T; z++){
        int s;//진법
        string n;//수
        int t;//바꿀 진법
        inStream >> s >> n >> t;
 
        int middle = toTen(n, s);
        
        printZinSu(middle, t);
        
    }
    inStream.close();
}
