//
//  main.cpp
//  삼각형면적
//
//  Created by 김다은 on 2017. 3. 20..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>
using namespace std;


int main(void){
    ifstream inStream;
    inStream.open("/Users/Dani/Documents/C++class/삼각형면적/삼각형면적/input.txt");
    
    if(inStream.fail()){
        cerr<<"input file opening failed.\n";
        exit(1);
    }
    int T;
    inStream >> T;
    int ax, ay, bx, by, cx, cy;
    int Area=0;//2배한 면적
    for(int z = 0;z < T; z++){
        inStream >> ax >> ay >> bx >> by >> cx >> cy;
        
        Area = (bx - ax)*(cy - ay)-(cx - ax)*(by - ay);
        if(Area <0)
            cout << abs(Area) <<" "<< "-1" <<endl;
        else if(Area>0)
            cout << abs(Area) <<" "<< "1" <<endl;
        else if(Area ==0)
            cout << abs(Area) <<" "<< "0" <<endl;
    
    }
    
    inStream.close();
}
