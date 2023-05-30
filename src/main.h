#ifndef MAIN_H
#define MAIN_H

#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>


#include <ncurses.h>

#define BLOCK_LIGHT  176
#define BLOCK_MEDIUM 177
#define BLOCK_DENSE  178

struct windowSize {
    int maxY;
    int maxX;
    int begY;
    int begX;
};

void final(int exitnum);
void scanWin();
void getWsize(WINDOW* win, struct windowSize* sizes);

#endif // MAIN_H