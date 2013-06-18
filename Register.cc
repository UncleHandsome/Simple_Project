#include "Register.h"
Register::Register(const u8 value)
{
    gp.hl[0] = value;
}
Register::Register(const u16 value)
{
    gp.x[0] = value;
}
Register::Register(const u32 value)
{
    gp.ex = value;
}
