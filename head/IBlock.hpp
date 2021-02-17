#pragma once
#ifndef LONGBLOCK_H
#define LONGBLOCK_H
#include "Block.hpp"

class IBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;
    bool turnLeft() override;
    bool turnRight() override;
    //辅助函数用来实现turn的
    bool grandChildTurn(int to, int index, int ox, int oy, BlockDirection dir);
    bool childTurn(int to, int ox, int oy, BlockDirection dir);

public:
    ~IBlock();
    IBlock(Background &bg);
    BlockType getType() override;
    void doStopMove() override;
};
#endif