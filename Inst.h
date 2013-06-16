//#include <llvm/DerivedTypes.h>
//#include <llvm/IRBuilder.h>
//#include <llvm/LLVMContext.h>
//#include <llvm/Module.h>
#include "Core.h"
#include "CPU.h"
#include <cstdio>
//using namespace llvm;
class Inst: public CPU {
    public:
        ~Inst() {};
        //  virtual Value *Codegen() = 0;
};
class Add : public Inst {
    public:
        template <typename T>
            T exec(const T, const T); 
};
class Sub : public Inst {
    public:
        template <typename T>
            T exec(const T, const T);
};
class And: public Inst {
    public:
        template <typename T>
            T exec(const T, const T);
};
class Cmp: public Inst {
    public:
            template <typename T>
                void exec(const T, const T);
};
template <typename T>
T Add::exec(const T a, const T b)
{
    return a + b;
}
// OF, SF, ZF, AF, PF, CF
template <typename T>
T Sub::exec(const T a, const T b)
{
    return a - b;
}
template <typename T>
T And::exec(const T a, const T b)
{
    return a & b;
}
// a - b
template <typename T>
void Cmp::exec(const T a, const T b)
{
    T c = a - b;
    if (c == 0)
        CPU::set_flag(ZF);
}
