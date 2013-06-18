#include "CPU.h"
#include <cstdio>
#include "llvm/Analysis/Verifier.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/Interpreter.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Instructions.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
using namespace llvm;


class Inst: public CPU {
    public:
        ~Inst() {};
        virtual Value *Codegen() = 0;
};
class Add : public Inst {
    public:
        template <typename T>
            T exec(const T, const T); 
        virtual Value *Codegen();
};
class Sub : public Inst {
    public:
        template <typename T>
            T exec(const T, const T);
        virtual Value *Codegen();
};
class And: public Inst {
    public:
        template <typename T>
            T exec(const T, const T);
        virtual Value *Codegen();
};
class Cmp: public Inst {
    public:
        template <typename T>
            void exec(const T, const T);
        virtual Value *Codegen();
};
// OF, SF, ZF, AF, PF, CF
    template <typename T>
T Add::exec(const T a, const T b)
{
    return a + b;
}
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
    template <typename T>
void Cmp::exec(const T a, const T b)
{
    T c = a - b;
    if (c == 0)
        set_flag(CPU::ZF);
}


