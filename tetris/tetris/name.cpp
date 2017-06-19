//
//  name.cpp
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#include "name.h"
#include <string.h>

void name_win_interface::print_bg(){
    wattron(name_win, COLOR_PAIR(4));
    mvwprintw(name_win, 1, 1, "name:");
    wattroff(name_win, COLOR_PAIR(4));
    wborder(name_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(name_win);
}
void name_win_interface::print_name(){
    wattron(name_win, COLOR_PAIR(4));
    mvwprintw(name_win, 2, 1, "%s", user_name);
    wattroff(name_win, COLOR_PAIR(4));
    wborder(name_win, '|', '|', '-', '-', '+', '+', '+', '+');
    wrefresh(name_win);
}
