// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * elf32.h - elf-ish definitions for 32-bit arches
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_ELF32_H
#define _CRTE_ELF32_H

typedef elf32_word elf_word;
typedef elf32_sword elf_sword;
typedef elf32_xword elf_xword;
typedef elf32_sxword elf_sxword;
typedef elf32_addr elf_addr;

typedef struct elf32_rel elf_rel;
typedef struct elf32_rela elf_rela;

#define ELF_R_SYM(i)		ELF32_R_SYM(i)
#define ELF_R_TYPE(i)		ELF32_R_TYPE(i)
#define ELF_R_INFO(sym, type)	ELF32_R_INFO(sym, type)

#endif /* !_CRTE_ELF32_H */
// vim:fenc=utf-8:tw=75:noet
