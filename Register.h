#include "Core.h"
class Register {
    private:
        union {
            u8  hl[4];
            u16 x[2];
            u32 ex;
        } gp;
    public:
        Register(const u8);
        Register(const u16);
        Register(const u32);
        ~Register();
        inline const u8 get_8() {
            return gp.hl[0];
        };
        inline const u16 get_16() {
            return gp.x[0];
        };
        inline const u32 get_32() {
            return gp.ex;
        };
        inline void set_8(const u8 value) {
            gp.hl[0] = value;
        };
        inline void set_16(const u16 value) {
            gp.x[0] = value;
        };
        inline void set_32(const u32 value) {
            gp.ex = value;
        };
};
