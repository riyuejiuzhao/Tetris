#include "Block.h"

Block::Block(int x = NEW_BLOCK_X, int y = NEW_BLOCK_Y, BlockDirection d = BlockDirection::LEFT)
    : nowX(x), nowY(y), direction(d)
{
}

LongBlock::LongBlock()
    : Block() {}

void LongBlock::printBlock(Background &bg)
{
    if (direction == BlockDirection::DOWN || direction == BlockDirection::UP)
    {
        bg[nowX][nowY] = '#';
        bg[nowX + 1][nowY] = '#';
        bg[nowX + 2][nowY] = '#';
        bg[nowX + 3][nowY] = '#';
    }
    else 
    {
        bg[nowX][nowY] = '#';
        bg[nowX][nowY+1] = '#';
        bg[nowX][nowY+2] = '#';
        bg[nowX][nowY+3] = '#';
    }
}