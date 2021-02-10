#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <ncurses.h>
#include "Block.h"
enum
{
    BACKGROUND_HEIGHT = 50, //背景高度
    BACKGROUND_WIDTH = 90, //背景宽度
    BACKGROUND_TOP = 0, //背景距离终端顶端距离
    BACKGROUND_LEFT = 0, //背景距离终端左侧距离
    DEFAULT_CONTENT = ' ', //背景填充
    //新方块的位置
    NEW_BLOCK_X = 0,
    NEW_BLOCK_Y = 0,
};
class Background
{
    char background[BACKGROUND_HEIGHT][BACKGROUND_WIDTH];
    Block *nowBlock;
    void doprintBackground();

public:
    Background();
    void printBackground();
    char *operator[](int i);
    //int getHeight();
    //int getWidth();
    void setNowBlock(Block *b);
};
#endif