// SimpleComputer.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "../libComputer/mySimpleComputer.h"
#include <iostream>

int main()
{
    sc_memoryInit();
    sc_regInit();
    int z = sc_memorySet(101, 1);
    if (z == -1)
        std::cout << "True" << std::endl;
    int a = 0;
    sc_commandEncode(10, 10, &a);
    int b = 0, c = 0;
    std::cout << sc_commandDecode(a, &b, &c) << std::endl;
    std::cout << b << c << std::endl;
    return 0;
}


