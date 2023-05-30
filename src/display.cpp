#include "display.h"
#include <curses.h>

Display::Display(){
    initscr();
    printw("HELLO WORLD");
    refresh();
}