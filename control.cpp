#include "control.hpp"
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
    return new LongBlock(bg);
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
        case KEY_UP:
            now->turn(BlockDirection::RIGHT);
            break;
        case ' ':
            now->moveToBottom();
            now->stopMove();
            delete now;
            now = getNextBlock();
            bg.printBackground(gameMainWin);
            wrefresh(gameMainWin);
            break;
        default:
            break;
        }
        char message[100];
        sprintf(message,"                ");
        mvaddstr(0,0,message);
        sprintf(message,"x:%d, y:%d",now->nowX,now->nowY);
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
        bg.printBackground(gameMainWin);
        now->printBlock(gameMainWin);
        wrefresh(gameMainWin);
        if (!now->move(BlockDirection::DOWN))
        {
            now->stopMove();
            delete now;
            now = getNextBlock();
        }
        pthread_mutex_unlock(&blockLock);
        sleep(1);
    }
}