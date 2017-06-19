//
//  block.cpp
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#include "Block.h"
#include <memory>
#include <iostream>
#include <string.h>
#include <ctime>

int Block::get_x()const {
    return x;
}

int Block::get_y()const {
    return y;
}
int Block::get_rotation_num()const {
    return rotation_num;
}
void Block:: update_x(int _input){
    x += _input;
}
void Block:: update_y(int _input){
    y += _input;
}
void Block:: update_rotation_num(int _input){
    rotation_num += _input;
    rotation_num += 4;
    rotation_num %= 4;
}

tetrimino_0::tetrimino_0():Block(){
    int tettblock[4][4][4] =
    
    { { { 1, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } },
        
        { { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 1, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, sizeof(int)*4*4*4);
}

const int tetrimino_0 :: get_shape(const int& x, const int& y) const{
    return block_shape[get_rotation_num()][y][x];
}


tetrimino_1::tetrimino_1():Block(){
    int tettblock[4][4][4] =
    
    { { { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 0, 0 } },
        
        { { 0, 0, 1, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 1, 0, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, (sizeof(int)*4*4*4));
}

const int tetrimino_1 :: get_shape(const int& x, const int& y) const{
    return block_shape[get_rotation_num()][y][x];
}


tetrimino_2::tetrimino_2():Block(){
    int tettblock[4][4][4] =
    
    { { { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 0, 0, 0, 0 } },
        
        { { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 1, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, sizeof(int)*4*4*4);
}

const int tetrimino_2 :: get_shape(const int& x, const int& y) const{
    return block_shape[get_rotation_num()][y][x];
}



tetrimino_3::tetrimino_3():Block(){
    int tettblock[4][4][4] =
    
    { { { 0, 1, 0, 0 },
        { 0, 1, 1, 0 },
        { 0, 0, 1, 0 },
        { 0, 0, 0, 0 } },
        
        { { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 1, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 1, 1, 0 },
            { 1, 1, 0, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, sizeof(int)*4*4*4);
}

const int tetrimino_3 :: get_shape(const int& x, const int& y) const{
    return block_shape[get_rotation_num()][y][x];
}



tetrimino_4::tetrimino_4():Block(){
    int tettblock[4][4][4] =
    
    {{ { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
        { 1, 0, 0, 0 },
        { 0, 0, 0, 0 } },
        
        { { 1, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 1, 0, 0 },
            { 1, 1, 0, 0 },
            { 1, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 1, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, (sizeof(int)*4*4*4));
}

const int tetrimino_4 :: get_shape(const int& x, const int& y) const{
    return block_shape[get_rotation_num()][y][x];
}

tetrimino_5::tetrimino_5():Block(){
    int tettblock[4][4][4] =
    { { { 0, 1, 0, 0 },
        { 1, 1, 1, 0 },
        { 0, 0, 0, 0 },
        { 0, 0, 0, 0 } },
        
        { { 0, 1, 0, 0 },
        { 1, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 0, 0, 0 },
            { 1, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 1, 0, 0 },
            { 0, 1, 1, 0 },
            { 0, 1, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, (sizeof(int)*4*4*4));
}

const int tetrimino_5 :: get_shape(const int& x, const int& y) const{
    return block_shape[get_rotation_num()][y][x];
}


tetrimino_6::tetrimino_6():Block(){
    int tettblock[4][4][4] =
    
    { { { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 },
        { 0, 1, 0, 0 } },
        
        { { 0, 0, 0, 0 },
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } },
        
        { { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 },
            { 0, 1, 0, 0 } },
        
        { { 0, 0, 0, 0 },
            { 1, 1, 1, 1 },
            { 0, 0, 0, 0 },
            { 0, 0, 0, 0 } } };
    memcpy(block_shape, tettblock, (sizeof(int)*4*4*4));
}

const int tetrimino_6 :: get_shape(const int& x, const int& y) const {
    return block_shape[get_rotation_num()][y][x];
}



