//#include <llvm/DerivedTypes.h>
//#include <llvm/IRBuilder.h>
//#include <llvm/LLVMContext.h>
//#include <llvm/Module.h>
#include "Core.h"
#include "CPU.h"
//using namespace llvm;
class Inst: public CPU {
    virtual ~Inst() {};
  //  virtual Value *Codegen() = 0;
};
template <typename T>
class add : public Inst {
    public:
        virtual ~add() {};
        inline T exec(const T a, const T b) {
            T c = a + b;
            if ((c >> ((sizeof(T) << 3) - 1)))
                set_flag(OF);
        };
};
template <typename T>
class sub : public Inst {
    public:
        virtual ~sub() {};
        inline T exec(const T a, const T b) {
            T c = a + b;
            if ((c >> ((sizeof(T) << 3) - 1)))
                set_flag(OF);
        };
};
