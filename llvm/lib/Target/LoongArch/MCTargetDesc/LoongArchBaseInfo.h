//=- LoongArchBaseInfo.h - Top level definitions for LoongArch MC -*- C++ -*-=//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file contains small standalone enum definitions and helper function
// definitions for the LoongArch target useful for the compiler back-end and the
// MC libraries.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_LIB_TARGET_LOONGARCH_MCTARGETDESC_LOONGARCHBASEINFO_H
#define LLVM_LIB_TARGET_LOONGARCH_MCTARGETDESC_LOONGARCHBASEINFO_H

#include "MCTargetDesc/LoongArchMCTargetDesc.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/MC/MCInstrDesc.h"
#include "llvm/MC/SubtargetFeature.h"

namespace llvm {

// This namespace holds all of the target specific flags that instruction info
// tracks.
namespace LoongArchII {
enum {
  MO_None,
  MO_CALL,
  MO_CALL_PLT,
  MO_PCREL_HI,
  MO_PCREL_LO,
  MO_GOT_PC_HI,
  MO_GOT_PC_LO,
  // TODO: Add more flags.
};
} // end namespace LoongArchII

namespace LoongArchABI {
enum ABI {
  ABI_ILP32S,
  ABI_ILP32F,
  ABI_ILP32D,
  ABI_LP64S,
  ABI_LP64F,
  ABI_LP64D,
  ABI_Unknown
};

ABI getTargetABI(StringRef ABIName);

// Returns the register used to hold the stack pointer after realignment.
MCRegister getBPReg();
} // end namespace LoongArchABI

} // end namespace llvm

#endif // LLVM_LIB_TARGET_LOONGARCH_MCTARGETDESC_LOONGARCHBASEINFO_H
