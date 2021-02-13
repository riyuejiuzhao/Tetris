#include "background.hpp"

BackgroundPoint::BackgroundPoint()
    : color(BACKGROUND_COLOR), content(DEFAULT_CONTENT)
{
}

BackgroundPoint::BackgroundPoint(int tColor, char tContent)
    : color(tColor), content(tContent)
{
}

BackgroundPoint::BackgroundPoint(const BackgroundPoint &b)
    : color(b.color), content(b.content)
{
}

int BackgroundPoint::operator[](int index)
{
    return (index == 0) ? content : color;
}

BackgroundPoint &BackgroundPoint::operator=(const BackgroundPoint &b)
{
    color = b.color;
    content = b.content;
    return *this;
}

bool BackgroundPoint::isEmpty()
{
    return content == ' ' && color == BACKGROUND_COLOR;
}