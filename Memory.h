#include "Core.h"
class Memory {
    private:
        u8 *memory;
    public:
        Memory() {
            memory = new u8[mm_size];
        }
        inline void set_32(u32 addr, u32 value) {
            *((u32 *)memory + (addr >> 2)) = value;
        };
        inline u32 get_32(u32 addr) {
            return *((u32 *)memory + (addr >> 2));
        };
};
