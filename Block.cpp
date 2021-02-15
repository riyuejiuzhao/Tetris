#include "Block.hpp"
#include "const.hpp"
#include <unordered_map>
#include <algorithm>

Block::Block(Background &background, int color, int vColor,
             int x, int y, BlockDirection d)
    : bg(background), blockColor(color), virtualColor(vColor), nowX(x), nowY(y), direction(d)
{
}

Block::~Block() {}

void Block::printBlock(WINDOW *win)
{
    printInBottom(win);
    printInNow(win);
}

bool Block::moveDown()
{
    if (!canMoveDown())
        return false;
    nowX += 1;
    return true;
}

bool Block::moveRight()
{
    if (!canMoveRight())
        return false;
    nowY += 2;
    return true;
}

inline bool Block::moveLeft()
{
    if (!canMoveLeft())
        return false;
    nowY -= 2;
    return true;
}

bool Block::move(BlockDirection t)
{
    if (t == BlockDirection::DOWN)
        return moveDown();
    else if (t == BlockDirection::LEFT)
        return moveLeft();
    else if (t == BlockDirection::RIGHT)
        return moveRight();
    return false;
}

void Block::moveToBottom()
{
    while (moveDown())
        ;
}

bool Block::turn(BlockDirection t)
{
    if (t == BlockDirection::LEFT)
        return turnLeft();
    else if (t == BlockDirection::RIGHT)
        return turnRight();
    return false;
}

bool Block::turnLeft()
{
    if (direction == ZERO) // Z -> L
        return originChildTurn(this, ZERO_TO_L, 0, 0, L);
    else if (direction == L) // L -> Two
        return originChildTurn(this, L_TO_TWO, 0, 0, TWO);
    else if (direction == TWO) // Two -> R
        return originChildTurn(this, TWO_TO_R, 0, 0, R);
    else if (direction == R) // R -> Zero
        return originChildTurn(this, R_TO_ZERO, 0, 0, ZERO);
    return false;
}

bool Block::turnRight()
{
    if (direction == ZERO)
        return originChildTurn(this, ZERO_TO_R, 0, 0, R);
    else if (direction == R)
        return originChildTurn(this, R_TO_TWO, 0, 0, TWO);
    else if (direction == TWO)
        return originChildTurn(this, TWO_TO_L, 0, 0, L);
    else if (direction == L)
        return originChildTurn(this, L_TO_ZERO, 0, 0, ZERO);
    return false;
}

bool originGrandChildTurn(Block *t, int to, int index, int ox, int oy, BlockDirection dir)
{
    if (t->canMove(t->nowX + ox + getJLSTZWallKickX(to, index),
                   t->nowY + oy + getJLSTZWallKickY(to, index), dir))
    {
        t->nowX = t->nowX + ox + getJLSTZWallKickX(to, index);
        t->nowY = t->nowY + oy + getJLSTZWallKickY(to, index);
        t->direction = dir;
        return true;
    }
    return false;
}

bool originChildTurn(Block *t, int to, int ox, int oy, BlockDirection dir)
{
    return originGrandChildTurn(t, to, 0, ox, oy, dir) ||
           originGrandChildTurn(t, to, 1, ox, oy, dir) ||
           originGrandChildTurn(t, to, 2, ox, oy, dir) ||
           originGrandChildTurn(t, to, 3, ox, oy, dir) ||
           originGrandChildTurn(t, to, 4, ox, oy, dir);
}