#pragma once

#include <vector>
#include <Block.hpp>

//用来定义常量，预处理器报错难以识别，所以我不太喜欢用#define
enum
{
    BACKGROUND_HEIGHT = 40, //背景高度
    BACKGROUND_CEIL = 20,   //能显示的最大高度
    BACKGROUND_WIDTH = 20,  //背景宽度
    BACKGROUND_TOP = 8,     //背景距离终端顶端距离
    BACKGROUND_LEFT = 80,   //背景距离终端左侧距离
    DEFAULT_CONTENT = ' ',  //背景填充
    BACKGROUND_INDEX_OFFSET = 1,
    BACKGROUND_HEIGHT_PAD = 2 * BACKGROUND_INDEX_OFFSET, //背景边框需要让出来，所以填充两位
    BACKGROUND_WIDTH_PAD = 2 * BACKGROUND_INDEX_OFFSET,  //背景边框需要让出来，所以填充两位
    //新方块的位置
    NEW_BLOCK_X = 0 + BACKGROUND_CEIL, //距离顶端的距离
    NEW_BLOCK_Y = 10,                  //距离边缘的距离
    //不同的方块由于用来定位的块不同，需要有不同的初始位置
    NEW_I_BLOCK_X = 0 + BACKGROUND_CEIL,
    NEW_I_BLOCK_Y = 2 + 2 * 4,
    //颜色
    //定义背景颜色
    BACKGROUND_COLOR = 0,
    //方块颜色
    BLOCK_CYAN = 1,
    BLOCK_MAGENTA = 2,
    BLOCK_BLUE = 3,
    BLOCK_ORANGE = 4, 
    BLOCK_YELLOW = 5,
    BLOCK_GREEN = 6,
    BLOCK_RED = 7,
    //这里时方块还没有落下时， 
    //程序给玩家一个预览
    BLOCK_VIRTURL_CYAN = 11,
    BLOCK_VIRTURL_MAGENTA = 12,
    BLOCK_VIRTURL_BLUE = 13,
    BLOCK_VIRTURL_ORANGE = 14,
    BLOCK_VIRTURL_YELLOW = 15,
    BLOCK_VIRTURL_GREE = 16,
    BLOCK_VIRTUAL_RED = 17,
    //Wall Kick
    ZERO_TO_R = 0,
    R_TO_ZERO = 1,
    R_TO_TWO = 2,
    TWO_TO_R = 3,
    TWO_TO_L = 4,
    L_TO_TWO = 5,
    L_TO_ZERO = 6,
    ZERO_TO_L = 7
};

