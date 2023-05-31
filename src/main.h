#ifndef MAIN_H
#define MAIN_H

#include <deque>
#include <vector>
#include <string>
#include <algorithm>
#include <exception>

#include "display.h"
#include <ncurses.h>



void final(int exitnum);
void scanWin(WINDOW* win, windowSize* winsize);


#endif // MAIN_H