#include <iostream>
#include <stdio.h>
#include "elf.h"

using namespace std;

int main()
{
    std::cout << sizeof(elf_header_32) << std::endl;
    return 0;
}