#pragma once
#ifndef OBLOCK_H
#define OBLOCK_H
#include "Block.hpp"

class OBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;

public:
    ~OBlock();
    OBlock(Background &bg);
    BlockType getType() override;
    void stopMove() override;
};
#endif

