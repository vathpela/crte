// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * elf64.h - elf-ish definitions for 64-bit arches
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_ELF64_H
#define _CRTE_ELF64_H

typedef elf64_word elf_word;
typedef elf64_sword elf_sword;
typedef elf64_xword elf_xword;
typedef elf64_sxword elf_sxword;
typedef elf64_addr elf_addr;

typedef struct elf64_rel elf_rel;
typedef struct elf64_rela elf_rela;

#define ELF_R_SYM(i)		ELF64_R_SYM(i)
#define ELF_R_TYPE(i)		ELF64_R_TYPE(i)
#define ELF_R_INFO(sym, type)	ELF64_R_INFO(sym, type)

#endif /* !_CRTE_ELF64_H */
// vim:fenc=utf-8:tw=75:noet

