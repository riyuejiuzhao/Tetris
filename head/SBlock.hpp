#pragma once
#ifndef SBLOCK_H
#define SBLOCK_H
#include "Block.hpp"

class SBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;

public:
    ~SBlock();
    SBlock(Background &bg);
    BlockType getType() override;
    void stopMove() override;
};
#endif