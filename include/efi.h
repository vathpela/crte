// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * efi.h - top level include for EFI stuff
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_EFI_H
#define _CRTE_EFI_H

#include "edk2-includes.h"

extern EFI_SYSTEM_TABLE *_ST;
extern EFI_BOOT_SERVICES *_BS;
extern EFI_RUNTIME_SERVICES *_RT;

#endif /* !_CRTE_EFI_H */
// vim:fenc=utf-8:tw=75:noet
