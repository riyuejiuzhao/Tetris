#include "Block.hpp"

LongBlock::LongBlock(Background &background)
    : Block(background, BLOCK_BLUE, BLOCK_VIRTURL_BLUE,NEW_LONG_BLOCK_X,NEW_LONG_BLOCK_Y) {}

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
    return canMove(x + 1, y);
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
        mvwaddch(win, x - 5, y, blockChar);
        mvwaddch(win, x - 4, y, blockChar);

        mvwaddch(win, x - 3, y, blockChar);
        mvwaddch(win, x - 2, y, blockChar);

        mvwaddch(win, x - 1, y, blockChar);
        mvwaddch(win, x, y, blockChar);

        mvwaddch(win, x + 1, y, blockChar);
        mvwaddch(win, x + 2, y, blockChar);
    }
    else //left
    {
        mvwaddch(win, x - 2, y, blockChar);
        mvwaddch(win, x - 1, y, blockChar);

        mvwaddch(win, x, y, blockChar);
        mvwaddch(win, x + 1, y, blockChar);

        mvwaddch(win, x + 2, y, blockChar);
        mvwaddch(win, x + 3, y, blockChar);

        mvwaddch(win, x + 4, y, blockChar);
        mvwaddch(win, x + 5, y, blockChar);
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
        mvwaddch(win, x - 5, y, blockCharLeft);
        mvwaddch(win, x - 4, y, blockCharRight);

        mvwaddch(win, x - 3, y, blockCharLeft);
        mvwaddch(win, x - 2, y, blockCharRight);

        mvwaddch(win, x - 1, y, blockCharLeft);
        mvwaddch(win, x, y, blockCharRight);

        mvwaddch(win, x + 1, y, blockCharLeft);
        mvwaddch(win, x + 2, y, blockCharRight);
    }
    else //left
    {
        mvwaddch(win, x - 2, y, blockCharLeft);
        mvwaddch(win, x - 1, y, blockCharRight);

        mvwaddch(win, x, y, blockCharLeft);
        mvwaddch(win, x + 1, y, blockCharRight);

        mvwaddch(win, x + 2, y, blockCharLeft);
        mvwaddch(win, x + 3, y, blockCharRight);

        mvwaddch(win, x + 4, y, blockCharLeft);
        mvwaddch(win, x + 5, y, blockCharRight);
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
        bg[x - 5][y] = temp;
        bg[x - 4][y] = temp;

        bg[x - 3][y] = temp;
        bg[x - 2][y] = temp;

        bg[x - 1][y] = temp;
        bg[x][y] = temp;

        bg[x][y + 1] = temp;
        bg[x][y + 2] = temp;
    }
    else //left
    {
        bg[x - 2][y] = temp;
        bg[x - 1][y] = temp;

        bg[x][y] = temp;
        bg[x + 1][y] = temp;

        bg[x + 2][y] = temp;
        bg[x + 3][y] = temp;

        bg[x + 4][y] = temp;
        bg[x + 5][y] = temp;
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
    return canMove(nowX, nowY + 2);
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
    return canMove(nowX, nowY - 2);
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

bool LongBlock::canMove(int x, int y)
{
    if (direction == BlockDirection::DOWN)
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
    else if (direction == BlockDirection::UP)
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
    else if (direction == BlockDirection::RIGHT)
    {
        return inBackground(x - 5, x + 2, y, y) &&
               bg[x - 5][y].isEmpty() &&
               bg[x - 4][y].isEmpty() &&

               bg[x - 3][y].isEmpty() &&
               bg[x - 2][y].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x][y].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 2][y].isEmpty();
    }
    else //left
    {
        return inBackground(x - 2, x + 5, y, y) &&
               bg[x - 2][y].isEmpty() &&
               bg[x - 1][y].isEmpty() &&

               bg[x][y].isEmpty() &&
               bg[x + 1][y].isEmpty() &&

               bg[x + 2][y].isEmpty() &&
               bg[x + 3][y].isEmpty() &&

               bg[x + 4][y].isEmpty() &&
               bg[x + 5][y].isEmpty();
    }
}