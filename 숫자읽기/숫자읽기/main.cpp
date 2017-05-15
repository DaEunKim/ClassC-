//
//  main.cpp
//  숫자읽기
//
//  Created by 김다은 on 2017. 5. 9..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

string unit[20] ={"","One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen","Nineteen"};
string tenth[10]={"Twenty", "Thirty","Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
string third[10]={"Hundred", "Thousand", "Million", "Billion"};

string ans = "";


string reader(int num){
    if(num ==0)
        return "";
    
    int global_ = 0;
    string ret = "";
    
    if(num >=100){
        if(ans!="" && ans.at(ans.size()-1) != '_')
            ret +="_", global_ = 1;
        
        ret += unit[num/100]+"_"+third[0];
       }
    if(num%100 >= 20){
        if(global_ ==0 && ans!="" && ans.at(ans.size()-1) != '_')
            ret +="_", global_ = 1;

        if(ret!="" && ret.at(ret.size()-1)!='_')
            ret += "_";
        
        ret += tenth[num%100/10-2];
        
        if(unit[num%10]!="")
            ret += "_"+unit[num%10];
        
    }
    else if (num % 100 !=0){
        if(global_ ==0 && ans!="" && ans.at(ans.size()-1) != '_')
            ret +="_", global_ = 1;
        
        if(ret != "" && ret.at(ret.size()-1) != '_')
            ret += "_";
        
        ret+= unit[num%20];
    }
    
    return ret;
}

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/숫자읽기/숫자읽기/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    for(int z = 0;z < T; z++){
        int n;
        inStream>>n;
        
        ans.clear();
        
        int temp[10];
        int index = 0;
        while(n){
            temp[index++] = n%1000;
            n /= 1000;
        }
        
        
        for(int i = 0;i<index;i++){
            string str = reader(temp[index - 1- i]);
            if(str == "")
                continue;
            ans += str;
            (index-1-i) ? ans += "_"+third[index - 1- i] : ans+="";

        }
        cout<<ans <<endl;
        
    }
        
    inStream.close();
}
