#include "control.hpp"
#include "random.hpp"
#include <ncurses.h>

void initColor()
{
    init_pair(BACKGROUND_COLOR, COLOR_BLACK, COLOR_BLACK);
    init_pair(BLOCK_CYAN, COLOR_CYAN, COLOR_CYAN);
    init_pair(BLOCK_VIRTURL_CYAN, COLOR_CYAN, COLOR_BLACK);
    init_pair(BLOCK_MAGENTA, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(BLOCK_VIRTURL_MAGENTA, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(BLOCK_BLUE, COLOR_BLUE, COLOR_BLUE);
    init_pair(BLOCK_VIRTURL_BLUE, COLOR_BLUE, COLOR_BLACK);
    //没有橘色，用白色
    init_pair(BLOCK_ORANGE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLOCK_VIRTURL_ORANGE, COLOR_WHITE, COLOR_BLACK);

    init_pair(BLOCK_YELLOW, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(BLOCK_VIRTURL_YELLOW, COLOR_YELLOW, COLOR_BLACK);
    init_pair(BLOCK_GREEN, COLOR_GREEN, COLOR_GREEN);
    init_pair(BLOCK_VIRTURL_GREE, COLOR_GREEN, COLOR_BLACK);
    init_pair(BLOCK_RED, COLOR_RED, COLOR_RED);
    init_pair(BLOCK_VIRTUAL_RED, COLOR_RED, COLOR_BLACK);
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

int main(int argc, char *argv[])
{
    gameInit();
    gameMainProcess();

//    RandomBlock t;
//    for (int i = 0; i < 10; ++i)
//    {
//        for (int j = 0; j < 7; ++j)
//        {
//            Block *temp = t.getNext();
//            if (temp->getType() == BlockType::I)
//                printf("I, ");
//            else if (temp->getType() == BlockType::J)
//                printf("J, ");
//            else if (temp->getType() == BlockType::L)
//                printf("L, ");
//            else if (temp->getType() == BlockType::O)
//                printf("O, ");
//            else if (temp->getType() == BlockType::S)
//                printf("S, ");
//            else if (temp->getType() == BlockType::T)
//                printf("T, ");
//            else if (temp->getType() == BlockType::Z)
//                printf("Z, ");
//        }
//        printf("\n");
//    }

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
    return 0;
}