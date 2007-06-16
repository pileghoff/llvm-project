//===--- CodeGenTypes.h - Type translation for LLVM CodeGen -----*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file was developed by Chris Lattner and is distributed under
// the University of Illinois Open Source License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
//
// This is the code that handles AST -> LLVM type lowering. 
//
//===----------------------------------------------------------------------===//

#ifndef CODEGEN_CODEGENTYPES_H
#define CODEGEN_CODEGENTYPES_H

#include <vector>

namespace llvm {
  class Type;
}

namespace clang {
  class TargetInfo;
  class QualType;
  class SourceLocation;
  class FunctionTypeProto;
  
namespace CodeGen {
  
/// CodeGenTypes - This class organizes the cross-module state that is used
/// while lowering AST types to LLVM types.
class CodeGenTypes {
  TargetInfo &Target;
  
public:
  CodeGenTypes(TargetInfo &target) : Target(target) {}
  
  TargetInfo &getTarget() const { return Target; }
  
  const llvm::Type *ConvertType(QualType T, SourceLocation Loc);
  void DecodeArgumentTypes(const FunctionTypeProto &FTP, 
                           std::vector<const llvm::Type*> &ArgTys,
                           SourceLocation Loc);
};
}  // end namespace CodeGen
}  // end namespace clang

#endif
