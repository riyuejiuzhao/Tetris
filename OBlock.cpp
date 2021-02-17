#include "OBlock.hpp"

void OBlock::printInNow(WINDOW *win)
{
    int x = nowX + BACKGROUND_CEIL - BACKGROUND_HEIGHT, y = nowY;
    char c = ' ';
    wattron(win, COLOR_PAIR(blockColor));
    //四种形态没有区别啊
    mvwaddch(win, x, y, c);
    mvwaddch(win, x, y + 1, c);

    mvwaddch(win, x, y + 2, c);
    mvwaddch(win, x, y + 3, c);

    mvwaddch(win, x + 1, y, c);
    mvwaddch(win, x + 1, y + 1, c);

    mvwaddch(win, x + 1, y + 2, c);
    mvwaddch(win, x + 1, y + 3, c);
    wattroff(win, COLOR_PAIR(blockColor));
}

void OBlock::printInBottom(WINDOW *win)
{
    int x = nowX, y = nowY;
    while (canMoveDown(x, y))
        ++x;
    x += BACKGROUND_CEIL - BACKGROUND_HEIGHT;

    char cl = '[', cr = ']';
    wattron(win, COLOR_PAIR(virtualColor));
    //四种形态没有区别啊
    mvwaddch(win, x, y, cl);
    mvwaddch(win, x, y + 1, cr);

    mvwaddch(win, x, y + 2, cl);
    mvwaddch(win, x, y + 3, cr);

    mvwaddch(win, x + 1, y, cl);
    mvwaddch(win, x + 1, y + 1, cr);

    mvwaddch(win, x + 1, y + 2, cl);
    mvwaddch(win, x + 1, y + 3, cr);
    wattroff(win, COLOR_PAIR(virtualColor));
}

bool OBlock::canMove(int x, int y, BlockDirection d)
{
    return inBackground(x, x + 1, y, y + 3) &&
           bg[x][y].isEmpty() &&
           bg[x][y + 1].isEmpty() &&

           bg[x][y + 2].isEmpty() &&
           bg[x][y + 3].isEmpty() &&

           bg[x + 1][y].isEmpty() &&
           bg[x + 1][y + 1].isEmpty() &&

           bg[x + 1][y + 2].isEmpty() &&
           bg[x + 1][y + 3].isEmpty();
}

OBlock::~OBlock() {}

OBlock::OBlock(Background &bg)
    : Block(bg, BLOCK_YELLOW, BLOCK_VIRTURL_YELLOW)
{
}

BlockType OBlock::getType()
{
    return BlockType::O;
}

void OBlock::doStopMove()
{
    BackgroundPoint temp(blockColor, ' ');
    int x = nowX, y = nowY;
    bg[x][y] = temp;
    bg[x][y + 1] = temp;

    bg[x][y + 2] = temp;
    bg[x][y + 3] = temp;

    bg[x + 1][y] = temp;
    bg[x + 1][y + 1] = temp;

    bg[x + 1][y + 2] = temp;
    bg[x + 1][y + 3] = temp;
}