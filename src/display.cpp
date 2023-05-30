#include "display.h"
#include <curses.h>

Display::Display(){
    initscr();
    cbreak();
    refresh();
}