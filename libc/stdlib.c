// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * stdlib.c - C standard library functions.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <stdlib.h>

#include <errno.h>
#include <stddef.h>
#include <string.h>

#include "efi.h"

/*
 * XXX TODO: make malloc() and free() keep some lists so we can do realloc()
 */

void *
malloc(size_t size)
{
	void *buf = NULL;
	EFI_STATUS status;

	status = _BS->AllocatePool(EfiLoaderData, size, &buf);
	errno = _efi_status_to_error(status);
	if (EFI_ERROR(status))
		return NULL;

	memset(buf, 0, size);
	return buf;
}

void
free(void *ptr)
{
	EFI_STATUS status;

	/*
	 * XXX FIXME: when we have allocation size tracking, make this fill
	 * with poison
	 */
	status = _BS->FreePool(ptr);
	errno = _efi_status_to_error(status);
}

#define mul(a, b, res) __builtin_mul_overflow(a, b, res)

void *
calloc(size_t nmemb, size_t size)
{
	size_t sz = 0;
	void *buf;

	if (mul(nmemb, size, &sz)) {
		errno = EOVERFLOW;
		return NULL;
	}

	buf = malloc(sz);
	if (!buf)
		return NULL;

	return buf;
}

/*
 * uggh, not having tracking state here really sucks.
 *
 * until we do, _realloc() and _reallocarray() will just have to be told
 * the sizes for the prior allocations.
 */

void *
_realloc(void *ptr, size_t oldsize, size_t newsize)
{
	uint8_t *new, *old = ptr;

	if (oldsize < newsize) {
		memset(&old[oldsize], 0, newsize - oldsize);
		return old;
	} else if (oldsize == newsize) {
		return old;
	}

	new = calloc(1, newsize);
	if (!new)
		return NULL;

	memcpy(new, old, newsize);
	memset(old, 0, oldsize);
	free(old);
	return new;
}

void *
_reallocarray(void *ptr, size_t oldnmemb, size_t newnmemb, size_t size)
{
	size_t oldsz, newsz;

	if (mul(oldnmemb, size, &oldsz) ||
	    mul(newnmemb, size, &newsz)) {
		errno = EOVERFLOW;
		return NULL;
	}

	return _realloc(ptr, oldsz, newsz);
}

// vim:fenc=utf-8:tw=75:noet
