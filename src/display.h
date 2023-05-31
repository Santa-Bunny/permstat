#ifndef DISPLAY_H
#define DISPLAY_H

#include <curses.h>

struct windowSize {
    int maxY;
    int maxX;
    int begY;
    int begX;
};

class Display {
public:
    Display();

    ~Display(){};

private:
    
};


void getWsize(WINDOW* win, struct windowSize* sizes);


#endif // DISPLAY_H