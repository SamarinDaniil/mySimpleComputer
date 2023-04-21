#include "mySimpleComputer.h"

int sc_memoryInit()
{
    forn(0, MEMORY_SIZE)
    {
        sc_memory[i] = 0;
    }
    return 0;
}

int sc_memorySet(int address, int value)
{
    if (address < 0 || address > MEMORY_SIZE) {
        sc_regSet(Flag_Wrong_Address, 1);
        return Error_Wrong_Address;
    } else {
        sc_memory[address] = value;
    }
    return 0;
}

int sc_memoryGet(int address, int* value)
{
    if (address < 0 || address > MEMORY_SIZE) {
        sc_regSet(Flag_Wrong_Address, 1);
        return Error_Wrong_Address;
    } else {
        *value = sc_memory[address];
    }
    return 0;
}

int sc_memorySave(char* filename)
{
    int flag = 0;
    FILE* write_bin = fopen(filename, "r+b");
    if (write_bin != NULL) {
        flag = fwrite(sc_memory, sizeof(int), MEMORY_SIZE, write_bin);
        if (flag != MEMORY_SIZE) {
            sc_regSet(Flag_Not_Saved, 1);
            return Error_Not_Saved;
        }
    } else {
        sc_regSet(Flag_Wrong_Path_File, 1);
        return Error_Wrong_Path_File;
    }
    fclose(write_bin);
    return 0;
}

int sc_memoryLoad(char* filename)
{
    int flag = 0;
    FILE* read_bin = fopen(filename, "rb");
    if (read_bin != NULL) {
        flag = fread(sc_memory, sizeof(int), MEMORY_SIZE, read_bin);
        if (flag != MEMORY_SIZE) {
            sc_regSet(Flag_Not_Load, 1);
            return Error_Not_Load;
        }
    } else {
        sc_regSet(Flag_Wrong_Path_File, 1);
        return Error_Wrong_Path_File;
    }
    fclose(read_bin);
    return 0;
}

int sc_regInit()
{
    sc_registr &= 0;
    return 0;
}

int sc_regSet(int msc_registr, int value)
{
    if (msc_registr > 0 && msc_registr <= 8) {
        if (value) {
            if (value == 1) {
                bit_set(sc_registr, msc_registr);
            } else {
                bit_set(sc_registr, Flag_Wrong_Value);
                return Error_Wrong_Value;
            }
        } else {
            bit_del(sc_registr, msc_registr);
        }
    } else {
        sc_regSet(Flag_Wrong_Value, 1);
        return Error_Wrong_Flag;
    }
    return 0;
}

int sc_regGet(int msc_registr, int* value)
{
    if ((msc_registr > 0) && (msc_registr <= 8)) {
        *value = bit_get(sc_registr, msc_registr);
    } else {
        *value = -1;
        sc_regSet(Flag_Wrong_Flag, 1);
        return Error_Wrong_Flag;
    }
    return 0;
}

int sc_commandEncode(int command, int operand, int* value)
{
    int isCom = 0;
    forn(0, 38)
    {
        if (command == Operation[i])
            isCom = 1;
    }
    if (isCom) {
        if ((operand >= 0) && (operand < 128)) {
            *value = (*value) & 0;
            *value = (*value) | command;
            *value = (*value) << 7;
            *value = (*value) | operand;
            return 0;
        } else {
            sc_regSet(Flag_Wrong_Operand, 1);
            return Error_Wrong_Operand;
        }
    }
    sc_regSet(Flag_Wrong_Command, 1);
    return Error_Wrong_Command;
}

int sc_commandDecode(int value, int* command, int* operand)
{
    int notCommand = bit_get(value, 14);

    if (!notCommand) {
        *command = (value >> 7);
        value -= ((value >> 7) << 7);
        *operand = value;
        return 0;
    } else {
        sc_regSet(Flag_Wrong_Command, 1);
        return Error_Wrong_Command;
    }
}