//
//  Block.h
//  Daeuntetris
//
//  Created by daeun on 21/05/2017.
//  Copyright © 2017 daeun. All rights reserved.
//

#ifndef Block_h
#define Block_h

class Block{
private:
    int x;
    int y;
    int rotation_num;
public:
    Block():x(5), y(0), rotation_num(0) {}
    int get_x() const ;
    int get_y() const ;
    int get_rotation_num() const ;
    void update_x(int _input);
    void update_y(int _input);
    void update_rotation_num(int _input);
    virtual const int get_shape(const int&, const int&) const {return 0;}
};

class tetrimino_0:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_0();
};

class tetrimino_1:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_1();
};

class tetrimino_2:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_2();
};

class tetrimino_3:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_3();
};

class tetrimino_4:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_4();
};

class tetrimino_5:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_5();
};

class tetrimino_6:public Block
{
private:
    int block_shape[4][4][4];
public:
    virtual const int get_shape(const int& x, const int& y) const ;
    tetrimino_6();
    
};


#endif /* Block_h */
