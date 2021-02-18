#include "background.hpp"
#include "Block.hpp"
#include "const.hpp"

Background& Background::getbg()
{
    static Background* bg = nullptr;
    if(bg == nullptr)
    {
        bg = new Background();
    }
    return *bg;
}

Background::Background()
{
    for (int i = 0; i < BACKGROUND_HEIGHT; ++i)
    {
        background.push_back({});
        for (int j = 0; j < BACKGROUND_WIDTH; ++j)
        {
            background[i].push_back(BackgroundPoint());
        }
    }
}

Background::~Background()
{
}

void Background::printBackground(WINDOW *win)
{
    for (int i = BACKGROUND_HEIGHT - BACKGROUND_CEIL; i < BACKGROUND_HEIGHT; ++i)
    {
        for (int j = 0; j < BACKGROUND_WIDTH; ++j)
        {
            BackgroundPoint &temp = background[i][j];
            wattron(win, COLOR_PAIR(temp[1]));
            mvwaddch(win, i - BACKGROUND_CEIL, j, temp[0]);
            wattroff(win, COLOR_PAIR(temp[1]));
        }
    }
}

std::vector<BackgroundPoint> &Background::operator[](int i)
{
    if (i >= BACKGROUND_HEIGHT)
    {
        return background[BACKGROUND_HEIGHT - 1];
    }
    else if (i < 0)
    {
        return background[0];
    }
    return background[i];
}

bool Background::isFullLine(int x)
{
    for (auto i = background[x].begin(); i != background[x].end(); ++i)
    {
        if ((*i).isEmpty())
            return false;
    }
    return true;
}

void Background::removeLine(int x)
{
    for (; x >= 1; --x)
    {
        background[x] = background[x - 1];
    }
}

void Background::removeLines(int x) //这里x是方块的中心坐标，所以最大删除范围是[x-2,x+2]
{
    int i = x - 2;
    for (; i <= x + 2 && i < BACKGROUND_HEIGHT; ++i)
    {
        if (isFullLine(i))
            removeLine(i);
    }
}