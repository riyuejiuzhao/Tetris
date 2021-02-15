#include "TBlock.hpp"

TBlock::TBlock(Background &background)
    : Block(background, BLOCK_MAGENTA, BLOCK_VIRTURL_MAGENTA, NEW_LONG_BLOCK_X, NEW_LONG_BLOCK_Y) {}

TBlock::~TBlock() {}

void TBlock::printInNow(WINDOW *win)
{
    wattron(win, COLOR_PAIR(blockColor));
    int x = nowX + BACKGROUND_CEIL - BACKGROUND_HEIGHT, y = nowY;
    char c = ' ';
    if (direction == ZERO)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x - 1, y, c);
        mvwaddch(win, x - 1, y + 1, c);

        mvwaddch(win, x, y - 2, c);
        mvwaddch(win, x, y - 1, c);

        mvwaddch(win, x, y + 2, c);
        mvwaddch(win, x, y + 3, c);
    }
    else if (direction == L)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x - 1, y, c);
        mvwaddch(win, x - 1, y + 1, c);

        mvwaddch(win, x + 1, y, c);
        mvwaddch(win, x + 1, y + 1, c);

        mvwaddch(win, x, y - 2, c);
        mvwaddch(win, x, y - 1, c);
    }
    else if (direction == R)
    {
        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x, y + 2, c);
        mvwaddch(win, x, y + 3, c);

        mvwaddch(win, x - 1, y, c);
        mvwaddch(win, x - 1, y + 1, c);

        mvwaddch(win, x + 1, y, c);
        mvwaddch(win, x + 1, y + 1, c);
    }
    else if (direction == TWO)
    {
        mvwaddch(win, x, y - 2, c);
        mvwaddch(win, x, y - 1, c);

        mvwaddch(win, x, y, c);
        mvwaddch(win, x, y + 1, c);

        mvwaddch(win, x, y + 2, c);
        mvwaddch(win, x, y + 3, c);

        mvwaddch(win, x + 1, y, c);
        mvwaddch(win, x + 1, y + 1, c);
    }
    wattroff(win, COLOR_PAIR(blockColor));
}

void TBlock::printInBottom(WINDOW *win)
{
    wattron(win, COLOR_PAIR(virtualColor));
    int y = nowY;
    int x = nowX;
    while (canMoveDown(x, y))
        ++x;
    x = x + BACKGROUND_CEIL - BACKGROUND_HEIGHT;
    char cL = '[', cR = ']';
    if (direction == ZERO)
    {
        mvwaddch(win, x, y, cL);
        mvwaddch(win, x, y + 1, cR);

        mvwaddch(win, x - 1, y, cL);
        mvwaddch(win, x - 1, y + 1, cR);

        mvwaddch(win, x, y - 2, cL);
        mvwaddch(win, x, y - 1, cR);

        mvwaddch(win, x, y + 2, cL);
        mvwaddch(win, x, y + 3, cR);
    }
    else if (direction == L)
    {
        mvwaddch(win, x, y, cL);
        mvwaddch(win, x, y + 1, cR);

        mvwaddch(win, x - 1, y, cL);
        mvwaddch(win, x - 1, y + 1, cR);

        mvwaddch(win, x + 1, y, cL);
        mvwaddch(win, x + 1, y + 1, cR);

        mvwaddch(win, x, y - 2, cL);
        mvwaddch(win, x, y - 1, cR);
    }
    else if (direction == R)
    {
        mvwaddch(win, x, y, cL);
        mvwaddch(win, x, y + 1, cR);

        mvwaddch(win, x, y + 2, cL);
        mvwaddch(win, x, y + 3, cR);

        mvwaddch(win, x - 1, y, cL);
        mvwaddch(win, x - 1, y + 1, cR);

        mvwaddch(win, x + 1, y, cL);
        mvwaddch(win, x + 1, y + 1, cR);
    }
    else if (direction == TWO)
    {
        mvwaddch(win, x, y - 2, cL);
        mvwaddch(win, x, y - 1, cR);

        mvwaddch(win, x, y, cL);
        mvwaddch(win, x, y + 1, cR);

        mvwaddch(win, x, y + 2, cL);
        mvwaddch(win, x, y + 3, cR);

        mvwaddch(win, x + 1, y, cL);
        mvwaddch(win, x + 1, y + 1, cR);
    }
    wattroff(win, COLOR_PAIR(virtualColor));
}

bool TBlock::canMove(int x, int y, BlockDirection d)
{
    if (d == ZERO)
        return inBackground(x - 1, x, y - 2, y + 3) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty();

    else if (d == L)
        return inBackground(x - 1, x + 1, y - 2, y + 1) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty() &&

               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty();
    else if (d == R)
        return inBackground(x - 1, x + 1, y, y + 3) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty();
    else if (d == TWO)
        return inBackground(x, x + 1, y - 3, y + 3) &&
               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty() &&

               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty();
    else
        return false;
}

BlockType TBlock::getType()
{
    return BlockType::T;
}

void TBlock::stopMove()
{
    BackgroundPoint temp(blockColor, ' ');
    int x = nowX, y = nowY;
    if (direction == ZERO)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x - 1][y] = temp;
        bg[x - 1][y + 1] = temp;

        bg[x][y - 2] = temp;
        bg[x][y - 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;
    }
    else if (direction == L)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x - 1][y] = temp;
        bg[x - 1][y + 1] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;

        bg[x][y - 2] = temp;
        bg[x][y - 1] = temp;
    }
    else if (direction == R)
    {
        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;

        bg[x - 1][y] = temp;
        bg[x - 1][y + 1] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;
    }
    else if (direction == TWO)
    {
        bg[x][y - 2] = temp;
        bg[x][y - 1] = temp;

        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;
    }
}
