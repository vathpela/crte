// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * errno.h - a subset of errno things.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef ERRNO_H_
#define ERRNO_H_

#include <stdint.h>

#include <asm-generic/errno-base.h>
#include <asm-generic/errno.h>

#include "edk2-includes.h"

extern int *__errno_location(void) __attribute__((__const__));

#define errno (*(__errno_location()))

typedef int error_t;

EFI_STATUS _efi_error_to_status(error_t err);
error_t _efi_status_to_error(EFI_STATUS status);

#endif /* !ERRNO_H_ */
// vim:fenc=utf-8:tw=75:noet
