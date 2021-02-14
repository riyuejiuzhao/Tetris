#pragma once

#ifndef BLOCK_H
#define BLOCK_H
#include "background.hpp"
#include "const.hpp"

//相互包含的关系，这样强制声明一下
class Background;

//这里，方向是指的，相对于中心点，主体的方向
enum class BlockDirection
{
    DOWN,
    LEFT,
    UP,
    RIGHT,
};
enum class BlockType
{
    Long
};

class Block
{
protected:
    Background &bg;
    int blockColor;
    int virtualColor;
    int nowX, nowY;
    BlockDirection direction;
    Block(Background &background, int color, int virtualColor,
          int x = NEW_BLOCK_X, int y = NEW_BLOCK_Y,
          BlockDirection d = BlockDirection::DOWN);
    inline virtual bool canMoveDown() = 0;
    virtual bool canMoveDown(int x, int y) = 0;
    virtual void printInNow(WINDOW *win) = 0;
    virtual void printInBottom(WINDOW *win) = 0;
    virtual bool canMoveRight() = 0;
    virtual bool canMoveLeft() = 0;
    virtual bool moveDown() = 0;
    virtual bool moveRight() = 0;
    virtual bool moveLeft() = 0;
    virtual bool canMove(int x, int y,BlockDirection d) = 0;
    virtual bool turnLeft() = 0;
    virtual bool turnRight() = 0;

public:
    virtual ~Block();
    virtual void printBlock(WINDOW *win) = 0;
    virtual bool move(BlockDirection t) = 0;
    virtual void moveToBottom() = 0;
    virtual bool turn(BlockDirection d) = 0;
    virtual BlockType getType() = 0;
    virtual void stopMove() = 0; //写入背景
    //两个用来debug的函数
    int getX() { return nowX; }
    int getY() { return nowY; }
    std::string getDirection()
    {
        switch (direction)
        {
        case BlockDirection::LEFT:
            return "left";
        case BlockDirection::RIGHT:
            return "right";
        case BlockDirection::UP:
            return "up";
        case BlockDirection::DOWN:
            return "down";
        default:
            return "void";
        }
    }
};

class LongBlock : public Block
{
    inline bool canMoveDown() override;
    bool canMoveDown(int x, int y) override;
    void printInNow(WINDOW *win) override;
    void printInBottom(WINDOW *win) override;
    bool canMoveRight() override;
    bool canMoveLeft() override;
    bool moveDown() override;
    bool moveRight() override;
    bool moveLeft() override;
    bool canMove(int x, int y,BlockDirection d) override;
    bool turnLeft() override;
    bool turnRight() override;

public:
    ~LongBlock();
    LongBlock(Background &bg);
    void printBlock(WINDOW *win) override;
    BlockType getType() override;
    void stopMove() override;
    bool move(BlockDirection t) override;
    void moveToBottom() override;
    bool turn(BlockDirection t) override;
};

#endif