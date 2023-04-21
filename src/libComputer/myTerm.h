#ifndef MY_TERM_H
#define MY_TERM_H

#include <fcntl.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define CLEAR "\E[H\E[2J"
#define SET_ADDR "\E[%d;%dH"
#define RESET "\E[0m"
#define SET_COLOR "\033[%dm"
#define STANDARD "\033[39m"

typedef enum {
    BLACK = 30,
    RED = 31,
    GREEN = 32,
    YELLOW = 33,
    BLUE = 34,
    MAGENTA = 35,
    CYAN = 36,
    WHITE = 37,
} COLORS; // bgcolor = fgcolor+10

int mt_clrscr(void); //производит очистку и перемещение курсора в левый верхний
                     //угол экрана;
int mt_gotoXY(int row, int column); //перемещает курсор в указанную позицию.
//Первый параметр номер строки, второй - номер столбца;
int mt_getscreensize(int* rows, int* cols); //определяет размер экрана терминала
                                            //(количество строк и столбцов);
int mt_setfgcolor(COLORS color); //устанавливает цвет последующих
//выводимых символов. В качестве параметра передаётся константа из
//созданного Вами перечислимого типа colors, описывающего цвета
//терминала;
int mt_setbgcolor(COLORS color); //- устанавливает цвет фона
//последующих выводимых символов. В качестве параметра передаётся
//константа из созданного Вами перечислимого типа colors, описывающего
//цвета терминала.
#endif
