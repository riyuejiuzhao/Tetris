#include "TBlock.hpp"

inline bool TBlock::canMoveDown()
{
    return canMoveDown(nowX, nowY);
}

inline bool TBlock::canMoveDown(int x, int y)
{
    return canMove(x + 1, y, direction);
}

void TBlock::printInNow(WINDOW *win)
{
    wattron(win, COLOR_PAIR(blockColor));
    int x = nowX, y = nowY;
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
        mvwaddch(win, x, y - 3, c);

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
        mvwaddch(win, x, y - 3, cR);

        mvwaddch(win, x, y, cL);
        mvwaddch(win, x, y + 1, cR);

        mvwaddch(win, x, y + 2, cL);
        mvwaddch(win, x, y + 3, cR);

        mvwaddch(win, x + 1, y, cL);
        mvwaddch(win, x + 1, y + 1, cR);
    }
    wattroff(win, COLOR_PAIR(blockColor));
}

inline bool TBlock::canMoveRight()
{
    return canMove(nowX, nowY + 2, direction);
}

inline bool TBlock::canMoveLeft()
{
    return canMove(nowX, nowY - 2, direction);
}

bool TBlock::canMove(int x, int y, BlockDirection d)
{
    if (d == ZERO)
        return inBackground(x - 1, x, y - 2, y + 3) &&
               bg[x][y].isEmpty() && bg[x][y + 1].isEmpty() &&
               bg[x - 1][y].isEmpty() && bg[x - 1][y + 1].isEmpty() &&
               bg[x][y - 2].isEmpty() && bg[x][y - 1].isEmpty() &&
               bg[x][y + 2].isEmpty() && bg[x][y + 3].isEmpty();

    else if (direction == L)
        return inBackground(x - 1, x + 1, y - 2, y + 1) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty() &&

               bg[x][y - 2].isEmpty() &&
               bg[x][y - 1].isEmpty();
    else if (direction == R)
        return inBackground(x - 1, x + 1, y, y + 3) &&
               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&

               bg[x - 1][y].isEmpty() &&
               bg[x - 1][y + 1].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty();
    else if (direction == TWO)
        return inBackground(x, x + 1, y - 3, y + 3) &&
               bg[x][y - 2].isEmpty() &&
               bg[x][y - 3].isEmpty() &&

               bg[x][y].isEmpty() &&
               bg[x][y + 1].isEmpty() &&

               bg[x][y + 2].isEmpty() &&
               bg[x][y + 3].isEmpty() &&

               bg[x + 1][y].isEmpty() &&
               bg[x + 1][y + 1].isEmpty();
    else
        return false;
}

inline bool TBlock::moveDown()
{
    if (!canMoveDown())
        return false;
    nowX += 1;
    return true;
}

inline bool TBlock::moveRight()
{
    if (!canMoveRight())
        return false;
    nowY += 2;
    return true;
}

inline bool TBlock::moveLeft()
{
    if (!canMoveLeft())
        return false;
    nowY -= 2;
    return true;
}

inline bool TBlock::turnLeft()
{
    if (direction == ZERO) // Z -> L
        return originChildTurn(this, ZERO_TO_L, 0, 0, L);
    else if (direction == L) // L -> Two
        return originChildTurn(this, L_TO_TWO, 0, 0, TWO);
    else if (direction == TWO) // Two -> R
        return originChildTurn(this, TWO_TO_R, 0, 0, TWO);
    else if (direction == R) // R -> Zero
        return originChildTurn(this, R_TO_ZERO, 0, 0, ZERO);
    return false;
}

inline bool TBlock::turnRight()
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

TBlock::TBlock(Background &background)
    : Block(background, BLOCK_MAGENTA, BLOCK_VIRTURL_MAGENTA) {}

void TBlock::printBlock(WINDOW *win)
{
    printInNow(win);
    printInBottom(win);
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
        bg[x][y - 3] = temp;

        bg[x][y] = temp;
        bg[x][y + 1] = temp;

        bg[x][y + 2] = temp;
        bg[x][y + 3] = temp;

        bg[x + 1][y] = temp;
        bg[x + 1][y + 1] = temp;
    }
}

bool TBlock::move(BlockDirection t)
{
    if (t == BlockDirection::DOWN)
    {
        return moveDown();
    }
    else if (t == BlockDirection::LEFT)
    {
        return moveLeft();
    }
    else if (t == BlockDirection::RIGHT)
    {
        return moveRight();
    }
    return false;
}

inline void TBlock::moveToBottom()
{
    while (moveDown)
        ;
}

bool TBlock::turn(BlockDirection t)
{
    if (t == BlockDirection::LEFT)
        return turnLeft();
    else if (t == BlockDirection::RIGHT)
        return turnRight();
    return false;
}