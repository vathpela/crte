// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * elf-x64.h - x64-specific thingimawhatsits for elf
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef __CRTE_ELF_X64_H
#define __CRTE_ELF_X64_H
#if defined(__x86_64__)

#include "elf64.h"

#define R_X86_64_NONE		0
#define REL_ARCH_NONE		R_X86_64_NONE
#define R_X86_64_RELATIVE	8
#define REL_ARCH_RELATIVE	R_X86_64_RELATIVE

#endif /* !__x86_64__ */
#endif /* !__CRTE_ELF_X64_H */
// vim:fenc=utf-8:tw=75:noet
