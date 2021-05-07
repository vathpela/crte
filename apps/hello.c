// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * hello.c - hello
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <crte.h>

#include <stdio.h>

EFI_STATUS
efi_main(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *systab)
{
	puts("hello\n");
	return 0;
}

// vim:fenc=utf-8:tw=75:noet
