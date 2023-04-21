#ifndef MY_SIMPLE_COMPUTER_H
#define MY_SIMPLE_COMPUTER_H

#include <stdio.h>

#define MEMORY_SIZE 100

#define Flag_Wrong_Value 8
#define Flag_Wrong_Flag 7
#define Flag_Wrong_Operand 6
#define Flag_Wrong_Command 5
#define Flag_Not_Load 4
#define Flag_Not_Saved 3
#define Flag_Wrong_Path_File 2
#define Flag_Wrong_Address 1

#define Error_Wrong_Address -1;
#define Error_Wrong_Path_File -2
#define Error_Not_Saved -3
#define Error_Not_Load -4
#define Error_Wrong_Command -5
#define Error_Wrong_Operand -6
#define Error_Wrong_Flag -7
#define Error_Wrong_Value -8

#define forn(X, Y) for (int i = X; i < Y; i++)
#define bit_set(X, Y) X = X | (1 << (Y - 1))
#define bit_del(X, Y) X = X & (~(1 << (Y - 1)))
#define bit_get(X, Y) X >> (Y - 1) & 0x1

static int sc_memory[MEMORY_SIZE];
static int sc_registr;

const int Operation[38] = {10, 11, 20, 21, 30, 31, 32, 33, 40, 41, 42, 43, 51,
                           52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64,
                           65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76};

int sc_memoryInit();
int sc_memorySet(int address, int value);
int sc_memoryGet(int address, int* value);
int sc_memorySave(char* filename);
int sc_memoryLoad(char* filename);
int sc_regInit();
int sc_regSet(int msc_registr, int value);
int sc_regGet(int msc_registr, int* value);
int sc_commandEncode(int command, int operand, int* value);
int sc_commandDecode(int value, int* command, int* operand);
#endif
