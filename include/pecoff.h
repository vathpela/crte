// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.
 * Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.
 */

#ifndef _CRTE_PECOFF_H
#define _CRTE_PECOFF_H

/*
 * PE32+ Machine type for EFI images
*/
#define IMAGE_FILE_MACHINE_UNKNOWN        0x0000
#define IMAGE_FILE_MACHINE_AM33           0x01d3
#define IMAGE_FILE_MACHINE_AMD64          0x8664
#define IMAGE_FILE_MACHINE_ARM            0x01c0
#define IMAGE_FILE_MACHINE_ARMNT          0x01c4
#define IMAGE_FILE_MACHINE_ARMTHUMB_MIXED 0x01c2
#define IMAGE_FILE_MACHINE_ARM64          0xaa64
#define IMAGE_FILE_MACHINE_EBC            0x0ebc
#define IMAGE_FILE_MACHINE_I386           0x014c
#define IMAGE_FILE_MACHINE_IA32           IMAGE_FILE_MACHINE_I386
#define IMAGE_FILE_MACHINE_IA64           0x0200
#define IMAGE_FILE_MACHINE_M32R           0x9041
#define IMAGE_FILE_MACHINE_MIPS16         0x0266
#define IMAGE_FILE_MACHINE_MIPSFPU        0x0366
#define IMAGE_FILE_MACHINE_MIPSFPU16      0x0466
#define IMAGE_FILE_MACHINE_POWERPC        0x01f0
#define IMAGE_FILE_MACHINE_POWERPCF       0x01f1
#define IMAGE_FILE_MACHINE_R4000          0x0166
#define IMAGE_FILE_MACHINE_RISCV32        0x5032
#define IMAGE_FILE_MACHINE_RISCV64        0x5064
#define IMAGE_FILE_MACHINE_RISCV128       0x5128
#define IMAGE_FILE_MACHINE_SH3            0x01a2
#define IMAGE_FILE_MACHINE_SH3DSP         0x01a3
#define IMAGE_FILE_MACHINE_SH4            0x01a6
#define IMAGE_FILE_MACHINE_SH5            0x01a8
#define IMAGE_FILE_MACHINE_THUMB          IMAGE_FILE_MACHINE_ARMTHUMB_MIXED
#define IMAGE_FILE_MACHINE_WCEMIPSV       0x0169
#define IMAGE_FILE_MACHINE_X64            IMAGE_FILE_MACHINE_AMD64

/*
 * Characteristics
 */
#define IMAGE_FILE_RELOCS_STRIPPED         0x0001
#define IMAGE_FILE_EXECUTABLE_IMAGE        0x0002
#define IMAGE_FILE_LINE_NUMS_STRIPPED      0x0004
#define IMAGE_FILE_LOCAL_SYMS_STRIPPED     0x0008
#define IMAGE_FILE_AGGRESSIVE_WS_TRIM      0x0010
#define IMAGE_FILE_LARGE_ADDRESS_AWARE     0x0020
#define IMAGE_FILE_RESERVED_0040           0x0040
#define IMAGE_FILE_BYTES_REVERSED_LO       0x0080
#define IMAGE_FILE_32BIT_MACHINE           0x0100
#define IMAGE_FILE_DEBUG_STRIPPED          0x0200
#define IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP 0x0400
#define IMAGE_FILE_NET_RUN_FROM_SAWP       0x0800
#define IMAGE_FILE_SYSTEM                  0x1000
#define IMAGE_FILE_DLL                     0x2000
#define IMAGE_FILE_UP_SYSTEM_ONLY          0x4000
#define IMAGE_FILE_BYTES_REVERSED_HI       0x8000

/*
 * PE32+ Subsystem type for EFI images
 */
#define IMAGE_SUBSYSTEM_UNKNOWN                 0
#define IMAGE_SUBSYSTEM_NATIVE                  1
#define IMAGE_SUBSYSTEM_WINDOWS_GUI             2
#define IMAGE_SUBSYSTEM_WINDOWS_CUI             3
#define IMAGE_SUBSYSTEM_POSIX_CUI               7
#define IMAGE_SUBSYSTEM_WINDOWS_CE_GUI          9
#define IMAGE_SUBSYSTEM_EFI_APPLICATION         10
#define IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER 11
#define IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER      12
#define IMAGE_SUBSYSTEM_EFI_ROM                 13
#define IMAGE_SUBSYSTEM_XBOX                    14

/*
 * DLL Charactaristics
 */
#define IMAGE_DLLCHARACTERISTICS_RESERVED_0001         0x0001
#define IMAGE_DLLCHARACTERISTICS_RESERVED_0002         0x0002
#define IMAGE_DLLCHARACTERISTICS_RESERVED_0004         0x0004
#define IMAGE_DLLCHARACTERISTICS_RESERVED_0008         0x0008
#define IMAGE_DLLCHARACTERISTICS_RESERVED_0010         0x0010
#define IMAGE_DLLCHARACTERISTICS_HIGH_ENTROPY_VA       0x0020
#define IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE          0x0040
#define IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY       0x0080
#define IMAGE_DLLCHARACTERISTICS_NX_COMPAT             0x0100
#define IMAGE_DLLCHARACTERISTICS_NO_ISOLATION          0x0400
#define IMAGE_DLLCHARACTERISTICS_NO_SEH                0x0400
#define IMAGE_DLLCHARACTERISTICS_NO_BIND               0x0800
#define IMAGE_DLLCHARACTERISTICS_APPCONTAINER          0x1000
#define IMAGE_DLLCHARACTERISTICS_WDM_DRIVER            0x2000
#define IMAGE_DLLCHARACTERISTICS_GUARD_CF              0x4000
#define IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE 0x8000

/*
 * Section Flags Values
 */
#define IMAGE_SCN_RESERVED_1             0x00000001
#define IMAGE_SCN_RESERVED_2             0x00000002
#define IMAGE_SCN_RESERVED_4             0x00000004
#define IMAGE_SCN_TYPE_NO_PAD            0x00000008 // Reserved.
#define IMAGE_SCN_RESERVED_10            0x00000010
#define IMAGE_SCN_CNT_CODE               0x00000020
#define IMAGE_SCN_CNT_INITIALIZED_DATA   0x00000040
#define IMAGE_SCN_CNT_UNINITIALIZED_DATA 0x00000080
#define IMAGE_SCN_LNK_OTHER              0x00000100 // Reserved.
#define IMAGE_SCN_LNK_INFO               0x00000200
#define IMAGE_SCN_LNK_RESERVED_400       0x00000400
#define IMAGE_SCN_LNK_REMOVE             0x00000800
#define IMAGE_SCN_LNK_COMDAT             0x00001000
#define IMAGE_SCN_GPREL                  0x00008000 // reserved
// yes, the spec has a 2 here ----------------v
#define IMAGE_SCN_MEM_PURGEABLE          0x00020000 // reserved
#define IMAGE_SCN_MEM_16BIT              0x00020000 // reserved
#define IMAGE_SCN_MEM_LOCKED             0x00040000 // reserved
#define IMAGE_SCN_MEM_PRELOAD            0x00080000 // reserved
#define IMAGE_SCN_ALIGN_1BYTES           0x00100000
#define IMAGE_SCN_ALIGN_2BYTES           0x00200000
#define IMAGE_SCN_ALIGN_4BYTES           0x00300000
#define IMAGE_SCN_ALIGN_8BYTES           0x00400000
#define IMAGE_SCN_ALIGN_16BYTES          0x00500000
#define IMAGE_SCN_ALIGN_32BYTES          0x00600000
#define IMAGE_SCN_ALIGN_64BYTES          0x00700000
#define IMAGE_SCN_ALIGN_128BYTES         0x00800000
#define IMAGE_SCN_ALIGN_256BYTES         0x00900000
#define IMAGE_SCN_ALIGN_512BYTES         0x00a00000
#define IMAGE_SCN_ALIGN_1024BYTES        0x00b00000
#define IMAGE_SCN_ALIGN_2048BYTES        0x00c00000
#define IMAGE_SCN_ALIGN_4096BYTES        0x00d00000
#define IMAGE_SCN_ALIGN_8129BYTES        0x00e00000
#define IMAGE_SCN_LNK_NRELOC_OVFL        0x01000000
#define IMAGE_SCN_MEM_DISCARDABLE        0x02000000
#define IMAGE_SCN_MEM_NOT_CACHED         0x04000000
#define IMAGE_SCN_MEM_NOT_PAGED          0x08000000
#define IMAGE_SCN_MEM_SHARED             0x10000000
#define IMAGE_SCN_MEM_EXECUTE            0x20000000
#define IMAGE_SCN_MEM_READ               0x40000000
#define IMAGE_SCN_MEM_WRITE              0x80000000

/*
 * Relocation types
 */
#define IMAGE_REL_AMD64_ABSOLUTE 0x0000
#define IMAGE_REL_AMD64_ADDR64   0x0001
#define IMAGE_REL_AMD64_ADDR32   0x0002
#define IMAGE_REL_AMD64_ADDR32N  0x0003
#define IMAGE_REL_AMD64_REL32    0x0004
#define IMAGE_REL_AMD64_REL32_1  0x0005
#define IMAGE_REL_AMD64_REL32_2  0x0006
#define IMAGE_REL_AMD64_REL32_3  0x0007
#define IMAGE_REL_AMD64_REL32_4  0x0008
#define IMAGE_REL_AMD64_REL32_5  0x0009
#define IMAGE_REL_AMD64_SECTION  0x000a
#define IMAGE_REL_AMD64_SECREL   0x000b
#define IMAGE_REL_AMD64_SECREL7  0x000c
#define IMAGE_REL_AMD64_TOKEN    0x000d
#define IMAGE_REL_AMD64_SREL32   0x000e
#define IMAGE_REL_AMD64_PAIR     0x000f
#define IMAGE_REL_AMD64_SSPAN32  0x0010

#define IMAGE_REL_ALPHA_ABSOLUTE       0x0000
#define IMAGE_REL_ALPHA_REFLONG        0x0001
#define IMAGE_REL_ALPHA_REFQUAD        0x0002
#define IMAGE_REL_ALPHA_GPREL32        0x0003
#define IMAGE_REL_ALPHA_LITERAL        0x0004
#define IMAGE_REL_ALPHA_LITUSE         0x0005
#define IMAGE_REL_ALPHA_GPDISP         0x0006
#define IMAGE_REL_ALPHA_BRADDR         0x0007
#define IMAGE_REL_ALPHA_HINT           0x0008
#define IMAGE_REL_ALPHA_INLINE_REFLONG 0x0009
#define IMAGE_REL_ALPHA_REFHI          0x000A
#define IMAGE_REL_ALPHA_REFLO          0x000B
#define IMAGE_REL_ALPHA_PAIR           0x000C
#define IMAGE_REL_ALPHA_MATCH          0x000D
#define IMAGE_REL_ALPHA_SECREL         0x000F
#define IMAGE_REL_ALPHA_REFLONGNB      0x0010
#define IMAGE_REL_ALPHA_SECRELLO       0x0011
#define IMAGE_REL_ALPHA_SECRELHI       0x0012
#define IMAGE_REL_ALPHA_REFQ3          0x0013
#define IMAGE_REL_ALPHA_REFQ2          0x0014
#define IMAGE_REL_ALPHA_REFQ1          0x0015
#define IMAGE_REL_ALPHA_GPRELLO        0x0016
#define IMAGE_REL_ALPHA_GPRELHI        0x0017

#define IMAGE_REL_ARM_ABSOLUTE       0x0000
#define IMAGE_REL_ARM_ADDR32         0x0001
#define IMAGE_REL_ARM_ADDR32NB       0x0002
#define IMAGE_REL_ARM_BRANCH24       0x0003
#define IMAGE_REL_ARM_BRANCH11       0x0004
#define IMAGE_REL_ARM_SECTION        0x000e
#define IMAGE_REL_ARM_SECREL         0x000f
#define IMAGE_REL_ARM_MOV32          0x0010
#define IMAGE_REL_ARM_THUMB_MOV32    0x0011
#define IMAGE_REL_ARM_THUMB_BRANCH20 0x0012
#define IMAGE_REL_ARM_THUMB_BRANCH24 0x0014
#define IMAGE_REL_ARM_THUMB_BLX23    0x0015
#define IMAGE_REL_ARM_PAIR           0x0016

#define IMAGE_REL_ARM64_ABSOLUTE       0x0000
#define IMAGE_REL_ARM64_ADDR32         0x0001
#define IMAGE_REL_ARM64_ADDR32NB       0x0002
#define IMAGE_REL_ARM64_BRANCH26       0x0003
#define IMAGE_REL_ARM64_PAGEBASE_REL21 0x0004
#define IMAGE_REL_ARM64_REL21          0x0005
#define IMAGE_REL_ARM64_PAGEOFFSET_12A 0x0006
#define IMAGE_REL_ARM64_PAGEOFFSET_12L 0x0007
#define IMAGE_REL_ARM64_SECREL         0x0008
#define IMAGE_REL_ARM64_SECREL_LOW12A  0x0009
#define IMAGE_REL_ARM64_SECREL_HIGH12A 0x000a
#define IMAGE_REL_ARM64_SECREL_LOW12L  0x000b
#define IMAGE_REL_ARM64_TOKEN          0x000c
#define IMAGE_REL_ARM64_SECTION        0x000d
#define IMAGE_REL_ARM64_ADDR64         0x000e

#define IMAGE_REL_I386_ABSOLUTE 0x0000
#define IMAGE_REL_I386_DIR16    0x0001
#define IMAGE_REL_I386_REL16    0x0002
#define IMAGE_REL_I386_DIR32    0x0006
#define IMAGE_REL_I386_DIR32NB  0x0007
#define IMAGE_REL_I386_SEG12    0x0009
#define IMAGE_REL_I386_SECTION  0x000a
#define IMAGE_REL_I386_SECREL   0x000b
#define IMAGE_REL_I386_TOKEN    0x000c
#define IMAGE_REL_I386_SECREL7  0x000d
#define IMAGE_REL_I386_REL32    0x0014

#define IMAGE_REL_IA64_ABSOLUTE   0x0000
#define IMAGE_REL_IA64_IMM14      0x0001
#define IMAGE_REL_IA64_IMM22      0x0002
#define IMAGE_REL_IA64_IMM64      0x0003
#define IMAGE_REL_IA64_DIR32      0x0004
#define IMAGE_REL_IA64_DIR64      0x0005
#define IMAGE_REL_IA64_PCREL21B   0x0006
#define IMAGE_REL_IA64_PCREL21M   0x0007
#define IMAGE_REL_IA64_PCREL21F   0x0008
#define IMAGE_REL_IA64_GPREL22    0x0009
#define IMAGE_REL_IA64_LTOFF22    0x000a
#define IMAGE_REL_IA64_SECTION    0x000b
#define IMAGE_REL_IA64_SECREL22   0x000c
#define IMAGE_REL_IA64_SECREL64I  0x000d
#define IMAGE_REL_IA64_SECREL32   0x000e
#define IMAGE_REL_IA64_DIR32NB    0x0010
#define IMAGE_REL_IA64_SREL14     0x0011
#define IMAGE_REL_IA64_SREL22     0x0012
#define IMAGE_REL_IA64_SREL32     0x0013
#define IMAGE_REL_IA64_UREL32     0x0014
#define IMAGE_REL_IA64_PCREL60X   0x0015
#define IMAGE_REL_IA64_PCREL60B   0x0016
#define IMAGE_REL_IA64_PCREL60F   0x0017
#define IMAGE_REL_IA64_PCREL60I   0x0018
#define IMAGE_REL_IA64_PCREL60M   0x0019
#define IMAGE_REL_IA64_IMMGPREL64 0x001a
#define IMAGE_REL_IA64_TOKEN      0x001b
#define IMAGE_REL_IA64_GPREL32    0x001c
#define IMAGE_REL_IA64_ADDEND     0x001f

#define IMAGE_REL_MIPS_ABSOLUTE  0x0000
#define IMAGE_REL_MIPS_REFHALF   0x0001
#define IMAGE_REL_MIPS_REFWORD   0x0002
#define IMAGE_REL_MIPS_JMPADDR   0x0003
#define IMAGE_REL_MIPS_REFHI     0x0004
#define IMAGE_REL_MIPS_REFLO     0x0005
#define IMAGE_REL_MIPS_GPREL     0x0006
#define IMAGE_REL_MIPS_LITERAL   0x0007
#define IMAGE_REL_MIPS_SECTION   0x000a
#define IMAGE_REL_MIPS_SECREL    0x000b
#define IMAGE_REL_MIPS_SECRELLO  0x000c
#define IMAGE_REL_MIPS_SECRELHI  0x000d
#define IMAGE_REL_MIPS_JMPADDR16 0x0010
#define IMAGE_REL_MIPS_REFWORDNB 0x0022
#define IMAGE_REL_MIPS_PAIR      0x0025

#define IMAGE_REL_M32R_ABSOLUTE  0x0000
#define IMAGE_REL_M32R_ADDR32    0x0001
#define IMAGE_REL_M32R_ADDR32NB  0x0002
#define IMAGE_REL_M32R_ADDR24    0x0003
#define IMAGE_REL_M32R_GPREL16   0x0004
#define IMAGE_REL_M32R_PCREL24   0x0005
#define IMAGE_REL_M32R_PCREL16   0x0006
#define IMAGE_REL_M32R_PCREL8    0x0007
#define IMAGE_REL_M32R_REFHALF   0x0008
#define IMAGE_REL_M32R_REFHI     0x0009
#define IMAGE_REL_M32R_REFLO     0x000a
#define IMAGE_REL_M32R_PAIR      0x000b
#define IMAGE_REL_M32R_SECTION   0x000c
#define IMAGE_REL_M32R_SECREL    0x000d
#define IMAGE_REL_M32R_TOKEN     0x000e

#define IMAGE_REL_PPC_ABSOLUTE 0x0000
#define IMAGE_REL_PPC_ADDR64   0x0001
#define IMAGE_REL_PPC_ADDR32   0x0002
#define IMAGE_REL_PPC_ADDR24   0x0003
#define IMAGE_REL_PPC_ADDR16   0x0004
#define IMAGE_REL_PPC_ADDR14   0x0005
#define IMAGE_REL_PPC_REL24    0x0006
#define IMAGE_REL_PPC_REL14    0x0007
#define IMAGE_REL_PPC_ADDR32NB 0x000a
#define IMAGE_REL_PPC_SECREL   0x000b
#define IMAGE_REL_PPC_SECTION  0x000c
#define IMAGE_REL_PPC_SECREL16 0x000f
#define IMAGE_REL_PPC_REFHI    0x0010
#define IMAGE_REL_PPC_REFLO    0x0011
#define IMAGE_REL_PPC_PAIR     0x0012
#define IMAGE_REL_PPC_SECRELLO 0x0013
#define IMAGE_REL_PPC_GPREL    0x0015
#define IMAGE_REL_PPC_TOKEN    0x0016

#define IMAGE_REL_SH3_ABSOLUTE        0x0000
#define IMAGE_REL_SH3_DIRECT16        0x0001
#define IMAGE_REL_SH3_DIRECT32        0x0002
#define IMAGE_REL_SH3_DIRECT8         0x0003
#define IMAGE_REL_SH3_DIRECT8_WORD    0x0004
#define IMAGE_REL_SH3_DIRECT8_LONG    0x0005
#define IMAGE_REL_SH3_DIRECT4         0x0006
#define IMAGE_REL_SH3_DIRECT4_WORD    0x0007
#define IMAGE_REL_SH3_DIRECT4_LONG    0x0008
#define IMAGE_REL_SH3_PCREL8_WORD     0x0009
#define IMAGE_REL_SH3_PCREL8_LONG     0x000a
#define IMAGE_REL_SH3_PCREL12_WORD    0x000b
#define IMAGE_REL_SH3_STARTOF_SECTION 0x000c
#define IMAGE_REL_SH3_SIZEOF_SECTION  0x000d
#define IMAGE_REL_SH3_SECTION         0x000e
#define IMAGE_REL_SH3_SECREL          0x000f
#define IMAGE_REL_SH3_DIRECT32_NB     0x0010
#define IMAGE_REL_SH3_GPREL4_LONG     0x0011
#define IMAGE_REL_SH3_TOKEN           0x0012
#define IMAGE_REL_SHM_PCRELPT         0x0013
#define IMAGE_REL_SHM_REFLO           0x0014
#define IMAGE_REL_SHM_REFHALF         0x0015
#define IMAGE_REL_SHM_RELLO           0x0016
#define IMAGE_REL_SHM_RELHALF         0x0017
#define IMAGE_REL_SHM_PAIR            0x0018
#define IMAGE_REL_SHM_NOMODE          0x8000

#define IMAGE_REL_RISCV_ABSOLUTE 0x0000 // not in the spec, but...

/*
 * Symbols have a section number of the section in which they are
 * defined. Otherwise, section numbers have the following meanings:
 */
#define IMAGE_SYM_UNDEFINED ((uint16_t)0x0000)
#define IMAGE_SYM_ABSOLUTE  ((uint16_t)0xffff)
#define IMAGE_SYM_DEBUG     ((uint16_t)0xfffe)

/*
 * Symbol Type (fundamental) values.
 */
#define IMAGE_SYM_TYPE_NULL   0
#define IMAGE_SYM_TYPE_VOID   1
#define IMAGE_SYM_TYPE_CHAR   2 // 1-byte
#define IMAGE_SYM_TYPE_SHORT  3 // 2-byte
#define IMAGE_SYM_TYPE_INT    4 // 4-byte normally
#define IMAGE_SYM_TYPE_LONG   5 // 4-byte
#define IMAGE_SYM_TYPE_FLOAT  6 // 4-byte
#define IMAGE_SYM_TYPE_DOUBLE 7 // 8-byte
#define IMAGE_SYM_TYPE_STRUCT 8
#define IMAGE_SYM_TYPE_UNION  9
#define IMAGE_SYM_TYPE_ENUM   10
#define IMAGE_SYM_TYPE_MOE    11 // member of enumeration.
#define IMAGE_SYM_TYPE_BYTE   12
#define IMAGE_SYM_TYPE_WORD   13 // 2-byte
#define IMAGE_SYM_TYPE_UINT   14 // 4-byte normally
#define IMAGE_SYM_TYPE_DWORD  15 // 4-byte

/*
 * Symbol Type (derived) values.
 */
#define IMAGE_SYM_DTYPE_NULL     0 // no derived type.
#define IMAGE_SYM_DTYPE_POINTER  1
#define IMAGE_SYM_DTYPE_FUNCTION 2
#define IMAGE_SYM_DTYPE_ARRAY    3

/*
 * Storage classes.
 */
#define IMAGE_SYM_CLASS_END_OF_FUNCTION  ((uint8_t)0xff)
#define IMAGE_SYM_CLASS_NULL             0
#define IMAGE_SYM_CLASS_AUTOMATIC        1
#define IMAGE_SYM_CLASS_EXTERNAL         2
#define IMAGE_SYM_CLASS_STATIC           3
#define IMAGE_SYM_CLASS_REGISTER         4
#define IMAGE_SYM_CLASS_EXTERNAL_DEF     5
#define IMAGE_SYM_CLASS_LABEL            6
#define IMAGE_SYM_CLASS_UNDEFINED_LABEL  7
#define IMAGE_SYM_CLASS_MEMBER_OF_STRUCT 8
#define IMAGE_SYM_CLASS_ARGUMENT         9
#define IMAGE_SYM_CLASS_STRUCT_TAG       10
#define IMAGE_SYM_CLASS_MEMBER_OF_UNION  11
#define IMAGE_SYM_CLASS_UNION_TAG        12
#define IMAGE_SYM_CLASS_TYPE_DEFINITION  13
#define IMAGE_SYM_CLASS_UNDEFINED_STATIC 14
#define IMAGE_SYM_CLASS_ENUM_TAG         15
#define IMAGE_SYM_CLASS_MEMBER_OF_ENUM   16
#define IMAGE_SYM_CLASS_REGISTER_PARAM   17
#define IMAGE_SYM_CLASS_BIT_FIELD        18
#define IMAGE_SYM_CLASS_BLOCK            100
#define IMAGE_SYM_CLASS_FUNCTION         101
#define IMAGE_SYM_CLASS_END_OF_STRUCT    102
#define IMAGE_SYM_CLASS_FILE             103
#define IMAGE_SYM_CLASS_SECTION          104
#define IMAGE_SYM_CLASS_WEAK_EXTERNAL    105
#define IMAGE_SYM_CLASS_CLR_TOKEN        106

/*
 * Communal selection types.
 */
#define IMAGE_COMDAT_SELECT_NODUPLICATES 1
#define IMAGE_COMDAT_SELECT_ANY          2
#define IMAGE_COMDAT_SELECT_SAME_SIZE    3
#define IMAGE_COMDAT_SELECT_EXACT_MATCH  4
#define IMAGE_COMDAT_SELECT_ASSOCIATIVE  5

#define WIN_CERT_REVISION_1_0 0x0010
#define WIN_CERT_REVISION_2_0 0x0020

#define WIN_CERT_TYPE_X509             0x0001
#define WIN_CERT_TYPE_PKCS_SIGNED_DATA 0x0002
#define WIN_CERT_TYPE_RESERVED_1       0x0003
#define WIN_CERT_TYPE_TS_STACK_SIGNED  0x0004

#define SCN_FLAGS_BSS (IMAGE_SCN_CNT_UNINITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE)
#define SCN_FLAGS_CORMETA IMAGE_SCN_LINK_INFO
#define SCN_FLAGS_DATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE)
#define SCN_FLAGS_DEBUGF (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_DISCARDABLE)
#define SCN_FLAGS_DEBUGP (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_DISCARDABLE)
#define SCN_FLAGS_DEBUGS (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_DISCARDABLE)
#define SCN_FLAGS_DEBUGT (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_DISCARDABLE)
#define SCN_FLAGS_DRECTIVE IMAGE_SCN_LNK_INFO
#define SCN_FLAGS_EDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ)
#define SCN_FLAGS_IDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE)
#define SCN_FLAGS_IDLSYM IMAGE_SCN_LNK_INFO
#define SCN_FLAGS_PDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ)
#define SCN_FLAGS_RDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ)
#define SCN_FLAGS_RELOC  (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_DISCARDABLE)
#define SCN_FLAGS_RSRC  (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ)
#define SCN_FLAGS_SBSS  (IMAGE_SCN_CNT_UNINITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE|IMAGE_SCN_GPREL)
#define SCN_FLAGS_SDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE|IMAGE_SCN_GPREL)
#define SCN_FLAGS_SRDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE _SCN_GPREL)
#define SCN_FLAGS_SXDATA (IMAGE_SCN_LNK_INFO)
#define SCN_FLAGS_TEXT (IMAGE_SCN_CNT_CODE|IMAGE_SCN_MEM_EXECUTE|IMAGE_SCN_MEM_READ)
#define SCN_FLAGS_TLS (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE)
#define SCN_FLAGS_VSDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_WRITE)
#define SCN_FLAGS_XDATA (IMAGE_SCN_CNT_INITIALIZED_DATA|IMAGE_SCN_MEM_READ)

/*
 * Debug information type...
 */
#define IMAGE_DEBUG_TYPE_UNKNOWN 0
#define IMAGE_DEBUG_TYPE_COFF 1
#define IMAGE_DEBUG_TYPE_CODEVIEW 2
#define IMAGE_DEBUG_TYPE_FPO 3
#define IMAGE_DEBUG_TYPE_MISC 4
#define IMAGE_DEBUG_TYPE_EXCEPTION 5
#define IMAGE_DEBUG_TYPE_FIXUP 6
#define IMAGE_DEBUG_TYPE_OMAP_TO_SRC 7
#define IMAGE_DEBUG_TYPE_OMAP_FROM_SRC 8
#define IMAGE_DEBUG_TYPE_BORLAND 9
#define IMAGE_DEBUG_TYPE_RESERVED10 10
#define IMAGE_DEBUG_TYPE_CLSID 11
#define IMAGE_DEBUG_TYPE_REPRO 16

#define FRAME_FPO  0
#define FRAME_TRAP 1
#define FRAME_TSS  2

/*
 * Based relocation types.
 */
#define IMAGE_REL_BASED_ABSOLUTE       0
#define IMAGE_REL_BASED_HIGH           1
#define IMAGE_REL_BASED_LOW            2
#define IMAGE_REL_BASED_HIGHLOW        3
#define IMAGE_REL_BASED_HIGHADJ        4
#define IMAGE_REL_BASED_MIPS_JMPADDR   5
#define IMAGE_REL_BASED_ARM_MOV32      5
#define IMAGE_REL_BASED_RISCV_HIGH20   5
#define IMAGE_REL_BASED_RESERVED_6     6
#define IMAGE_REL_BASED_THUMB_MOV32    7
#define IMAGE_REL_BASED_RISCV_LOW12I   7
#define IMAGE_REL_BASED_RISCV_LOW12S   8
#define IMAGE_REL_BASED_IA64_IMM64     9
#define IMAGE_REL_BASED_MIPS_JMPADDR16 9
#define IMAGE_REL_BASED_DIR64          10

#define IMPORT_CODE  0
#define IMPORT_DATA  1
#define IMPORT_CONST 2

#define IMPORT_ORDINAL         0
#define IMPORT_NAME            1
#define IMPORT_NAME_NOPREFIX   2
#define IMPORT_NAME_UNDECORATE 3

/*
 * EXE file formats
 */
#define IMAGE_DOS_SIGNATURE    "MZ"
#define IMAGE_OS2_SIGNATURE    "NE"
#define IMAGE_OS2_SIGNATURE_LE "LE"
#define IMAGE_NT_SIGNATURE     "PE\000\000"

/*
 * Size of IMAGE_FILE_HEADER.
 */
#define IMAGE_SIZEOF_FILE_HEADER 20

/*
 * Directory Entries
 */
#define IMAGE_DIRECTORY_ENTRY_EXPORT      0
#define IMAGE_DIRECTORY_ENTRY_IMPORT      1
#define IMAGE_DIRECTORY_ENTRY_RESOURCE    2
#define IMAGE_DIRECTORY_ENTRY_EXCEPTION   3
#define IMAGE_DIRECTORY_ENTRY_SECURITY    4
#define IMAGE_DIRECTORY_ENTRY_BASERELOC   5
#define IMAGE_DIRECTORY_ENTRY_DEBUG       6
#define IMAGE_DIRECTORY_ENTRY_COPYRIGHT   7
#define IMAGE_DIRECTORY_ENTRY_GLOBALPTR   8
#define IMAGE_DIRECTORY_ENTRY_TLS         9
#define IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG 10

#define PE_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES 16

#define IMAGE_NT_OPTIONAL_HDR32_MAGIC 0x10b
#define IMAGE_NT_OPTIONAL_HDR64_MAGIC 0x20b

/*
 * Length of short_name.
 */
#define IMAGE_SIZEOF_SHORT_NAME 8

/*
 * Size of IMAGE_SECTION_HEADER.
 */
#define IMAGE_SIZEOF_SECTION_HEADER 40
/*
 * Size of a Symbol Table Record.
 */
#define IMAGE_SIZEOF_SYMBOL 18

/*
 * type packing constants
 */
#define IMAGE_N_BTMASK 017
#define IMAGE_N_TMASK  060
#define IMAGE_N_TMASK1 0300
#define IMAGE_N_TMASK2 0360
#define IMAGE_N_BTSHFT 4
#define IMAGE_N_TSHIFT 2

#define IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY 1
#define IMAGE_WEAK_EXTERN_SEARCH_LIBRARY   2
#define IMAGE_WEAK_EXTERN_SEARCH_ALIAS     3

/*
 * Archive format.
 */
#define IMAGE_ARCHIVE_START_SIZE       8
#define IMAGE_ARCHIVE_START            "!<arch>\n"
#define IMAGE_ARCHIVE_END              "`\n"
#define IMAGE_ARCHIVE_PAD              "\n"
#define IMAGE_ARCHIVE_LINKER_MEMBER    "/               "
#define IMAGE_ARCHIVE_LONGNAMES_MEMBER "//              "

#define IMAGE_ORDINAL_FLAG       0x80000000ull
#define IMAGE_SNAP_BY_ORDINAL(o) ((o & IMAGE_ORDINAL_FLAG) != 0)
#define IMAGE_ORDINAL(o)         (o & 0xffff)

#define CODEVIEW_SIGNATURE_NB10 "NB10"
#define CODEVIEW_SIGNATURE_RSDS "RSDS"
#define CODEVIEW_SIGNATURE_MTOC "MTOC"

/*
 * Example:
 * SECTION(".text\0\0\0",
 *         _start - ImageBase, _data - _start,
 *         _start - ImageBase, _data - _start,
 *         IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_EXECUTE|IMAGE_SCN_CNT_CODE)
 * ->
 *	.ascii	".text\0\0\0"
 *	.long	_data - _start		// VirtualSize
 *	.long	_start - ImageBase	// VirtualAddress
 *	.long	_data - _start		// SizeOfRawData
 *	.long	_start - ImageBase	// PointerToRawData
 *
 *	.long	0		// PointerToRelocations (0 for executables)
 *	.long	0		// PointerToLineNumbers (0 for executables)
 *	.short	0		// NumberOfRelocations  (0 for executables)
 *	.short	0		// NumberOfLineNumbers  (0 for executables)
 *	.long	0x60000020	// Characteristics (section flags)
 */
#define SECTION(name, vaddr, vsize, faddr, fsize, flags) \
	.ascii	name ; \
	.long vsize ; \
	.long vaddr ; \
	.long fsize ; \
	.long faddr ; \
	.long 0 ; \
	.long 0 ; \
	.short 0 ; \
	.short 0 ; \
	.long flags ;

/*
 * Example:
 * LOAD_SECTION(".text\0\0\0", _start - ImageBase, _data - _start,
 *	   IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_EXECUTE|IMAGE_SCN_CNT_CODE)
 * ->
 * SECTION(".text\0\0\0",
 *         _start - ImageBase, _data - _start,
 *         _start - ImageBase, _data - _start,
 *         IMAGE_SCN_MEM_READ|IMAGE_SCN_MEM_EXECUTE|IMAGE_SCN_CNT_CODE)
 */
#define LOAD_SECTION(name, address, size, flags) \
	SECTION(name, address, size, address, size, flags)

#ifndef __ASSEMBLY__
/*
 * PE images can start with an optional DOS header, so if an image is run
 * under DOS it can print an error message.
 */
typedef struct {
	uint16_t e_magic;    // Magic number.
	uint16_t e_cblp;     // Bytes on last page of file.
	uint16_t e_cp;       // Pages in file.
	uint16_t e_crlc;     // Relocations.
	uint16_t e_cparhdr;  // Size of header in paragraphs.
	uint16_t e_minalloc; // Minimum extra paragraphs needed.
	uint16_t e_maxalloc; // Maximum extra paragraphs needed.
	uint16_t e_ss;       // Initial (relative) SS value.
	uint16_t e_sp;       // Initial SP value.
	uint16_t e_csum;     // Checksum.
	uint16_t e_ip;       // Initial IP value.
	uint16_t e_cs;       // Initial (relative) CS value.
	uint16_t e_lfarlc;   // File address of relocation table.
	uint16_t e_ovno;     // Overlay number.
	uint16_t e_res[4];   // Reserved words.
	uint16_t e_oemid;    // OEM identifier (for e_oeminfo).
	uint16_t e_oeminfo;  // OEM information; e_oemid specific.
	uint16_t e_res2[10]; // Reserved words.
	uint32_t e_lfanew;   // File address of new exe header.
} image_dos_header_t;

/*
 * COFF File Header (Object and Image).
 */
typedef struct {
	uint16_t machine;
	uint16_t number_of_sections;
	uint32_t time_date_stamp;
	uint32_t pointer_to_symbol_table;
	uint32_t number_of_symbols;
	uint16_t size_of_optional_header;
	uint16_t characteristics;
} image_file_header_t;

/*
 * Header Data Directories.
 */
typedef struct {
	uint32_t virtual_address;
	uint32_t size;
} image_data_directory_t;

/*
 * Optional Header Standard Fields for PE32.
 */
typedef struct {
	uint16_t magic;
	uint8_t major_linker_version;
	uint8_t minor_linker_version;
	uint32_t size_of_code;
	uint32_t size_of_initialized_data;
	uint32_t size_of_uninitialized_data;
	uint32_t address_of_entry_point;
	uint32_t base_of_code;
	uint32_t base_of_data; // PE32 contains this additional field, which is absent in PE32+.
	uint32_t image_base;
	uint32_t section_alignment;
	uint32_t file_alignment;
	uint16_t major_operating_system_version;
	uint16_t minor_operating_system_version;
	uint16_t major_image_version;
	uint16_t minor_image_version;
	uint16_t major_subsystem_version;
	uint16_t minor_subsystem_version;
	uint32_t win32_version_value;
	uint32_t size_of_image;
	uint32_t size_of_headers;
	uint32_t checksum;
	uint16_t subsystem;
	uint16_t dll_characteristics;
	uint32_t size_of_stack_reserve;
	uint32_t size_of_stack_commit;
	uint32_t size_of_heap_reserve;
	uint32_t size_of_heap_commit;
	uint32_t loader_flags;
	uint32_t number_of_rva_and_sizes;
	union {
		struct {
			image_data_directory_t export;
			image_data_directory_t import;
			image_data_directory_t resource;
			image_data_directory_t exception;
			image_data_directory_t security;
			image_data_directory_t basereloc;
			image_data_directory_t debug;
			image_data_directory_t copyright;
			image_data_directory_t globalptr;
			image_data_directory_t tls;
			image_data_directory_t load_config;
		};
		image_data_directory_t data_directory[PE_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES];
	};
} image_optional_header_32_t;

/*
 * Optional Header Standard Fields for PE32+.
 */
typedef struct {
	uint16_t magic;
	uint8_t major_linker_version;
	uint8_t minor_linker_version;
	uint32_t size_of_code;
	uint32_t size_of_initialized_data;
	uint32_t size_of_uninitialized_data;
	uint32_t address_of_entry_point;
	uint32_t base_of_code;
	uint64_t image_base;
	uint32_t section_alignment;
	uint32_t file_alignment;
	uint16_t major_operating_system_version;
	uint16_t minor_operating_system_version;
	uint16_t major_image_version;
	uint16_t minor_image_version;
	uint16_t major_subsystem_version;
	uint16_t minor_subsystem_version;
	uint32_t win32_version_value;
	uint32_t size_of_image;
	uint32_t size_of_headers;
	uint32_t checksum;
	uint16_t subsystem;
	uint16_t dll_characteristics;
	uint64_t size_of_stack_reserve;
	uint64_t size_of_stack_commit;
	uint64_t size_of_heap_reserve;
	uint64_t size_of_heap_commit;
	uint32_t loader_flags;
	uint32_t number_of_rva_and_sizes;
	union {
		struct {
			image_data_directory_t export;
			image_data_directory_t import;
			image_data_directory_t resource;
			image_data_directory_t exception;
			image_data_directory_t security;
			image_data_directory_t basereloc;
			image_data_directory_t debug;
			image_data_directory_t copyright;
			image_data_directory_t globalptr;
			image_data_directory_t tls;
			image_data_directory_t load_config;
		};
		image_data_directory_t data_directory[PE_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES];
	};
} image_optional_header_64_t;

typedef struct {
	uint8_t signature[4];
	image_file_header_t file_header;
	image_optional_header_32_t optional_header;
} image_nt_headers_32_t;

typedef struct {
	uint8_t signature[4];
	image_file_header_t file_header;
	image_optional_header_64_t optional_header;
} image_nt_headers_64_t;

/*
 * Section Table. This table immediately follows the optional header.
 */
typedef struct {
	uint8_t name[IMAGE_SIZEOF_SHORT_NAME];
	union {
		uint32_t physical_address;
		uint32_t virtual_size;
	} Misc;
	uint32_t virtual_address;
	uint32_t size_of_raw_data;
	uint32_t pointer_to_raw_data;
	uint32_t pointer_to_relocations;
	uint32_t pointer_to_linenumbers;
	uint16_t number_of_relocations;
	uint16_t number_of_linenumbers;
	uint32_t characteristics;
} image_section_header_t;

/*
 * Relocation format.
 */
typedef struct {
	uint32_t virtual_address;
	uint32_t symbol_table_index;
	uint16_t type;
} image_relocation_t;

/*
 * Based relocation format.
 */
typedef struct {
	uint32_t virtual_address;
	uint32_t size_of_block;
} image_base_relocation_t;

/*
 * Line number format.
 */
typedef struct {
	union {
		uint32_t symbol_table_index; // Symbol table index of function name if Linenumber is 0.
		uint32_t virtual_address; // Virtual address of line number.
	} type;
	uint16_t linenumber; // Line number.
} image_line_number_t;

/*
 * Symbol table
 */
typedef struct {
	union {
		char short_name[8];
		struct {
			uint32_t zeroes;
			uint32_t offset;
		};
	} name;
	uint32_t value;
	uint16_t section_number;
	uint16_t type;
	uint8_t storage_class;
	uint8_t number_of_aux_symbols;
} image_symbol_table_t;

/*
 * Archive Member Headers
 */
typedef struct {
	uint8_t name[16];      // File member name - `/' terminated.
	uint8_t date[12];      // File member date - decimal.
	uint8_t user_id[6];    // File member user id - decimal.
	uint8_t group_id[6];   // File member group id - decimal.
	uint8_t mode[8];       // File member mode - octal.
	uint8_t size[10];      // File member size - decimal.
	uint8_t end_header[2]; // String to end header. (0x60 0x0a).
} image_archive_member_header_t;

/*
 * DLL Support
 */

/*
 * Export Directory Table.
 */
typedef struct {
	uint32_t characteristics;
	uint32_t time_date_stamp;
	uint16_t major_version;
	uint16_t minor_version;
	uint32_t name;
	uint32_t base;
	uint32_t number_of_functions;
	uint32_t number_of_names;
	uint32_t address_of_functions;
	uint32_t address_of_names;
	uint32_t address_of_name_ordinals;
} image_export_directory_t;

/*
 * Hint/Name Table.
 */
typedef struct {
	uint16_t hint;
	uint8_t name[1];
} image_import_by_name_t;

/*
 * Import Address Table RVA (Thunk Table).
 */
typedef struct {
	union {
		uint32_t function;
		uint32_t ordinal;
		image_import_by_name_t *address_of_data;
	} u1;
} image_thunk_data_t;

/*
 * Import Directory Table
 */
typedef struct {
	uint32_t characteristics;
	uint32_t time_date_stamp;
	uint32_t forwarder_chain;
	uint32_t name;
	image_thunk_data_t *first_thunk;
} image_import_descriptor_t;

/*
 * Debug Directory Format.
 */
typedef struct {
	uint32_t characteristics;
	uint32_t time_date_stamp;
	uint16_t major_version;
	uint16_t minor_version;
	uint32_t type;
	uint32_t size_of_data;
	uint32_t rva; // The address of the debug data when loaded, relative to the image base.
	uint32_t file_offset; // The file pointer to the debug data.
} image_debug_directory_entry_t;

/*
 * Debug Data Structure defined in Microsoft C++.
 */
typedef struct {
	uint8_t signature[4]; // "NB10"
	uint32_t unknown;
	uint32_t unknown2;
	uint32_t unknown3;
	// Filename of .PDB goes here
} image_debug_codeview_nb10_entry_t;

/*
 * Debug Data Structure defined in Microsoft C++.
 */
typedef struct {
	uint8_t signature[4]; // "RSDS".
	uint32_t unknown;
	uint32_t unknown2;
	uint32_t unknown3;
	uint32_t unknown4;
	uint32_t unknown5;
	// Filename of .PDB goes here
} image_debug_codeview_rsds_entry_t;

/*
 * Debug Data Structure defined by Apple Mach-O to Coff utility.
 */
typedef struct {
	uint8_t signature[4]; // "MTOC".
	efi_guid_t macho_uuid;
	//  Filename of .DLL (Mach-O with debug info) goes here
} image_debug_codeview_mtoc_entry_t;

/*
 * Resource format.
 */
typedef struct {
	uint32_t characteristics;
	uint32_t time_date_stamp;
	uint16_t major_version;
	uint16_t minor_version;
	uint16_t number_of_named_entries;
	uint16_t number_of_id_entries;
	// Array of image_resource_directory_entry entries goes here.
} image_resource_directory_t;

/*
 * Resource directory entry format.
 */
typedef struct {
	union {
		struct {
			uint32_t name_offset : 31;
			uint32_t name_is_string : 1;
		} s;
		uint32_t id;
	} u1;
	union {
		uint32_t offset_to_data;
		struct {
			uint32_t offset_to_directory : 31;
			uint32_t data_is_directory : 1;
		} s;
	} u2;
} image_resource_directory_entry_t;

/*
 * Resource directory entry for string.
 */
typedef struct {
	uint16_t length;
	char16_t String[1];
} image_resource_directory_string_t;

/*
 * Resource directory entry for data array.
 */
typedef struct {
	uint32_t offset_to_data;
	uint32_t size;
	uint32_t code_page;
	uint32_t reserved;
} image_resource_data_entry_t;

typedef struct {
	uint32_t  length; // includes header
	uint16_t  revision;
	uint16_t  certificate_type;
	// uint8_t certificate[ANYSIZE_ARRAY];
} win_certificate_t;

typedef struct {
	win_certificate_t hdr;
	uint8_t cert_data[1];
} win_certificate_efi_pkcs_t;

#endif /* __ASSEMBLY__ */

#include "tecoff.h"

#ifndef __ASSEMBLY__
/*
 * Union of PE32, PE32+, and TE headers.
 */
typedef union {
	image_nt_headers_32_t pe_32;
	image_nt_headers_64_t pe_32_plus;
	te_image_header_t te;
} image_optional_header_union_t;

typedef union {
	image_nt_headers_32_t *pe_32;
	image_nt_headers_64_t *pe_32_plus;
	te_image_header_t *te;
	image_optional_header_union_t *opt_hdr;
} image_optional_header_ptr_union_t;

typedef struct {
	uint64_t image_address;
	uint64_t image_size;
	uint64_t entry_point;
	size_t size_of_headers;
	uint16_t image_type;
	uint16_t number_of_sections;
	uint32_t section_alignment;
	image_section_header_t *first_section;
	image_data_directory_t *reloc_dir;
	image_data_directory_t *sec_dir;
	uint64_t number_of_rva_and_sizes;
	image_optional_header_union_t *pe_hdr;
} pe_coff_loader_image_context_t;

#endif /* !__ASSEMBLY__ */
#endif /* _CRTE_PECOFF_H */
