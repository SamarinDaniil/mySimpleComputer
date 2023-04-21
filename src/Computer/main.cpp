// SimpleComputer.cpp : Этот файл содержит функцию "main". Здесь начинается и
// заканчивается выполнение программы.
//
#include "../libComputer/mySimpleComputer.h"
#include "../libComputer/myTerm.h"
#include <iostream>

#define line(x)                 \
    for (int i = 0; i < x; i++) \
        printf("-");

int main()
{
    sc_memoryInit();
    sc_regInit();
    mt_clrscr();
    // memory
    for (int i = 0; i < 28; i++)
    {
        printf("-");
    }
    printf("Memory");
    for (int i = 0; i < 28; i++)
    {
        printf("-");
    }
    printf("\n");
    for (int i = 0; i < 10; i++)
    {
        printf("|");
        for (int j = 0; j < 10; j++)
        {   
            printf(" +%04d",sc_memory[i*10+j]);
        }
        printf("|\n");
    }
    for (int i = 0; i < 62; i++)
    {
        printf("-");
    }
    printf("\n");
    // keys
    mt_gotoXY(14,47);line(1)printf(" Keys: ");line(32)
    mt_gotoXY(15,47);printf("| l - load ");mt_gotoXY(15,86);printf("|\n");
    mt_gotoXY(16,47);printf("| s - save ");mt_gotoXY(16,86);printf("|\n");
    mt_gotoXY(17,47);printf("| r - run ");mt_gotoXY(17,86);printf("|\n");
    mt_gotoXY(18,47);printf("| t - step ");mt_gotoXY(18,86);printf("|\n");
    mt_gotoXY(19,47);printf("| i - reset ");mt_gotoXY(19,86);printf("|\n");
    mt_gotoXY(20,47);line(40)printf("\n");
    // flag
    mt_gotoXY(10,64); line(23)
    mt_gotoXY(11,64);printf("|");mt_gotoXY(11,73); printf("O E V M");mt_gotoXY(11,86);printf("|");
    mt_gotoXY(12,64); line(23)
    //
    mt_gotoXY(21,0); printf("\n");

    return 0;
}
