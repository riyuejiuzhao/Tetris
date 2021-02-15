#pragma once
#ifndef TBLOCK_H
#define TBLOCK_H
#include "Block.hpp"

class TBlock : public Block
{
    bool canMoveDown() override;
    bool canMoveDown(int x, int y) override;
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMoveRight() override;
    bool canMoveLeft() override;
    bool moveDown() override;
    bool moveRight() override;
    bool moveLeft() override;
    bool canMove(int x, int y, BlockDirection d) override;
    bool turnLeft() override;
    bool turnRight() override;

public:
    ~TBlock();
    TBlock(Background &bg);
    void printBlock(WINDOW *win) override;
    BlockType getType() override;
    void stopMove() override;
    bool move(BlockDirection t) override;
    void moveToBottom() override;
    bool turn(BlockDirection t) override;
};
#endif