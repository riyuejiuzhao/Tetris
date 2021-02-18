#include "random.hpp"
#include <cstdlib>
#include <algorithm>

RandomBlock::RandomBlock()
    : nowStatus(0)
{
}

void RandomBlock::generateNewSequence()
{
    srand(time(0));
    while (nowq.size() < 7)
    {
        int r = rand() % (7 - nowq.size());
        int is = 0;
        if (!hasI())
        {
            if (is == r)
            {
                addI();
                continue;
            }
            ++is;
        }
        if (!hasJ())
        {
            if (is == r)
            {
                addJ();
                continue;
            }
            ++is;
        }
        if (!hasL())
        {
            if (is == r)
            {
                addL();
                continue;
            }
            ++is;
        }
        if (!hasO())
        {
            if (is == r)
            {
                addO();
                continue;
            }
            ++is;
        }
        if (!hasS())
        {
            if (is == r)
            {
                addS();
                continue;
            }
            ++is;
        }
        if (!hasT())
        {
            if (is == r)
            {
                addT();
                continue;
            }
            ++is;
        }
        if (!hasZ())
        {
            if (is == r)
            {
                addZ();
                continue;
            }
            ++is;
        }
    }
}

Block *RandomBlock::getNext()
{
    if (nowq.empty())
    {
        nowStatus = 0;
        generateNewSequence();
    }
    Block *t = nowq.front();
    nowq.pop();
    return t;
}
