//
//  main.cpp
//  입체사목
//
//  Created by 김다은 on 2017. 5. 14..
//  Copyright © 2017년 김다은. All rights reserved.
//
#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

class connectFour
{
private:
    int board[6][8];
    int col_put;
    
public:
    connectFour();
    
    void play_game(ifstream &inStream, int p);
    int check_four();
};

int main(void)
{
    ifstream inStream;
    int numCases;
    
    inStream.open("/Users/Dani/Documents/ClassCpp/입체사목/입체사목/input.txt");
    
    if (inStream.fail()) {
        cerr << "opening failed" << endl;
    }
    
    inStream >> numCases;
    
    for (int i = 0; i < numCases; i++)
    {
        connectFour CF;
        
        int num_play;
        inStream >> num_play;
        
        for (int j = 0; j < num_play; j++)
            CF.play_game(inStream, j);
        
        if (CF.check_four() == 1)
            cout << 1 << endl;
        else if (CF.check_four() == 2)
            cout << 2 << endl;
        else if (CF.check_four() == 0)
            cout << 0 << endl;
    }
    
    inStream.close();
    return 0;
}

connectFour::connectFour() : col_put(0)
{
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 8; j++)
        {
            if (j != 0)
                board[i][j] = 0;
            else
                board[i][j] = -1;
        }
}

void connectFour::play_game(ifstream &inStream, int p)
{
    int person;
    if (p % 2 == 0) person = 1;
    else person = 2;
    
    inStream >> col_put;
    
    int i = 5;
    while (i>=0)
    {
        if (board[i][col_put] != 0)
            i--;
        else if (board[i][col_put] == 0)
        {
            if (person == 1)
            {
                board[i][col_put] = 1;
                return;
            }
            else if (person == 2)
            {
                board[i][col_put] = 2;
                return;
            }
        }
        else
            return;
    }
    
    
}

int connectFour::check_four()
{
    int cnt = 0;
    
    for (int i = 0; i < 6; i++)
        for (int j = 1; j < 8; j++)
        {
            if (board[i][j] == 1 || board[i][j] == 2)
            {
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i<=2)&&board[i][j] == board[i + k][j]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i<=4)&&board[i][j] == board[i][j+k]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i>=4)&&board[i][j] == board[i][j-k]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i<=2 && j<=4)&&board[i][j] == board[i+k][j+k]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i<=2&&j>=4)&&board[i][j] == board[i + k][j-k]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i>=3&&j<=4)&&board[i][j] == board[i-k][j+k]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                cnt = 1;
                for (int k = 1; k < 4; k++)
                {
                    if ((i>=3&&j>=4)&&board[i][j] == board[i-k][j-k]) cnt++;
                    if (cnt == 4) return board[i][j];
                }
                
            }
        }
    return 0;
}
