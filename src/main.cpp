#include "main.h"
#include "display.h"

#include <iostream>

#include <curses.h>

int main(int argc, char** argv){
    windowSize stdSize;
    initscr();
    cbreak();
    refresh();

    getWsize(stdscr, &stdSize);
    WINDOW* win = newwin(10, stdSize.maxX - 2, (stdSize.maxY / 2 - 5), stdSize.begX + 2);
    scanWin(win, &stdSize);

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
void scanWin(WINDOW* win, windowSize* winsize){
    box(win, 0, 0);
    mvwprintw(win, 0, 3, "Scanning...");
    mvwprintw(win, 2, 2, "Total items: %d", 0);
    mvwprintw(win, 3, 2, "Current item: %s", "/mnt/docs");
    mvwprintw(win, 8, 2, "Scanning...");
    wrefresh(win);
}