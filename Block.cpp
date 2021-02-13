#include "Block.hpp"
#include "const.hpp"
#include <unordered_map>
#include <algorithm>

std::vector<BlockDirection> turnList{
    BlockDirection::DOWN,
    BlockDirection::RIGHT,
    BlockDirection::UP,
    BlockDirection::LEFT};

Block::Block(Background &background, int color, int vColor,
             int x, int y, BlockDirection d)
    : bg(background), blockColor(color), virtualColor(vColor), nowX(x), nowY(y), direction(d)
{
}

Block::~Block() {}

bool Block::turnLeft()
{
    auto now = std::find(turnList.begin(), turnList.end(), direction);
    if (now == turnList.end() - 1)
        direction = *(turnList.begin());
    else
        direction = *(now + 1);
}

bool Block::turnRight()
{
    auto now = std::find(turnList.begin(), turnList.end(), direction);
    if (now == turnList.begin())
        direction = *turnList.rbegin();
    else
        direction = *(now - 1);
}

bool Block::turn(BlockDirection d)
{
    switch (d)
    {
    case BlockDirection::LEFT:
        return turnLeft();
        break;
    case BlockDirection::RIGHT:
        return turnRight();
        break;
    default:
        break;
    }
    return false;
}
