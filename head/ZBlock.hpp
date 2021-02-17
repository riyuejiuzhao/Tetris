#pragma once
#ifndef ZBLOCK_H
#define ZBLOCK_H
#include "Block.hpp"

class ZBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;

public:
    ~ZBlock();
    ZBlock(Background &bg);
    BlockType getType() override;
    void doStopMove() override;
};
#endif