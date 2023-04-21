#include "myTerm.h"

int mt_clrscr(void)
{
    printf(CLEAR);
    return 0;
}

int mt_gotoXY(int x, int y)
{
    printf(SET_ADDR, x, y);
    return 0;
}

int mt_getscreensize(int* rows, int* cols)
{
    struct winsize ws;

    if (!ioctl(1, TIOCGWINSZ, &ws)) {
        *rows = ws.ws_row;
        *cols = ws.ws_col;
    } else {
        return -1;
    }
    return 0;
}

int mt_setfgcolor(COLORS color)
{
    if ((int)color > 29 && (int)color < 38) {
        printf(SET_COLOR, color);
        return 0;
    }
    return -1;
}

int mt_setbgcolor(COLORS color)
{
    if ((int)color > 29 && (int)color < 38) {
        printf(SET_COLOR, color+10);
        return 0;
    }
    return -1;
}