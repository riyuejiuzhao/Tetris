#pragma once
#ifndef JBLOCK_H
#define JBLOCK_H
#include "Block.hpp"

class JBlock : public Block
{
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMove(int x, int y, BlockDirection d) override;

public:
    ~JBlock();
    JBlock(Background &bg);
    BlockType getType() override;
    void stopMove() override;
};
#endif