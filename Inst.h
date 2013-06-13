#include <llvm/DerivedTypes.h>
#include <llvm/IRBuilder.h>
#include <llvm/LLVMContext.h>
#include <llvm/Module.h>
#include <llvn/Analysis/Verifier.h>
class Inst {
    virtual ~Inst() {};
    virtual Value *Codegen() = 0;
};
