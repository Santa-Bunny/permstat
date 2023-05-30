#include <display.h>
#include <ncurses.h>

Display::Display(){
    initscr();
}

Display::~Display(){
    endwin();
}