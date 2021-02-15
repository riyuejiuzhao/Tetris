#pragma once
#ifndef LBLOCK_H
#define LBLOCK_H
#include "Block.hpp"

class LBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;

public:
    ~LBlock();
    LBlock(Background &bg);
    BlockType getType() override;
    void stopMove() override;
};
#endif