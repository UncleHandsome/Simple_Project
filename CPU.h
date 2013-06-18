#include "Core.h"
class CPU {
    public:
        enum flags {
            CF=  1 << 0,
            PF = 1 << 2,
            AF = 1 << 4,
            ZF = 1 << 6,
            SF = 1 << 7,
            TF = 1 << 8,
            IF = 1 << 9,
            DF = 1 << 10,
            OF = 1 << 11,
            RF = 1 << 16,
            VM = 1 << 17,
            AC = 1 << 18,
            VIF = 1 << 19,
            VIP = 1 << 20,
            ID = 1 << 21
        };
        inline bool get_flag(const flags& flag) {
            return eflags & flag;
        }
        ~CPU () {};
    private:
        static u32 eflags;
    protected:
        inline void set_flag(const flags flag) {
            eflags |= flag;
        }
        inline void clear_flag(const flags& flag) {
            eflags &= ~flag;
        }
};
