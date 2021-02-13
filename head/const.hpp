#pragma once
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
    BACKGROUND_WIDTH_PAD = 4 * BACKGROUND_INDEX_OFFSET, //背景边框需要让出来，所以填充两位
    //新方块的位置
    NEW_BLOCK_X = 0 + BACKGROUND_CEIL, //距离顶端的距离
    NEW_BLOCK_Y = 10,                  //距离边缘的距离
    //不同的方块由于用来定位的块不同，需要有不同的初始位置
    NEW_LONG_BLOCK_X = 0 + BACKGROUND_CEIL,
    NEW_LONG_BLOCK_Y = 5 + 2*4,
    //颜色
    //定义背景颜色
    BACKGROUND_COLOR = 0,
    //方块颜色
    BLOCK_BLUE = 1,
    BLOCK_RED = 2,
    BLOCK_GREEN = 3,
    BLOCK_YELLOW = 4,
    BLOCK_WHITE = 5,
    //这里时方块还没有落下时，
    //程序给玩家一个预览
    BLOCK_VIRTURL_BLUE = 6,

};