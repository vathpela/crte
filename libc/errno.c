// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * errno.c - a subset of errno things.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <errno.h>

#include "efi.h"

EFI_STATUS
_efi_error_to_status(error_t err)
{
	EFI_STATUS status;

	switch (err) {
	case 0:
		status = EFI_SUCCESS;
		break;
	case EINVAL:
		status = EFI_INVALID_PARAMETER;
		break;
	case ENOSPC:
		status = EFI_OUT_OF_RESOURCES;
		break;
	case EIO:
		status = EFI_DEVICE_ERROR;
		break;
	case EROFS:
		status = EFI_WRITE_PROTECTED;
		break;
	case EACCES:
		status = EFI_SECURITY_VIOLATION;
		break;
	case ENOENT:
		status = EFI_NOT_FOUND;
		break;
	case EINTR:
		status = EFI_ABORTED;
		break;
	case EOVERFLOW:
		status = EFI_BAD_BUFFER_SIZE;
		break;
	case ENOSYS:
		status = EFI_UNSUPPORTED;
		break;
	default:
		status = EFI_INVALID_PARAMETER;
	}

	return status;
}

error_t
_efi_status_to_error(EFI_STATUS status)
{
	error_t err;

	switch (status) {
	case EFI_SUCCESS:
		err = 0;
		break;
	case EFI_INVALID_PARAMETER:
		err = EINVAL;
		break;
	case EFI_OUT_OF_RESOURCES:
		err = ENOSPC;
		break;
	case EFI_DEVICE_ERROR:
		err = EIO;
		break;
	case EFI_WRITE_PROTECTED:
		err = EROFS;
		break;
	case EFI_SECURITY_VIOLATION:
		err = EACCES;
		break;
	case EFI_NOT_FOUND:
		err = ENOENT;
		break;
	case EFI_ABORTED:
		err = EINTR;
		break;
	case EFI_BAD_BUFFER_SIZE:
		err = EOVERFLOW;
		break;
	case EFI_UNSUPPORTED:
		err = ENOSYS;
		break;
	default:
		err = EINVAL;
	}

	return err;
}

/*
 * Currently we don't support e.g. TLS (or threads), but still we want this
 * as much like a real system as possible, so it's defined to work like
 * we do in terms of structure.
 */
static int __errno;

int *
__errno_location(void)
{
	return &__errno;
}

// vim:fenc=utf-8:tw=75:noet
