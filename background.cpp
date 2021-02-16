#include "background.hpp"
#include "Block.hpp"
#include "const.hpp"

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