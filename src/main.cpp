#include "main.h"
#include "display.h"

#include <iostream>

#include <curses.h>

int main(){
    Display disply;
    windowSize stdSize;

    getWsize(stdscr, &stdSize);

    scanWin();

    getch();
    final(0);
}


/// @brief Cleanup memory and close
/// @param exitnum the exit code of the program
void final(int exitnum){
    endwin();
    exit(exitnum);
}

/// @brief Makes the box to start scanning and calls scan program
void scanWin(){
    WINDOW* win = newwin(10,20,0,0);
    refresh();
    
    box(win, 0, 0);
    mvwprintw(win, 0, 2, "Scanning...");
    wrefresh(win);


}

/// @brief Gets the size of the window in rows/columns and loads it into sizes
/// @param win the window to get the size of
/// @param sizes the location in memory to store the sizes
void getWsize(WINDOW* win, struct windowSize* sizes){
    getbegyx(win, sizes->begY, sizes->begX);
    getmaxyx(win, sizes->maxY, sizes->maxX);
    return;
}



void testing(){
    int y = 5, x = 5;

    move(y, x);
    printw("hello world");
    

    move(0,0);
    char v = getch();
}