#include "background.h"

Background::Background() : nowBlock(nullptr)
{
    for (int i = 0; i < BACKGROUND_HEIGHT; ++i)
    {
        for (int j = 0; j < BACKGROUND_WIDTH; ++j)
        {
            background[i][j] = DEFAULT_CONTENT;
        }
    }
}
void Background::printBackground()
{
    nowBlock->printBlock(*this);
    doprintBackground();
    refresh();
}
void Background::doprintBackground()
{
    for (int i = 0; i < BACKGROUND_HEIGHT; ++i)
    {
        for (int j = 0; j < BACKGROUND_WIDTH; ++j)
        {
            mvaddch(i + BACKGROUND_TOP, j + BACKGROUND_LEFT, background[i][j]);
        }
    }
}

char *Background::operator[](int i) { return background[i]; }
int Background::getHeight() { return BACKGROUND_HEIGHT; }
int Background::getWidth() { return BACKGROUND_WIDTH; }
void Background::setNowBlock(Block *b) { nowBlock = b; };
