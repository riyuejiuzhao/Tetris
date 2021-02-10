#pragma once

#ifndef BLOCK_H
#define BLOCK_H
#include "background.h"

enum class BlockDirection
{
    LEFT,
    RIGHT,
    DOWN,
    UP
};

class Block
{
protected:
    int nowX,nowY;
    BlockDirection direction;
public:
    Block(int x,int y,BlockDirection d);
    virtual void printBlock(Background &background) = 0;
    virtual void canMove() = 0;
    virtual void moveDown() = 0;
    virtual void turn() = 0;
    virtual int getType() = 0;
};

class LongBlock : public Block
{
public:
    LongBlock();
    void printBlock(Background &background) override;
    void canMove();
    int getType();
};

#endif