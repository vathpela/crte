// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * stdio.c - vsnprintf() and its descendents, among others
 *
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <stdio.h>

#include <alloca.h>
#include <errno.h>
#include <limits.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "efi.h"

int
putchar(int c)
{
	EFI_STATUS status;
	CHAR16 wc[2] = { c, 0 };

	if (!_ST || !_ST->ConOut || !_ST->ConOut->OutputString)
		return c;

	status = _ST->ConOut->OutputString(_ST->ConOut, &wc[0]);
	errno = _efi_status_to_error(status);
	if (EFI_ERROR(status))
		return EOF;
	return c;
}

/*
 * FIXME: for now, is (plausibly 8-bit) ASCII, not UTF-8.  That is,
 * there's ASCII -> UCS-2 conversion, not UTF-8 -> UCS-2 conversion.
 */
int
puts(const char *s)
{
	CHAR16 *buf;
	size_t sz;
	int ret;

	sz = strlen(s) + 1;

	if (!_ST || !_ST->ConOut || !_ST->ConOut->OutputString)
		return sz;

	buf = alloca(sz * 2);
	for (size_t i = 0; i < sz; i++) {
		if (buf) {
			buf[i] = s[i];
		} else {
			ret = putchar(s[i]);
			if (ret < 0)
				return ret;
		}
	}
	if (buf) {
		EFI_STATUS status;

		status = _ST->ConOut->OutputString(_ST->ConOut, buf);
		errno = _efi_status_to_error(status);
		if (EFI_ERROR(status))
			return EOF;
	}
	return sz;
}

// vim:fenc=utf-8:tw=75:noet
