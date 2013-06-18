#include "Inst.h"
#include "Memory.h"
#include "Register.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"


using namespace llvm;

class x86toArm {
    public:
        Module *parse(std::istream *in1, int mem, LLVMContext& C);
    protected:
        Add add;
        Sub sub;
        And annd;
        Cmp cmp;
        Memory mem;
        Register eax, ebx, ecx, edx, esp, ebp;

        void header(LLVMContext& C);

        std::istream *in;
        Module *module;

        IRBuilder<> *builder;
        Value *crushed;
};
