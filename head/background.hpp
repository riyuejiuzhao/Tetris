#pragma once

#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <stdio.h>
#include <ncurses.h>
#include <memory>
#include "Block.hpp"
#include "const.hpp"
#include <vector>

//同强制声明下
class Block;

class BackgroundPoint
{
    int color;
    char content;

public:
    BackgroundPoint();
    BackgroundPoint(int tColor, char tContent);
    BackgroundPoint(const BackgroundPoint &b);
    //这里，由于char和int都可以用int类型表示，就返回int了
    int operator[](int index);
    BackgroundPoint &operator=(const BackgroundPoint &b);
    bool isEmpty();
};

class Background
{
    std::vector<std::vector<BackgroundPoint>> background;
    //禁止进行拷贝构造和移动构造
    Background &operator=(Background &t);
    Background(Background &t);
    bool isFullLine(int x);
    void removeLine(int x);
public:
    Background();
    ~Background();
    void printBackground(WINDOW *win);
    void removeLines(int x);
    //允许直接操作显示的字符串
    std::vector<BackgroundPoint> &operator[](int i);
};
#endif