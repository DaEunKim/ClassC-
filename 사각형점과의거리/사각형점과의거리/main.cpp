//
//  main.cpp
//  사각형점과의거리
//
//  Created by 김다은 on 2017. 3. 15..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;

int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/111Coding/C++class/사각형점과의거리/사각형점과의거리/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int x1, y1, x2, y2;
    int p, q;
    
    for(int i = 0;i < T;i++){
        inStream >> x1 >> y1 >> x2 >> y2;
        inStream >> p >> q;
        //1 2 3
        //4 5 6
        //7 8 9
        if(x1<=p and p<=x2 and y1<=q and q<=y2)//5
            cout<< "0" <<" "<< "0" <<endl;
        
        else if(x1>p and y2<q)//1
            cout << (x1-p)*(x1-p)+(y2-q)*(y2-q)<< " " << abs(x1-p)+abs(y2-q)<<endl;
        
        else if(x1<=p and p<=x2 and y2<q)//2
            cout << (y2-q)*(y2-q)<< " " << abs(y2-q)<<endl;//2
        
        else if(x2<p and y2<q)//3
            cout << (x2-p)*(x2-p)+(y2-q)*(y2-q)<< " " << abs(x2-p)+abs(y2-q)<<endl;//3
        
        else if(x1>p and y1<=q and q<=y2)//4
            cout << (x1-p)*(x1-p)<< " " << abs(x1-p)<<endl;//4
        
        else if(x2<p and y1<=q and q<=y2)//6
            cout << (x2-p)*(x2-p)<< " " << abs(x2-p)<<endl;//6
        
        else if(x1>p and y1>q)//7
            cout << (x1-p)*(x1-p)+(y1-q)*(y1-q)<< " " << abs(x1-p)+abs(y1-q)<<endl;//7
        
        else if(x1<=p and p<=x2 and y1>q)//8
            cout << (y1-q)*(y1-q)<< " " << abs(y1-q)<<endl;//8
        
        else if(x2<p and y1>q)//9
            cout << (x2-p)*(x2-p)+(y1-q)*(y1-q)<< " " << abs(x2-p)+abs(y1-q)<<endl;//9
        
    }
    
    inStream.close();
}
