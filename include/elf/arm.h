// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * elf-arm.h - arm-specific thingimawhatsits for elf
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef __CRTE_ELF_ARM_H
#define __CRTE_ELF_ARM_H
#if defined(__arm__)

#include "elf32.h"

#define R_ARM_NONE		0
#define REL_ARCH_NONE		R_ARM_NONE
#define R_ARM_RELATIVE		23
#define REL_ARCH_RELATIVE	R_ARM_RELATIVE

#endif /* !__arm__ */
#endif /* !__CRTE_ELF_ARM_H */
// vim:fenc=utf-8:tw=75:noet
