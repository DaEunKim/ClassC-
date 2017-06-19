//
//  score.h
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#ifndef score_h
#define score_h

#include <curses.h>
#include <string.h>
#include "game.h"

#define score_BeginX 30
#define score_BeginY 4
#define score_WindowRow 4
#define score_WindowCol 10

class score_win_interface
{
private:
    WINDOW * score_win;
public:
    
    score_win_interface()
    {
        score_win = newwin(score_WindowRow, score_WindowCol, score_BeginY, score_BeginX);
    }
    void print_score_win_bg();
    void print_score_on_win(game_win_interface gw);
};

#endif /* score_h */
