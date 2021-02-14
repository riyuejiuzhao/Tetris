#include "LongBlock.hpp"

LongBlock::LongBlock(Background &background)
    : Block(background, BLOCK_BLUE, BLOCK_VIRTURL_BLUE, NEW_LONG_BLOCK_X, NEW_LONG_BLOCK_Y) {}

void LongBlock::printBlock(WINDOW *win)
{
    printInBottom(win);
    printInNow(win);
}

inline bool LongBlock::canMoveDown()
{

    return canMoveDown(nowX, nowY);
}

bool LongBlock::canMoveDown(int x, int y)
{
    return canMove(x + 1, y, direction);
}

void LongBlock::printInNow(WINDOW *win)
{
    char blockChar = ' ';
    wattron(win, COLOR_PAIR(blockColor));
    int x = nowX + BACKGROUND_CEIL - BACKGROUND_HEIGHT;
    int y = nowY;
    if (direction == BlockDirection::DOWN)
    {
        mvwaddch(win, x, y - 2, blockChar);
        mvwaddch(win, x, y - 1, blockChar);

        mvwaddch(win, x, y, blockChar);
        mvwaddch(win, x, y + 1, blockChar);

        mvwaddch(win, x, y + 2, blockChar);
        mvwaddch(win, x, y + 3, blockChar);

        mvwaddch(win, x, y + 4, blockChar);
        mvwaddch(win, x, y + 5, blockChar);
    }
    else if (direction == BlockDirection::UP)
    {
        mvwaddch(win, x, y - 5, blockChar);
        mvwaddch(win, x, y - 4, blockChar);

        mvwaddch(win, x, y - 3, blockChar);
        mvwaddch(win, x, y - 2, blockChar);

        mvwaddch(win, x, y - 1, blockChar);
        mvwaddch(win, x, y, blockChar);

        mvwaddch(win, x, y + 1, blockChar);
        mvwaddch(win, x, y + 2, blockChar);
    }
    else if (direction == BlockDirection::RIGHT)
    {
        mvwaddch(win, x - 2, y - 1, blockChar);
        mvwaddch(win, x - 2, y, blockChar);

        mvwaddch(win, x - 1, y - 1, blockChar);
        mvwaddch(win, x - 1, y, blockChar);

        mvwaddch(win, x, y - 1, blockChar);
        mvwaddch(win, x, y, blockChar);

        mvwaddch(win, x + 1, y - 1, blockChar);
        mvwaddch(win, x + 1, y, blockChar);
    }
    else //left
    {
        mvwaddch(win, x - 1, y, blockChar);
        mvwaddch(win, x - 1, y + 1, blockChar);

        mvwaddch(win, x, y, blockChar);
        mvwaddch(win, x, y + 1, blockChar);

        mvwaddch(win, x + 1, y, blockChar);
        mvwaddch(win, x + 1, y + 1, blockChar);

        mvwaddch(win, x + 2, y, blockChar);
        mvwaddch(win, x + 2, y + 1, blockChar);
    }
    wattroff(win, COLOR_PAIR(blockColor));
}

void LongBlock::printInBottom(WINDOW *win)
{
    char blockCharLeft = '[';
    char blockCharRight = ']';
    wattron(win, COLOR_PAIR(virtualColor));
    int x = nowX;
    while (canMoveDown(x, nowY))
    {
        ++x;
    }
    x = x + BACKGROUND_CEIL - BACKGROUND_HEIGHT;
    int y = nowY;

    wattron(win, COLOR_PAIR(BLOCK_VIRTURL_BLUE));
    if (direction == BlockDirection::DOWN)
    {
        mvwaddch(win, x, y - 2, blockCharLeft);
        mvwaddch(win, x, y - 1, blockCharRight);

        mvwaddch(win, x, y, blockCharLeft);
        mvwaddch(win, x, y + 1, blockCharRight);

        mvwaddch(win, x, y + 2, blockCharLeft);
        mvwaddch(win, x, y + 3, blockCharRight);

        mvwaddch(win, x, y + 4, blockCharLeft);
        mvwaddch(win, x, y + 5, blockCharRight);
    }
    else if (direction == BlockDirection::UP)
    {
        mvwaddch(win, x, y - 5, blockCharLeft);
        mvwaddch(win, x, y - 4, blockCharRight);

        mvwaddch(win, x, y - 3, blockCharLeft);
        mvwaddch(win, x, y - 2, blockCharRight);

        mvwaddch(win, x, y - 1, blockCharLeft);
        mvwaddch(win, x, y, blockCharRight);

        mvwaddch(win, x, y + 1, blockCharLeft);
        mvwaddch(win, x, y + 2, blockCharRight);
    }
    else if (direction == BlockDirection::RIGHT)
    {
        mvwaddch(win, x - 2, y - 1, blockCharLeft);
        mvwaddch(win, x - 2, y, blockCharRight);

        mvwaddch(win, x - 1, y - 1, blockCharLeft);
        mvwaddch(win, x - 1, y, blockCharRight);

        mvwaddch(win, x, y - 1, blockCharLeft);
        mvwaddch(win, x, y, blockCharRight);

        mvwaddch(win, x + 1, y - 1, blockCharLeft);
        mvwaddch(win, x + 1, y, blockCharRight);
    }
    else //left
    {
        mvwaddch(win, x - 1, y, blockCharLeft);
        mvwaddch(win, x - 1, y + 1, blockCharRight);

        mvwaddch(win, x, y, blockCharLeft);
        mvwaddch(win, x, y + 1, blockCharRight);

        mvwaddch(win, x + 1, y, blockCharLeft);
        mvwaddch(win, x + 1, y + 1, blockCharRight);

        mvwaddch(win, x + 2, y, blockCharLeft);
        mvwaddch(win, x + 2, y + 1, blockCharRight);
    }
    wattroff(win, COLOR_PAIR(virtualColor));
}

bool LongBlock::moveDown()
{
    if (!canMoveDown())
        return false;
    ++nowX;
    return true;
}

BlockType LongBlock::getType()
{
    return BlockType::Long;
}

LongBlock::~LongBlock() {}

void LongBlock::stopMove()
{
    BackgroundPoint temp(BLOCK_BLUE, ' ');
    int x = nowX, y = nowY;
    if (direction == BlockDirection::DOWN)
    {
        bg[x][y - 2] = temp;
        bg[x][y - 1] = temp;

        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;

        bg[x][y + 4] = temp;
        bg[x][y + 5] = temp;
    }
    else if (direction == BlockDirection::UP)
    {
        bg[x][y - 5] = temp;
        bg[x][y - 4] = temp;

        bg[x][y - 3] = temp;
        bg[x][y - 2] = temp;

        bg[x][y - 1] = temp;
        bg[x][y] = temp;

        bg[x][y + 1] = temp;
        bg[x][y + 2] = temp;
    }
    else if (direction == BlockDirection::RIGHT)
    {
        bg[x - 2][y - 1] = temp;
        bg[x - 2][y] = temp;

        bg[x - 1][y - 1] = temp;
        bg[x - 1][y] = temp;

        bg[x][y - 1] = temp;
        bg[x][y] = temp;

        bg[x + 1][y - 1] = temp;
        bg[x + 1][y] = temp;
    }
    else //left
    {
        bg[x - 1][y] = temp;
        bg[x - 1][y + 1] = temp;

        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;

        bg[x + 2][y] = temp;
        bg[x + 2][y + 1] = temp;
    }
}

bool LongBlock::move(BlockDirection t)
{
    switch (t)
    {
    case BlockDirection::RIGHT:
        return moveRight();
    case BlockDirection::LEFT:
        return moveLeft();
    case BlockDirection::DOWN:
        return moveDown();
    default:
        return false;
        break;
    }
}

bool LongBlock::canMoveRight()
{
    return canMove(nowX, nowY + 2, direction);
}

bool LongBlock::moveRight()
{
    if (!canMoveRight())
        return false;
    nowY += 2;
    return true;
}

bool LongBlock::canMoveLeft()
{
    return canMove(nowX, nowY - 2, direction);
}

bool LongBlock::moveLeft()
{
    if (!canMoveLeft())
        return false;
    nowY -= 2;
    return true;
}

void LongBlock::moveToBottom()
{
    while (moveDown())
        ;
}

inline bool inBackground(int minX, int maxX, int minY, int maxY)
{
    return minX >= 0 && maxX < BACKGROUND_HEIGHT && minX <= maxX &&
           minY >= 0 && maxY < BACKGROUND_WIDTH && minY <= maxY;
}

bool LongBlock::canMove(int x, int y, BlockDirection d)
{
    if (d == BlockDirection::DOWN)
    {
        return inBackground(x, x, y - 2, y + 5) &&
               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty() &&
               //第二个点
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&
               //第三个点
               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&
               //第四个点
               bg[x][y + 4].isEmpty() &&
               bg[x][y + 5].isEmpty();
    }
    else if (d == BlockDirection::UP)
    {
        return inBackground(x, x, y - 4, y + 2) &&
               bg[x][y - 5].isEmpty() &&
               bg[x][y - 4].isEmpty() &&

               bg[x][y - 3].isEmpty() &&
               bg[x][y - 2].isEmpty() &&

               bg[x][y - 1].isEmpty() &&
               bg[x][y].isEmpty() &&

               bg[x][y + 1].isEmpty() &&
               bg[x][y + 2].isEmpty();
    }
    else if (d == BlockDirection::RIGHT)
    {
        return inBackground(x - 2, x + 1, y - 1, y) &&
               bg[x - 2][y - 1].isEmpty() &&
               bg[x - 2][y].isEmpty() &&

               bg[x - 1][y - 1].isEmpty() &&
               bg[x - 1][y].isEmpty() &&

               bg[x][y - 1].isEmpty() &&
               bg[x][y].isEmpty() &&

               bg[x + 1][y - 1].isEmpty() &&
               bg[x + 1][y].isEmpty();
    }
    else //left
    {
        return inBackground(x - 1, x + 2, y, y + 1) &&
               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty() &&

               bg[x + 2][y].isEmpty() &&
               bg[x + 2][y + 1].isEmpty();
    }
}

bool LongBlock::turn(BlockDirection t)
{
    if (t == BlockDirection::LEFT)
        return turnLeft();
    else if (t == BlockDirection::RIGHT)
        return turnRight();
    else
        return false;
}

inline bool LongBlock::childTurn(int to, int ox, int oy, BlockDirection dir)
{
    return grandChildTurn(to, 0, ox, oy, dir) ||
           grandChildTurn(to, 1, ox, oy, dir) ||
           grandChildTurn(to, 2, ox, oy, dir) ||
           grandChildTurn(to, 3, ox, oy, dir) ||
           grandChildTurn(to, 4, ox, oy, dir);
}

inline bool LongBlock::grandChildTurn(int to, int index, int ox, int oy, BlockDirection dir)
{
    if (canMove(nowX + ox + getIWallKickX(to, index),
                nowY + oy + getIWallKickY(to, index), dir))
    {
        nowX = nowX + ox + getIWallKickX(to, index);
        nowY = nowY + oy + getIWallKickY(to, index);
        direction = dir;
        return true;
    }
    return false;
}

bool LongBlock::turnLeft()
{
    int ox, oy;
    if (direction == ZERO)
    {
        ox = 1, oy = 1;
        return childTurn(ZERO_TO_L, ox, oy, L);
    }
    else if (direction == L)
    {
        ox = 0, oy = 2;
        return childTurn(L_TO_TWO, ox, oy, TWO);
    }
    else if (direction == TWO)
    {
        ox = -1, oy = -1;
        return childTurn(TWO_TO_R, ox, oy, TWO);
    }
    else if (direction == R)
    {
        ox = 0, oy = -2;
        return childTurn(R_TO_ZERO, ox, oy, ZERO);
    }
    else
        return false;
}

//由于I块的中心点不在块上，所以会调整nowX，nowY
bool LongBlock::turnRight()
{
    int ox, oy;
    if (direction == ZERO) // 0 -> R
    {
        ox = 0, oy = 2;
        return childTurn(ZERO_TO_R, ox, oy, R);
    }
    else if (direction == L) // L -> 0
    {
        ox = -1, oy = -1;
        return childTurn(L_TO_ZERO, ox, oy, ZERO);
    }
    else if (direction == R) // R -> 2
    {
        ox = 1, oy = 1;
        return childTurn(R_TO_TWO, ox, oy, TWO);
    }
    else if (direction == TWO) // 2 -> L
    {
        ox = 0, oy = -2;
        return childTurn(TWO_TO_L, ox, oy, L);
    }
    else
        return false;
}