// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * earlyprint.h - declaration of early debug print
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_EARLYPRINT_H
#define _CRTE_EARLYPRINT_H

#ifdef _CRTE_DEBUG
static void __attribute__((__unused__))
_early_print_val(EFI_SYSTEM_TABLE *systab, int size, uint64_t value);

static void __attribute__((__unused__))
_early_print(EFI_SYSTEM_TABLE *systab, uint16_t *str);

#define early_print_val(a) _early_print_val(systab, sizeof(a), (uint64_t)(a))
#define early_print(x) _early_print(systab, (x))
#else /* !_CRTE_DEBUG */
#define early_print_val(a)
#define early_print(x)
#endif /* !_CRTE_DEBUG */

#endif /* !_CRTE_EARLYPRINT_H */
// vim:fenc=utf-8:tw=75:noet
