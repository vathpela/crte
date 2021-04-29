// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * crte.h - C Runtime for EFI
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_H
#define _CRTE_H

#include <efi.h>

/*
 * external
 */
EFI_STATUS EFIAPI efi_main(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *systab);

#endif /* !_CRTE_H */
// vim:fenc=utf-8:tw=75:noet
