// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * efi-includes.h - a single include for all edk2-based include files.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_EDK2_INCLUDES_H
#define _CRTE_EDK2_INCLUDES_H

/*
 * stddef.h and efi/Base.h both want to define NULL, and edk2's header
 * doesn't correctly guard it :/
 */
#ifdef NULL
#undef NULL
#endif

#include <ProcessorBind.h>
#include <Uefi/UefiBaseType.h>
#include <Uefi/UefiSpec.h>
#include <Protocol/LoadedImage.h>
#include <Protocol/Rng.h>

/*
 * Now make sure our NULL definition is sane.
 */
#ifdef NULL
#undef NULL
#endif
#define NULL ((void *)0)

#endif /* !_CRTE_EDK2_INCLUDES_H */
// vim:fenc=utf-8:tw=75:noet
