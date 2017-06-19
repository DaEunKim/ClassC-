//
//  name.h
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#ifndef name_h
#define name_h

#include <curses.h>
#include <memory>
#include <iostream>
#include <cstdlib>
#include <string.h>


#define name_BeginX 30
#define name_BeginY 10
#define name_WindowRow 4
#define name_WindowCol 10

class name_win_interface
{
private:
    WINDOW * name_win;
    char user_name[8];
public:
    name_win_interface(const char _user_name[8])
    {
        name_win = newwin(name_WindowRow, name_WindowCol, name_BeginY, name_BeginX);
        memcpy(user_name, _user_name, sizeof(char)*strlen(_user_name));
        user_name[strlen(_user_name)] = '\0';
    }
    void print_bg();
    void print_name();
    ~name_win_interface(){}
};

#endif /* name_h */
