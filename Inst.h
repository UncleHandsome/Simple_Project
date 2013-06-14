//#include <llvm/DerivedTypes.h>
//#include <llvm/IRBuilder.h>
//#include <llvm/LLVMContext.h>
//#include <llvm/Module.h>
#include "Core.h"
#include "CPU.h"
//using namespace llvm;
class Inst: public CPU {
    public:
        virtual ~Inst() {};
        //  virtual Value *Codegen() = 0;
};
class add : public Inst {
    public:
        template <typename T>
            T exec(const T, const T); 
};
class sub : public Inst {
    public:
        template <typename T>
            T exec(const T, const T);
};
class annd: public Inst {
    public:
        template <typename T>
            T exec(const T, const T);
};
class cmp: public Inst {
    public:
            template <typename T>
                T exec(const T, const T);
};
