#include "Core.h"
class Memory {
    private:
        char *memory;
    public:
        Memory() {
            memory = new char[mm_size];
        }
        inline void set_32(u32 addr, u32 value) {
            *(memory + addr) = value;
        };
        inline u32 get_32(u32 addr) {
            return *(memory + addr);
        };
};
