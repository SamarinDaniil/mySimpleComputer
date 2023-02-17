#include "../src/libComputer/mySimpleComputer.h"
#include <cstdio>
#include <ctest.h>

using namespace std;

// test checkfile
CTEST(check_data, True_address_sc_memorySet)
{
    sc_memoryInit();
    int check = sc_memorySet(1, 1);

    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_address_sc_memorySet)
{
    sc_memoryInit();
    int check = sc_memorySet(101, 1);

    ASSERT_EQUAL(-1, check);
}
CTEST(check_data, True_address_sc_memoryGet)
{
    sc_memoryInit();
    sc_memorySet(1, 1);
    int value = 0;
    int check = sc_memoryGet(1, &value);
    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_address_sc_memoryGet)
{
    sc_memoryInit();
    sc_memorySet(1, 1);
    int value = 0;
    int check = sc_memoryGet(-1, &value);
    ASSERT_EQUAL(-1, check);
}
CTEST(check_data, Check_sc_memorySave)
{
    sc_memoryInit();
    sc_memorySet(1, 1);
    char* Path = "test/test-file.txt";
    int check = sc_memorySave(Path);
    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Check_Wrong_address_sc_memorySave)
{
    sc_memoryInit();
    sc_memorySet(1, 1);
    char* Path = "test/test-file-not.txt";
    int check = sc_memorySave(Path);
    ASSERT_EQUAL(-2, check);
}
CTEST(check_data, Check_sc_memoryLoad)
{
    sc_memoryInit();
    char* Path = "test/test-file.txt";
    int check = sc_memoryLoad(Path);
    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Check_Wrong_address_sc_memoryLoad)
{
    sc_memoryInit();
    char* Path = "test/test-file-not.txt";
    int check = sc_memoryLoad(Path);
    ASSERT_EQUAL(-2, check);
}
CTEST(check_data, True_Flag_sc_regSet)
{
    sc_regInit();
    int check = sc_regSet(Flag_Wrong_Flag,1);

    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_Flag_sc_regSet)
{
    sc_regInit();
    int check = sc_regSet(22,1);

    ASSERT_EQUAL(-7, check);
}
CTEST(check_data, True_Flag_sc_regGet)
{
    sc_regInit();
    int value = 0;
    int check = sc_regGet(Flag_Wrong_Flag, &value);

    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_Flag_sc_regGet)
{
    sc_regInit();
    int value = 0;
    int check = sc_regGet(22, &value);

    ASSERT_EQUAL(-7, check);
}
CTEST(check_data, True_Operand_and_Command_sc_commandEncode)
{
    int a = 0;
    int check = sc_commandEncode(10, 10, &a);

    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_Operand_sc_commandEncode)
{
    int a = 0;
    int check = sc_commandEncode(20, -2, &a);

    ASSERT_EQUAL(-6, check);
}
CTEST(check_data, Wrong_Command_sc_commandEncode)
{
    int a = 0;
    int check = sc_commandEncode(-20, 2, &a);

    ASSERT_EQUAL(-5, check);
}
CTEST(check_data, True_Operand_and_Command_sc_commandDecode)
{
    int a = 0, b =0, c = 0;
    int check = sc_commandDecode(c,&a, &b);

    ASSERT_EQUAL(0, check);
}
CTEST(check_data, Wrong_Command_sc_commandDecode)
{
    int a = 0, b =0, c = 0;
    bit_set(c,14);
    int check = sc_commandDecode(c, &b, &a);

    ASSERT_EQUAL(-5, check);
}