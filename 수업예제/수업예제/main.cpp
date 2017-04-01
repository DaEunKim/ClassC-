
//  main.cpp
//  수업예제
//
//  Created by 김다은 on 2017. 3. 15..
//  Copyright © 2017년 김다은. All rights reserved.
//

#include <iostream>
using namespace std;

class Example{
public:
    int i=7;
    int j;
	char c = 'a';
	double interest_rate=0.05;
};

int main(int argc, char *argv[])
{
    Example ex;
    //ex.i = 10;
    //ex.j = 20;
	cout << "ex.c = " << ex.c << endl;
	cout << "rate = " << ex.interest_rate << endl;
    cout << "ex.i = " << ex.i << endl;
    return 0;
}
