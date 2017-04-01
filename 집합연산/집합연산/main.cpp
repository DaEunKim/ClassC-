//
//  main.cpp
//  집합연산
//
//  Created by 김다은 on 2017. 3. 28..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <set>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/집합연산/집합연산/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    
    int A;
    int B;
    
    
    for(int z = 0;z < T; z++){
        int ma[133] = {0, };
        int mb[133] = {0, };
        
        set<int> s_inter;
        set<int> s_union;
        set<int> s_diff;
    
        int intersection[133] = {0, };
        
        inStream >> A;
        for(int i = 0;i<A;i++)
            inStream >> ma[i];
        
        inStream >> B;
        for(int i = 0;i<B;i++)
            inStream >> mb[i];
        
        for(int i = 0;i<A;i++)
                s_union.insert(ma[i]);
        for(int i=0; i<B; i++)
                s_union.insert(mb[i]);
        
        for(int i = 0;i<A;i++){
            for(int j = 0;j<B;j++){
                if(ma[i]==mb[j]){
                    intersection[i] = ma[i];
                    s_inter.insert(ma[i]);
                    
                }
            }
            
            if(ma[i] != intersection[i]){
                s_diff.insert(ma[i]);
            }
        }
        
        
        cout<<s_inter.size();
        for(set<int>::iterator i = s_inter.begin();i!=s_inter.end();i++){
            cout<<" "<<*i;
        }
        cout<<endl;
        
        
        cout<<s_union.size();
        for(set<int>::iterator i = s_union.begin(); i!=s_union.end(); i++){
            cout<<" "<<*i;
        }
        cout<<endl;
        
        cout<<s_diff.size();
        for(set<int>::iterator i = s_diff.begin();i!=s_diff.end();i++){
            cout<<" "<< *i;

        }
        cout<<endl;
        
    }
    
    inStream.close();
}
