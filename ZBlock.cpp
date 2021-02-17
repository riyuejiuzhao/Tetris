#include "ZBlock.hpp"

ZBlock::ZBlock(Background &background)
    : Block(background, BLOCK_RED, BLOCK_VIRTUAL_RED) {}

ZBlock::~ZBlock() {}

void ZBlock::printInNow(WINDOW *win)
{
    wattron(win, COLOR_PAIR(blockColor));
    int x = nowX + BACKGROUND_CEIL - BACKGROUND_HEIGHT, y = nowY;
    char c = ' ';
    if (direction == ZERO)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x, y + 2, c);
        mvwaddch(win, x, y + 3, c);

        mvwaddch(win, x - 1, y, c);
        mvwaddch(win, x - 1, y + 1, c);

        mvwaddch(win, x - 1, y - 2, c);
        mvwaddch(win, x - 1, y - 1, c);
    }
    else if (direction == R)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x, y + 2, c);
        mvwaddch(win, x, y + 3, c);

        mvwaddch(win, x + 1, y, c);
        mvwaddch(win, x + 1, y + 1, c);

        mvwaddch(win, x - 1, y + 2, c);
        mvwaddch(win, x - 1, y + 3, c);
    }
    else if (direction == TWO)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x, y - 2, c);
        mvwaddch(win, x, y - 1, c);

        mvwaddch(win, x + 1, y, c);
        mvwaddch(win, x + 1, y + 1, c);

        mvwaddch(win, x + 1, y + 2, c);
        mvwaddch(win, x + 1, y + 3, c);
    }
    else if (direction == L)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x, y - 2, c);
        mvwaddch(win, x, y - 1, c);

        mvwaddch(win, x - 1, y, c);
        mvwaddch(win, x - 1, y + 1, c);

        mvwaddch(win, x + 1, y - 2, c);
        mvwaddch(win, x + 1, y - 1, c);
    }
    wattroff(win, COLOR_PAIR(blockColor));
}

void ZBlock::printInBottom(WINDOW *win)
{
    wattron(win, COLOR_PAIR(virtualColor));
    int y = nowY;
    int x = nowX;
    while (canMoveDown(x, y))
        ++x;
    x = x + BACKGROUND_CEIL - BACKGROUND_HEIGHT;
    char cl = '[', cr = ']';
    if (direction == ZERO)
    {
        mvwaddch(win, x, y, cl);
        mvwaddch(win, x, y + 1, cr);

        mvwaddch(win, x, y + 2, cl);
        mvwaddch(win, x, y + 3, cr);

        mvwaddch(win, x - 1, y, cl);
        mvwaddch(win, x - 1, y + 1, cr);

        mvwaddch(win, x - 1, y - 2, cl);
        mvwaddch(win, x - 1, y - 1, cr);
    }
    else if (direction == R)
    {
        mvwaddch(win, x, y, cl);
        mvwaddch(win, x, y + 1, cr);

        mvwaddch(win, x, y + 2, cl);
        mvwaddch(win, x, y + 3, cr);

        mvwaddch(win, x + 1, y, cl);
        mvwaddch(win, x + 1, y + 1, cr);

        mvwaddch(win, x - 1, y + 2, cl);
        mvwaddch(win, x - 1, y + 3, cr);
    }
    else if (direction == TWO)
    {
        mvwaddch(win, x, y, cl);
        mvwaddch(win, x, y + 1, cr);

        mvwaddch(win, x, y - 2, cl);
        mvwaddch(win, x, y - 1, cr);

        mvwaddch(win, x + 1, y, cl);
        mvwaddch(win, x + 1, y + 1, cr);

        mvwaddch(win, x + 1, y + 2, cl);
        mvwaddch(win, x + 1, y + 3, cr);
    }
    else if (direction == L)
    {
        mvwaddch(win, x, y, cl);
        mvwaddch(win, x, y + 1, cr);

        mvwaddch(win, x, y - 2, cl);
        mvwaddch(win, x, y - 1, cr);

        mvwaddch(win, x - 1, y, cl);
        mvwaddch(win, x - 1, y + 1, cr);

        mvwaddch(win, x + 1, y - 2, cl);
        mvwaddch(win, x + 1, y - 1, cr);
    }
    wattroff(win, COLOR_PAIR(virtualColor));
}

bool ZBlock::canMove(int x, int y, BlockDirection d)
{
    if (d == ZERO)
    {
        return inBackground(x - 1, x, y - 2, y + 3) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x - 1][y - 2].isEmpty() &&
               bg[x - 1][y - 1].isEmpty();
    }
    else if (d == R)
    {
        return inBackground(x - 1, x, y, y + 3) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty() &&

               bg[x - 1][y + 2].isEmpty() &&
               bg[x - 1][y + 3].isEmpty();
    }
    else if (d == TWO)
    {
        return inBackground(x, x + 1, y - 2, y + 3) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty() &&

               bg[x + 1][y + 2].isEmpty() &&
               bg[x + 1][y + 3].isEmpty();
    }
    else if (d == L)
    {
        return inBackground(x - 1, x + 1, y - 2, y + 1) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x + 1][y - 2].isEmpty() &&
               bg[x + 1][y - 1].isEmpty();
    }
    return false;
}

BlockType ZBlock::getType()
{
    return BlockType::Z;
}

void ZBlock::doStopMove()
{
    BackgroundPoint temp(blockColor, ' ');
    int x = nowX, y = nowY;
    if (direction == ZERO)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;

        bg[x - 1][y] = temp;
        bg[x - 1][y + 1] = temp;

        bg[x - 1][y - 2] = temp;
        bg[x - 1][y - 1] = temp;
    }
    else if (direction == R)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;

        bg[x - 1][y + 2] = temp;
        bg[x - 1][y + 3] = temp;
    }
    else if (direction == TWO)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y - 2] = temp;
        bg[x][y - 1] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;

        bg[x + 1][y + 2] = temp;
        bg[x + 1][y + 3] = temp;
    }
    else if (direction == L)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y - 2] = temp;
        bg[x][y - 1] = temp;

        bg[x - 1][y] = temp;
        bg[x - 1][y + 1] = temp;

        bg[x + 1][y - 2] = temp;
        bg[x + 1][y - 1] = temp;
    }
}
