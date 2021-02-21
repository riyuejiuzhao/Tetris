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
    DOWN,  //0
    LEFT,  //R
    RIGHT, //L
    UP,    //2
};
enum class BlockType
{
    I,
    T,
    J,
    L,
    O,
    S,
    Z,
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
    inline bool canMoveDown(int x, int y) { return canMove(x + 1, y, direction); }
    inline bool canMoveRight() { return canMove(nowX, nowY + 2, direction); }
    inline bool canMoveLeft() { return canMove(nowX, nowY - 2, direction); }
    bool moveDown();
    bool moveRight();
    bool moveLeft();
    virtual void printInNow(WINDOW *win) = 0;
    virtual void printInBottom(WINDOW *win) = 0;
    virtual bool canMove(int x, int y, BlockDirection d) = 0;
    virtual void doStopMove() = 0;
    //这两个函数I型需要重置，别的不需要
    virtual bool turnLeft();
    virtual bool turnRight();

public:
    virtual ~Block();
    void printBlock(WINDOW *win);
    bool move(BlockDirection t);
    void moveToBottom();
    bool turn(BlockDirection d);
    inline bool canMoveDown() { return canMoveDown(nowX, nowY); }

    virtual BlockType getType() = 0;
    void stopMove(); //写入背景

    //辅助函数用来实现turn的, I型块用自己的，其余的用这个
    friend bool originGrandChildTurn(Block *t, int to, int index, int ox, int oy, BlockDirection dir);
    friend bool originChildTurn(Block *t, int to, int ox, int oy, BlockDirection dir);

    inline int getX() { return nowX; }
    inline int getY() { return nowY; }
    inline std::string getDirection()
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

bool originGrandChildTurn(Block *t, int to, int index, int ox, int oy, BlockDirection dir);
bool originChildTurn(Block *t, int to, int ox, int oy, BlockDirection dir);

//为了用来旋转，定义的常量
//由于之前设置的和 俄罗斯方块规则中的不一样，所以重新定义一下
const BlockDirection ZERO = BlockDirection::DOWN;
const BlockDirection L = BlockDirection::RIGHT;
const BlockDirection R = BlockDirection::LEFT;
const BlockDirection TWO = BlockDirection::UP;

const int JLSTZBlockWillKicks[8][5][2] =
    {
        {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},
        {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},
        {{0, 0}, {1, 0}, {1, -1}, {0, 2}, {1, 2}},
        {{0, 0}, {-1, 0}, {-1, 1}, {0, -2}, {-1, -2}},
        {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},
        {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},
        {{0, 0}, {-1, 0}, {-1, -1}, {0, 2}, {-1, 2}},
        {{0, 0}, {1, 0}, {1, 1}, {0, -2}, {1, -2}},
};

const int IBlockWillKicks[8][5][2] =
    {
        {{0, 0}, {-2, 0}, {1, 0}, {-2, -1}, {1, 2}}, //0->R
        {{0, 0}, {2, 0}, {-1, 0}, {2, 1}, {-1, -2}}, //R->0
        {{0, 0}, {-1, 0}, {2, 0}, {-1, 2}, {2, -1}}, //R->2
        {{0, 0}, {1, 0}, {-2, 0}, {1, -2}, {-2, 1}}, //2->R
        {{0, 0}, {2, 0}, {-1, 0}, {2, 1}, {-1, -2}}, //2->L
        {{0, 0}, {-2, 0}, {1, 0}, {-2, -1}, {1, 2}}, //L->2
        {{0, 0}, {1, 0}, {-2, 0}, {1, -2}, {-2, 1}}, //L->0
        {{0, 0}, {-1, 0}, {2, 0}, {-1, 2}, {2, -1}}, //0->L
};

inline int getIWallKickX(int d, int i)
{
    return IBlockWillKicks[d][i][1];
}

inline int getIWallKickY(int d, int i) { return IBlockWillKicks[d][i][0] * 2; }

inline int getJLSTZWallKickX(int d, int i) { return JLSTZBlockWillKicks[d][i][1]; }

inline int getJLSTZWallKickY(int d, int i) { return JLSTZBlockWillKicks[d][i][0] * 2; }

inline bool inBackground(int minX, int maxX, int minY, int maxY)
{
    return minX >= 0 && maxX < BACKGROUND_HEIGHT && minX <= maxX &&
           minY >= 0 && maxY < BACKGROUND_WIDTH && minY <= maxY;
}

#endif