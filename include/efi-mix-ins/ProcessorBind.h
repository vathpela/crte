// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * ProcessorBind.h - make it find ARCH/ProcessorBind.h
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_EFI_PROCESSORBIND_H
#define _CRTE_EFI_PROCESSORBIND_H

#if defined(__aarch64__)
#define MDE_CPU_AARCH64
#elif defined(__arm__)
#define MDE_CPU_ARM
#elif defined(MDE_CPU_EBC)
/* nothing here */
#elif defined(__i386__)
#define MDE_CPU_IA32
#elif defined(__riscv__) || defined(__riscv)
#if !defined(__LP64__)
#error 32-bit RISC-V is not supported
#endif
#define MDE_CPU_RISCV64
#elif defined(__x86_64__)
#define MDE_CPU_X64
#endif

#if defined(MDE_CPU_AARCH64)
#include <AArch64/ProcessorBind.h>
#elif defined(MDE_CPU_ARM)
#include <Arm/ProcessorBind.h>
#elif defined(MDE_CPU_EBC)
#include <Ebc/ProcesorBind.h>
#elif defined(MDE_CPU_IA32)
#include <Ia32/ProcessorBind.h>
#elif defined(MDE_CPU_RISCV64)
#include <Riscv64/ProcessorBind.h>
#elif defined(MDE_CPU_X64)
#include <X64/ProcessorBind.h>
#endif

#endif /* !_CRTE_EFI_PROCESSORBIND_H */
// vim:fenc=utf-8:tw=75:noet
