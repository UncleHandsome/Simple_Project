#include "x86toArm.h"
#include "llvm/Analysis/Verifier.h"
#include "llvm/Bitcode/ReaderWriter.h"
#include "llvm/ExecutionEngine/GenericValue.h"
#include "llvm/ExecutionEngine/JIT.h"
#include "llvm/IR/Constants.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/ManagedStatic.h"
#include "llvm/Support/TargetSelect.h"
#include "llvm/Support/raw_ostream.h"
#include <iostream>
#include <fstream>
using namespace llvm;

static cl::opt<std::string>
InputFilename(cl::Positional, cl::desc("<input x86toArm>"));

static cl::opt<std::string>
OutputFilename("o", cl::desc("Output filename"), cl::value_desc("filename"));

void addMainFunction(Module *mod)
{
    Function *main_func = cast<Function>(mod->
            getOrInsertFunction("main", 
                IntegerType::getInt32Ty(mod->getContext()),
                IntegerType::getInt32Ty(mod->getContext()),
                PointerType::getUnqual(PointerType::getUnqual(
                        IntegerType::getInt8Ty(mod->getContext()))), 
                NULL));
    {
        Function::arg_iterator args = main_func->arg_begin();
        Value *arg_0 = args++;
        arg_0->setName("argc");
        Value *arg_1 = args++;
        arg_1->setName("argv");
    }

    BasicBlock *bb = BasicBlock::Create(mod->getContext(), "main.0", main_func);

    {

    }

    ReturnInst::Create(mod->getContext(), 
            ConstantInt::get(mod->getContext(), APInt(32, 0)), bb);
}

int main(int argc, const char **argv)
{
    cl::ParseCommandLineOptions(argc, argv, "x86toArm");

    LLVMContext &Context = getGlobalContext();

    if (InputFilename == "") {
        errs() << "Error: You must specify the filename of the program to "
            "be compiled.  Use --help to see the options.\n";
        abort();
    }

    //Get the output stream
    raw_ostream *out = &outs();
    if (OutputFilename == "") {
        std::string base = InputFilename;
        if (InputFilename == "-") { base = "a"; }

        // Use default filename.
        OutputFilename = base+".bc";
    }
    if (OutputFilename != "-") {
        std::string ErrInfo;
        out = new raw_fd_ostream(OutputFilename.c_str(), ErrInfo,
                raw_fd_ostream::F_Binary);
    }

    //Get the input stream
    std::istream *in = &std::cin;
    if (InputFilename != "-")
        in = new std::ifstream(InputFilename.c_str());

    x86toArm x2a;
    Module *mod = x2a.parse(in, 65536, Context);

    if (in != &std::cin)
        delete in;

    addMainFunction(mod);

    if (verifyModule(*mod)) {
        errs() << "Error: module failed verification.  This shouldn't happen.\n";
        abort();
    }

    //WriteBitcodeToFile(mod, *out);

    if (out != &outs())
        delete out;
    delete mod;

    llvm_shutdown();

    return 0;
}
