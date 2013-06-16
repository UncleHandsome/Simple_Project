#include "Core.h"
class Memory {
    private:
        u32 *memory;
    public:
        Memory() {
            memory = new u32[mm_size];
        }
        ~Memory() {
            delete [] memory;
        }
        inline void set_32(u32 addr, u32 value) {
            *(memory + (addr >> 2)) = value;
        };
        inline u32 get_32(u32 addr) {
            return *(memory + (addr >> 2));
        };
};
