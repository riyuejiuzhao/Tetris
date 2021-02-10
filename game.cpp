#include"background.h"

int main(int argc, char *argv[])
{
    Background background;
    initscr();
    cbreak();
    noecho();
    clear();
    background.printBackground();
    endwin();
    return 0;
}