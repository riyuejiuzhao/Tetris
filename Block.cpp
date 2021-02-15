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

inline bool originGrandChildTurn(Block *t, int to, int index, int ox, int oy, BlockDirection dir)
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

inline bool originChildTurn(Block *t, int to, int ox, int oy, BlockDirection dir)
{
    return originGrandChildTurn(t, to, 0, ox, oy, dir) ||
           originGrandChildTurn(t, to, 1, ox, oy, dir) ||
           originGrandChildTurn(t, to, 2, ox, oy, dir) ||
           originGrandChildTurn(t, to, 3, ox, oy, dir) ||
           originGrandChildTurn(t, to, 4, ox, oy, dir);
}