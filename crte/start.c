// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * start.c - entry point for EFI code
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include "internals.h"

EFI_SYSTEM_TABLE *_ST;
EFI_BOOT_SERVICES *_BS;
EFI_RUNTIME_SERVICES *_RT;

EFI_STATUS EFIAPI
_start(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *systab)
{
	EFI_STATUS ret, status;
	uintptr_t ldbase;
	EFI_LOADED_IMAGE *image = NULL;
	elf_dynamic *dyn = NULL;

	status = systab->BootServices->HandleProtocol(
						image_handle,
						&gEfiLoadedImageProtocolGuid,
						(void *)&image);
	if (EFI_ERROR(status))
		return status;

	ldbase = (uintptr_t)image->ImageBase;
	dyn = (void *)(&_DYNAMIC);

	status = _relocate_elf(ldbase, dyn);
	if (EFI_ERROR(status))
		return status;

	_ST = systab;
	_BS = systab->BootServices;
	_RT = systab->RuntimeServices;

	status = _ctors(ldbase);
	if (EFI_ERROR(status))
		return status;

	ret = efi_main(image_handle, systab);
	if (EFI_ERROR(ret))
		return ret;

	status = _dtors(ldbase);
	if (EFI_ERROR(status))
		return status;

	return ret;
}
// vim:fenc=utf-8:tw=75:noet
