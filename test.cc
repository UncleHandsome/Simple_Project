#include "Core.h"
#include "Memory.h"
#include "Register.h"
#include "Inst.h"
#include <cstdio>

Register eax, ebx, ecx, edx, esp, ebp;
Memory mem;
Add add;
int main(void)
{
    int a = 10, b = 20;
    printf("%d\n", add.exec(a, b));
    return 0;
}

