#include "Core.h"
class reg {
    private:
        union {
            u8  hl[4];
            u16 x[2];
            u32 ex;
        } gp;
    public:
        reg(u8 value):gp.hl[0](value);
        reg(u16);
        reg(u32);
        ~reg();
        inline u8 get_8() {
            return gp.hl[0];
        };
        inline u16 get_16() {
            return gp.x[0];
        };
        inline u32 get_32() {
            return gp.ex;
        };
};
