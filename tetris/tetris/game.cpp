//
//  game.cpp
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#include "Block.h"
#include "game.h"
#include <iostream>
#include <string.h>

void game_win_interface::print_bg()
{
    wattron(game_window, COLOR_PAIR(2));
    for (int i = 1; i <= 18; i++)
        mvwprintw(game_window, i, 1, "######################");
    wattroff(game_window, COLOR_PAIR(2));
    wborder(game_window, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(game_window);
}
void game_win_interface::print_block(const int& block_num)
{
    init_pair(10, COLOR_YELLOW, COLOR_BLACK);
    init_pair(11, COLOR_BLUE, COLOR_BLACK);
    init_pair(12, COLOR_GREEN, COLOR_BLACK);
    init_pair(13, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(14, COLOR_RED, COLOR_BLACK);
    init_pair(15, COLOR_CYAN, COLOR_BLACK);
    init_pair(16, COLOR_WHITE, COLOR_BLACK);
#ifndef DEBUG
    for (int i = 1; i <= 18; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int Y = i;
            int X = j * 2 - 1;
            if (get_state(field[i - 1][j])== exist )
            {
                wattron(game_window, COLOR_PAIR(10+field[i-1][j] - exist));
                mvwprintw(game_window, Y, X, "||");
                wattroff(game_window, COLOR_PAIR(10+field[i-1][j] - exist));
            }
            else if(get_state(field[i - 1][j]) == moving)
            {
                wattron(game_window, COLOR_PAIR(10+field[i-1][j] - moving));
                mvwprintw(game_window, Y, X, "||");
                wattroff(game_window, COLOR_PAIR(10+field[i-1][j] - moving));
            }
            else
            {
                wattron(game_window, COLOR_PAIR(2));
                mvwprintw(game_window, Y, X, "//");
                wattroff(game_window, COLOR_PAIR(2));
            }
        }
        wrefresh(game_window);
    }
#endif
    wrefresh(game_window);
}
void game_win_interface::move_block(Block* Block, const int& ch, const int& block_num)
{
    if (ch == -1)
    {
        memcpy(copy_filed, field, sizeof(int)* 19 * 12);
        Block->update_y(1);
        update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
        update_field(Block, Block->get_x(), Block->get_y()-1, temp);
        if (!Can_it_move(Block, block_num))
        {
            memcpy(field, copy_filed, sizeof(int)* 19 * 12);
            Block->update_y(-1);
            update_field(Block, Block->get_x(), Block->get_y(), exist+block_num);
            nextblock++;
        }
    }
    else
    {
        if(ch == KEY_LEFT || ch == 'l')
        {
            Block->update_x(-1);
            memcpy(copy_filed, field, sizeof(int)* 19 * 12);
            update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            update_field(Block, Block->get_x()+1, Block->get_y(), temp);
            if (!Can_it_move(Block, block_num))
            {
                memcpy(field, copy_filed, sizeof(int)* 19 * 12);
                Block->update_x(1);
                update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            }
            
        }
        else if (ch == KEY_RIGHT || ch == 'r')
        {
            Block->update_x(+1);
            memcpy(copy_filed, field, sizeof(int)* 19 * 12);
            update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            update_field(Block, Block->get_x()-1, Block->get_y(), temp);
            if (!Can_it_move(Block, block_num))
            {
                memcpy(field, copy_filed, sizeof(int)* 19 * 12);
                Block->update_x(-1);
                update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            }
        }
        else if ( ch == KEY_DOWN || ch == 'g')
        {
            Block->update_y(+1);
            memcpy(copy_filed, field, sizeof(int)* 19 * 12);
            update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            update_field(Block, Block->get_x(), Block->get_y()-1, temp);
            if (!Can_it_move(Block, block_num))
            {
                memcpy(field, copy_filed, sizeof(int)* 19 * 12);
                Block->update_y(-1);
                update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
                nextblock++;
                update_field(Block, Block->get_x(), Block->get_y(), exist+block_num);
                is_it_gameover(block_num);
            }
        }
        else if ( ch == KEY_UP || ch == 't')
        {
            update_field(Block, Block->get_x(), Block->get_y(), temp);
            Block->update_rotation_num(1);
            memcpy(copy_filed, field, sizeof(int)* 19 * 12);
            update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            
            if (!Can_it_move(Block, block_num))
            {
                memcpy(field, copy_filed, sizeof(int)* 19 * 12);
                Block->update_rotation_num(-1);
                update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
            }
        }
        else if ( ch == ' ' || ch == 'd')
        {
            update_field(Block, Block->get_x(), Block->get_y(), temp);
            memcpy(copy_filed, field, sizeof(int)* 19 * 12);
            while (1)
            {
                Block->update_y(+1);
                update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
                update_field(Block, Block->get_x(), Block->get_y()-1, temp);
                if (!Can_it_move(Block, block_num))
                {
                    memcpy(field, copy_filed, sizeof(int)* 19 * 12);
                    Block->update_y(-1);
                    update_field(Block, Block->get_x(), Block->get_y(), moving+block_num);
                    break;
                }
            }
            update_field(Block, Block->get_x(), Block->get_y(), exist+block_num);
            nextblock++;
            is_it_gameover(block_num);
        }
        else if (ch == 'q')
        {
            gameover=true;
            nextblock++;
        }
    }
}
void game_win_interface::remove_block(const int &Y, const int& block_num)
{
    for (int k = 0; k <4; k++)
        for (int i = Y + 3; i >= Y; i--)
            if (isItFull(i, block_num))
            {
                removed_line ++;
                for (int k = i; k > 0; k--)
                {
                    for (int j = 1; j < 11; j++)
                    {
                        if (k == 1) field[k][j] = temp;
                        field[k][j] = field[k - 1][j];
                    }
                }
            }
}
bool game_win_interface::isItFull(const int &Y, const int& block_num)
{
    for (int i = 1; i < 11; i++)
        if (get_state(field[Y][i])!=exist)	return false;
    return true;
}
bool game_win_interface::is_it_gameover(const int& block_num)
{
    for (int i = 1; i < 11; i++)
        if (get_state(field[0][i])==exist)
        {
            gameover = true;
            return true;
        }
    gameover = false;
    return false;
}
void game_win_interface::update_field(const Block* Block, const int& X, const int& Y, const int &value)
{
    for (int y = 0; y < 4; y++)
    {
        for (int x = 0; x < 4; x++)
        {
            if (Block->get_shape(x, y) == 1)
            {
                field[Y + y][X + x] = value;
            }
        }
    }
}
bool game_win_interface::Can_it_move(const Block* Block, const int& block_num)
{
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if ( Block->get_shape(x, y) == 1)
                if (get_state(copy_filed[Block->get_y() + y][Block->get_x() + x]) == wall || get_state(copy_filed[Block->get_y() + y][Block->get_x() + x]) == exist)
                    return false;
    return true;
}
int game_win_interface:: get_removed_line()
{return removed_line ;}
int game_win_interface:: get_nextblock()
{return nextblock;}
void game_win_interface:: input_nextblock(int num)
{nextblock = num;}
bool game_win_interface:: get_gameover()
{
    return gameover;
}
int game_win_interface:: get_state(const int& data)
{
    if ( moving <= data && data <= moving + 6)
        return moving;
    else if ( exist <= data && data <= exist + 6)
        return exist;
    else if ( data == wall )
        return wall;
    else
        return temp;
}
bool game_win_interface:: can_make_new_block(const Block* Block, const int& block_num){
    for (int y = 0; y < 4; y++)
        for (int x = 0; x < 4; x++)
            if ( Block->get_shape(x, y) == 1)
                if (get_state(field[0 + y][5 + x]) == exist)
                    return false;
    return true;
}
void game_win_interface::make_gameover(){
    gameover = true;
}






