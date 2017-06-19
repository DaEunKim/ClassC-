//
//  game.h
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#ifndef game_h
#define game_h

#include <curses.h>
#include <random>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <fstream>
#include "Block.h"

#define game_BeginX 2
#define game_BeginY 2
#define game_WindowRow 20
#define game_WindowCol 22

enum state_num
{
    temp = 0,
    moving = 1,
    exist = 1000,
    wall = 10000
};

class game_win_interface
{
private:
    WINDOW * game_window;
    int field[19][12];
    int copy_filed[19][12];
    int nextblock;
    int removed_line;
    bool gameover;
public:
    game_win_interface(): removed_line(0), gameover(false)
    {
        game_window = newwin(game_WindowRow, game_WindowCol, game_BeginY, game_BeginX);
        for (int i = 0; i <= 17; i++)
            for (int j = 1; j <= 10; j++)
                field[i][j] = temp;
        for (int i = 0; i <= 18; i++)
        {
            field[i][0] = wall;
            field[i][11] = wall;
        }
        for (int i = 0; i <= 11; i++)
            field[18][i] = wall;
    }
    void print_bg();
    void print_block(const int& block);
    void play_game();
    void move_block(Block* Block, const int& ch, const int& block_num);
    void remove_block(const int &Y, const int& block_num);
    bool isItFull(const int &Y, const int& block_num);
    bool is_it_gameover(const int& block_num);
    void update_field(const Block* Block, const int& X, const int& Y, const int &value);
    bool Can_it_move(const Block* Block, const int& block_num);
    int get_removed_line();
    int get_nextblock();
    bool get_gameover();
    void make_gameover();
    int get_state(const int& data);
    void input_nextblock(int num);
    bool can_make_new_block(const Block* Block, const int& block_num);
    ~game_win_interface(){}
};



#endif /* game_h */
