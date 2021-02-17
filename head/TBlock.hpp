#pragma once
#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.hpp"

class TBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;

public:
    ~TBlock();
    TBlock(Background &bg);
    BlockType getType() override;
    void doStopMove() override;
};
#endif