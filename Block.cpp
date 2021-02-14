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
