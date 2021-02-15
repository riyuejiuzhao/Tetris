#include "background.hpp"
#include "Block.hpp"
#include "control.hpp"
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

void initColor()
{
    init_pair(BACKGROUND_COLOR, COLOR_BLACK, COLOR_BLACK);
    init_pair(BLOCK_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BLOCK_VIRTURL_BLUE, COLOR_BLUE, COLOR_BLACK);
    init_pair(BLOCK_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(BLOCK_VIRTURL_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
}

void gameInit()
{
    initscr();
    //开启方向键的使用
    if (has_colors())
    {
        start_color();
        initColor();
    }
    else
    {
        printf("sorry no color\n");
        exit(1);
    }
    keypad(stdscr, TRUE);
    cbreak();
    noecho();
    clear();
    refresh();
}

void gameEnd()
{
}

int main(int argc, char *argv[])
{
    gameInit();
    //    int ch;
    //    int height = BACKGROUND_HEIGHT, weight = BACKGROUND_WIDTH,
    //        x = BACKGROUND_LEFT, y = BACKGROUND_TOP;
    //    WINDOW *t = newwin(height, weight, y, x);
    //    WINDOW *tt = newwin(height-2, weight-2,y+1,x+1);
    //    wrefresh(t);
    //    wrefresh(tt);
    //    while ((ch = getch()) != KEY_F(1))
    //    {
    //        switch (ch)
    //        {
    //        case KEY_UP:
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wborder(tt, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            wrefresh(tt);
    //            delwin(t);
    //            delwin(tt);
    //            if (y >= 0)
    //                --y;
    //            t = newwin(height, weight, y, x);
    //            tt = newwin(height-2, weight-2,y+1,x+1);
    //            box(t, 0, 0);
    //            box(tt, 0, 0);
    //            wrefresh(t);
    //            wrefresh(tt);
    //            break;
    //        case KEY_DOWN:
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wborder(tt, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            wrefresh(tt);
    //            delwin(t);
    //            delwin(tt);
    //            ++y;
    //            t = newwin(height, weight, y, x);
    //            tt = newwin(height-2, weight-2,y+1,x+1);
    //            box(t, 0, 0);
    //            box(tt, 0, 0);
    //            wrefresh(t);
    //            wrefresh(tt);
    //            break;
    //        case KEY_LEFT:
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wborder(tt, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            wrefresh(tt);
    //            delwin(t);
    //            delwin(tt);
    //            if (x >= 0)
    //                --x;
    //            t = newwin(height, weight, y, x);
    //            tt = newwin(height-2, weight-2,y+1,x+1);
    //            box(t, 0, 0);
    //            box(tt, 0, 0);
    //            wrefresh(t);
    //            wrefresh(tt);
    //            break;
    //        case KEY_RIGHT:
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wborder(tt, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            wrefresh(tt);
    //            delwin(t);
    //            delwin(tt);
    //            ++x;
    //            t = newwin(height, weight, y, x);
    //            tt = newwin(height-2, weight-2,y+1,x+1);
    //            box(t, 0, 0);
    //            box(tt, 0, 0);
    //            wrefresh(t);
    //            wrefresh(tt);
    //            break;
    //        case 'w':
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            delwin(t);
    //            ++height;
    //            t = newwin(height, weight, y, x);
    //            box(t, 0, 0);
    //            wrefresh(t);
    //            break;
    //        case 's':
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            delwin(t);
    //            if (height > 1)
    //                --height;
    //            t = newwin(height, weight, y, x);
    //            box(t, 0, 0);
    //            wrefresh(t);
    //            break;
    //        case 'd':
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            delwin(t);
    //            ++weight;
    //            t = newwin(height, weight, y, x);
    //            box(t, 0, 0);
    //            wrefresh(t);
    //            break;
    //        case 'a':
    //            wborder(t, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    //            wrefresh(t);
    //            delwin(t);
    //            if (weight > 1)
    //                --weight;
    //            t = newwin(height, weight, y, x);
    //            box(t, 0, 0);
    //            wrefresh(t);
    //
    //            break;
    //        case 'p':
    //        case 'P':
    //            char message[1000];
    //            sprintf(message, "x: %d, y: %d, height: %d, width:%d", x, y, height, weight);
    //            waddstr(t, message);
    //            wrefresh(t);
    //            break;
    //        default:
    //            break;
    //        }
    //    }

    gameMainProcess();
    gameEnd();

    return 0;
}