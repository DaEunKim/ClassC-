//
//  score.cpp
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#include "game.h"
#include "score.h"
#include <string.h>
void score_win_interface::print_score_win_bg()
{
    wattron(score_win, COLOR_PAIR(4));
    mvwprintw(score_win, 1, 1, "score:");
    wattroff(score_win, COLOR_PAIR(4));
    wborder(score_win, '|', '|', '-', '-', '*', '*', '*', '*');
    wrefresh(score_win);
}
void score_win_interface::print_score_on_win(game_win_interface gw)
{
    wattron(score_win, COLOR_PAIR(4));
    mvwprintw(score_win, 2, 1, "%d", gw.get_removed_line());
    wattroff(score_win, COLOR_PAIR(4));
    wrefresh(score_win);
}
