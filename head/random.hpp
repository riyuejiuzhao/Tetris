#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#include "Block.hpp"
#include <queue>
#include "IBlock.hpp"
#include "SBlock.hpp"
#include "JBlock.hpp"
#include "LBlock.hpp"
#include "ZBlock.hpp"
#include "OBlock.hpp"
#include "TBlock.hpp"
//用来生成随机的块
class RandomBlock
{
    enum
    {
        I,
        J,
        L,
        O,
        S,
        T,
        Z,
    };

    std::queue<Block *> nowq;
    int nowStatus; //这里我们按位来对应每一个块的有无，从高位到低位分别是ZTSOLJI

    inline bool hasI() { return nowStatus & 1; }
    inline void addI()
    {
        nowq.push(new IBlock(Background::getbg()));
        nowStatus |= 1;
    }
    inline bool hasJ() { return nowStatus & 2; }
    inline void addJ()
    {
        nowq.push(new JBlock(Background::getbg()));
        nowStatus |= 2;
    }
    inline bool hasL() { return nowStatus & 4; }
    inline void addL()
    {
        nowq.push(new LBlock(Background::getbg()));
        nowStatus |= 4;
    }
    inline bool hasO() { return nowStatus & 8; }
    inline void addO()
    {
        nowq.push(new OBlock(Background::getbg()));
        nowStatus |= 8;
    }
    inline bool hasS() { return nowStatus & 16; }
    inline void addS()
    {
        nowq.push(new SBlock(Background::getbg()));
        nowStatus |= 16;
    }
    inline bool hasT() { return nowStatus & 32; }
    inline void addT()
    {
        nowq.push(new TBlock(Background::getbg()));
        nowStatus |= 32;
    }
    inline bool hasZ() { return nowStatus & 64; }
    inline void addZ()
    {
        nowq.push(new ZBlock(Background::getbg()));
        nowStatus |= 64;
    }
    inline bool hasAll() { return nowStatus & 127; }

    void generateNewSequence();

public:
    RandomBlock();
    Block *getNext();
};

#endif