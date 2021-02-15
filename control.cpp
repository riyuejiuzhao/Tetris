#include "control.hpp"
#include "TBlock.hpp"
#include "LBlock.hpp"
#include "JBlock.hpp"
#include <unistd.h>
#include <assert.h>

pthread_mutex_t blockLock;
Background bg;
Block *now = getNextBlock();
WINDOW *gameOutWin = nullptr;  //外面的边框
WINDOW *gameMainWin = nullptr; //放方块的地方

//后面还需要在修改
Block *getNextBlock()
{
    Block *temp;
    static int i=0;
    if(i==0)
        temp = new TBlock(bg);
    else if(i==1)
        temp = new JBlock(bg);
    else if(i==2)
        temp = new LBlock(bg);
    else if(i==3)
        temp = new LongBlock(bg);
    else
        temp = new TBlock(bg);
    i=(i+1)%4;
    return temp;
}

void *keyboardControlProcess(void *arg)
{
    while (1)
    {
        int c = getch();
        pthread_mutex_lock(&blockLock);
        switch (c)
        {
        case KEY_RIGHT:
            now->move(BlockDirection::RIGHT);
            bg.printBackground(gameMainWin);
            now->printBlock(gameMainWin);
            wrefresh(gameMainWin);
            break;
        case KEY_LEFT:
            now->move(BlockDirection::LEFT);
            bg.printBackground(gameMainWin);
            now->printBlock(gameMainWin);
            wrefresh(gameMainWin);
            break;
        case KEY_DOWN:
            now->turn(BlockDirection::LEFT);
            bg.printBackground(gameMainWin);
            now->printBlock(gameMainWin);
            wrefresh(gameMainWin);
            break;
        case KEY_UP:
            now->turn(BlockDirection::RIGHT);
            bg.printBackground(gameMainWin);
            now->printBlock(gameMainWin);
            wrefresh(gameMainWin);
            break;
        case ' ':
            now->moveToBottom();
            now->stopMove();
            delete now;
            now = getNextBlock();
            bg.printBackground(gameMainWin);
            now->printBlock(gameMainWin);
            wrefresh(gameMainWin);
            break;
        default:
            break;
        }
        char message[100];
        sprintf(message,"                             \n                             ");
        mvaddstr(0,0,message);
        sprintf(message,"%s\n, x:%d, y:%d",now->getDirection().c_str(),now->getX(),now->getY());
        mvaddstr(0,0,message);
        pthread_mutex_unlock(&blockLock);
    }
    return nullptr;
}

void gameMainProcess()
{
    pthread_t pid;

    gameOutWin = newwin(BACKGROUND_HEIGHT_PAD + BACKGROUND_CEIL, BACKGROUND_WIDTH + BACKGROUND_WIDTH_PAD,
                        BACKGROUND_TOP, BACKGROUND_LEFT);
    gameMainWin = newwin(BACKGROUND_CEIL, BACKGROUND_WIDTH,
                         BACKGROUND_TOP + 1, BACKGROUND_LEFT + 1);
    box(gameOutWin, 0, 0);
    wrefresh(gameOutWin);
    wrefresh(gameMainWin);

    pthread_mutex_init(&blockLock, nullptr);
    pthread_create(&pid, nullptr, keyboardControlProcess, nullptr);

    while (1)
    {
        pthread_mutex_lock(&blockLock);

        if (!now->move(BlockDirection::DOWN))
        {
            now->stopMove();
            delete now;
            now = getNextBlock();
        }
        bg.printBackground(gameMainWin);
        now->printBlock(gameMainWin);
        wrefresh(gameMainWin);

        pthread_mutex_unlock(&blockLock);
        sleep(1);
    }
}