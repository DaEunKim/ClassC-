//
//  main.cpp
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <random>
#include <curses.h>
#include "game.h"
#include "Block.h"
#include "score.h"
#include "name.h"
using namespace std;

#define terminalRow 25
#define terminalCol 50

//void init();
//void display();

void check_key(void);
//void print_game_over();
int main(int argc, char* argv[]) {
    ifstream inStream;
    
    char cur_key[8];
    
    // i) arg를 확인하여, 입력파일이 있으면 파일을 연다. (없으면 그냥 통과)
    if(argc >1)
        inStream.open(argv[1]);
    
    if(argc > 1)
        inStream >> cur_key;
    else{
        cout<< "User name : ";
        cin >>cur_key;
    }
    // ii) 테트리스 게임의 초기 화면을 구성한다.
    initscr();
    noecho();
    start_color();
    keypad(stdscr, TRUE);
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    curs_set(0);
    noecho();
    
    bkgd(COLOR_PAIR(1));
    resize_term(terminalRow, terminalCol);
    attron(COLOR_PAIR(1));
    border('|', '|', '-', '-', '*', '*', '*', '*');
    attroff(COLOR_PAIR(1));
    refresh();
    
    score_win_interface score_win;
    name_win_interface name_win(cur_key);
    game_win_interface game_win;
    
    score_win.print_score_win_bg();
    score_win.print_score_on_win(game_win);
    name_win.print_bg();
    game_win.print_bg();
    name_win.print_name();
    noecho();
    
    //   display();
    
    while(1){
        
        Block* tetrimino[7];
        tetrimino[0] = new tetrimino_0;
        tetrimino[1] = new tetrimino_1;
        tetrimino[2] = new tetrimino_2;
        tetrimino[3] = new tetrimino_3;
        tetrimino[4] = new tetrimino_4;
        tetrimino[5] = new tetrimino_5;
        tetrimino[6] = new tetrimino_6;
        
        timeout(800);
        int block_num = rand()%7;
        game_win.input_nextblock(0);
        
        
        // iii) 종료가 될 때까지 게임을 진행한다.
        while (!game_win.get_nextblock()){
            check_key();
            if(!game_win.can_make_new_block(tetrimino[block_num], block_num)){
                game_win.make_gameover();
                game_win.update_field(tetrimino[block_num], tetrimino[block_num]->get_x(), tetrimino[block_num]->get_y(), moving+block_num);
                game_win.print_block(block_num);
                break;
            }
            game_win.update_field(tetrimino[block_num], tetrimino[block_num]->get_x(), tetrimino[block_num]->get_y(), moving+block_num);
            game_win.print_block(block_num);
            
            if( argc != 1)
            {
                int ch;
                char ip;
                inStream >> ip;
                ch = ip;
                game_win.move_block(tetrimino[block_num], ch, block_num);
            }
            else
            {
                int ch = getch();
                game_win.move_block(tetrimino[block_num], ch, block_num);
            }
        }
        
        game_win.remove_block(tetrimino[block_num]->get_y(), block_num);
        game_win.print_block(block_num);
        score_win.print_score_on_win(game_win);
        if (game_win.get_gameover()){
            for(int i = 0 ; i < 7 ; i ++)
                delete tetrimino[i];
            break;
        }
        
        for(int i = 0 ; i < 7 ; i ++)
            delete tetrimino[i];
        
    }
    
    // iv) 테트리스 게임에 쓰인 각종 리소스를 반환한다.
    timeout(1000000);
    mvprintw(22, 10, "score is %d", game_win.get_removed_line());
    mvprintw(23, 10, "Press any key to exit tetris");
    getch();
    endwin();
    
    return 0;
    
    
}
