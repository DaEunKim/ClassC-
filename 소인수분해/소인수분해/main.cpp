//
//  main.cpp
//  소인수분해
//
//  Created by 김다은 on 2017. 3. 31..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/ClassCpp/소인수분해/소인수분해/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    vector<int> v;
    for(int i = 2;i<=10000;i++){
        bool flag = true;
        
        for(int j = 2;j<i;j++){
            if (i%j == 0)
                flag = false;
        }
        
        if (flag==true) v.push_back(i);
    }
    
    for(int z = 0; z < T; z++){
        int n;
        set<int> s;
        
        inStream >>n;
        vector<int> tmp;
        
        // 소수 세기
        for(int i = 0;i<v.size();i++){
            int cnt = 0;
            
            while(n%v[i] == 0){
                ++cnt;
                s.insert(v[i]);
                n /= v[i];
            }
            
            if(cnt!=0)
                tmp.push_back(cnt);
        }
        
        if(s.size()!=0)
            cout<<s.size()<<" ";
        
        int j = 0;
        for(set<int>::iterator i = s.begin();i!=s.end();i++){
            cout<<*i<<" ";
            
            
            cout << tmp[j] << " ";
            
            j++;
        }
        int cnt2=0;
        if(n!=1){
            ++cnt2;
            cout<<cnt2<<" ";
            cout<<n<<" ";
            cout<<"1 ";
        }
        cout<<endl;
    }
    
    
    inStream.close();
}





