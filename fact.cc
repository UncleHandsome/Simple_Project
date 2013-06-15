#include "Core.h"
#include "Memory.h"
#include "Register.h"
#include "Inst.h"
#include <cstdio>

Register eax, ebx, ecx, edx, esp((u32)mm_size), ebp((u32)mm_size);
Memory mem;
Add add;
Sub sub;
And annd;
Cmp cmp;
CPU cpu;
u32 CPU::eflags = 0;
int main(void)
{
    u32 addr, value;

    value = sub.exec(esp.get_32(), (u32)0x4);
    esp.set_32(value);
    addr = esp.get_32();
    value = ebp.get_32();
    mem.set_32(addr, value);

    value = esp.get_32();
    ebp.set_32(value);

    value = annd.exec(esp.get_32(), 0xfffffff0); 
    esp.set_32(value);
    
    value = sub.exec(esp.get_32(), (u32)0x20);
    esp.set_32(value);

    addr = add.exec(esp.get_32(), (u32)0x1c);
    value = 0x0;
    mem.set_32(addr, value);

    value = add.exec(esp.get_32(), (u32)0x14);
    eax.set_32(value);

    addr = add.exec(esp.get_32(), (u32)0x4);
    value = eax.get_32();
    mem.set_32(addr, value);

    addr = esp.get_32();
    value = 0x8048540;
    mem.set_32(addr, value);

    // call scanf
    addr = add.exec(esp.get_32(), (u32)0x14);
    value = 10;
    mem.set_32(addr, value);
    // call scanf

    addr = add.exec(esp.get_32(), (u32)0x18);
    value = 0x1;
    mem.set_32(addr, value);

    goto  main_0x3c;

again:
    addr = add.exec(esp.get_32(), (u32)0x18);
    value = mem.get_32(addr);
    eax.set_32(value);

    addr = add.exec(esp.get_32(), (u32)0x1c);
    value = mem.get_32(addr);
    value = add.exec(value, eax.get_32());
    mem.set_32(addr, value);

    addr = add.exec(esp.get_32(), (u32)0x18);
    value = add.exec(mem.get_32(addr), (u32)0x1);
    mem.set_32(addr, value);

main_0x3c:
    addr = add.exec(esp.get_32(), (u32)0x14);
    value = mem.get_32(addr);
    eax.set_32(value);

    addr = add.exec(esp.get_32(), (u32)0x18);
    value = mem.get_32(addr);
    cmp.exec(eax.get_32(), value);

    if (!cpu.get_flag(CPU::ZF))// || (cpu.get_flag(CPU::SF) < cpu.get_flag(CPU::OF)))
        goto again;

    addr = add.exec(esp.get_32(), (u32)0x1c);
    value = mem.get_32(addr);
    eax.set_32(value);

    value = eax.get_32();
    addr = add.exec(esp.get_32(), (u32)0x4);
    mem.set_32(addr, value);

    addr = esp.get_32();
    value = 0x8048543;
    mem.set_32(addr, value);

    // printf
    addr = add.exec(esp.get_32(), (u32)0x1c);
    value = mem.get_32(addr);
    printf("%d\n", value);
    // printf

    return 0;
}

