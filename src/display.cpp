#include "display.h"
#include <curses.h>

/// @brief Gets the size of the window in rows/columns and loads it into sizes
/// @param win the window to get the size of
/// @param sizes the location in memory to store the sizes
void getWsize(WINDOW* win, struct windowSize* sizes){
    getbegyx(win, sizes->begY, sizes->begX);
    getmaxyx(win, sizes->maxY, sizes->maxX);
    return;
}