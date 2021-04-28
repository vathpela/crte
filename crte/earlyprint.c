// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * earlyprint.c - implementation of early debug print
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <internals.h>

#ifdef _CRTE_DEBUG

#if __SIZEOF_WCHAR_T__ != 2
#error we really do need -fshort-wchar
#endif

static const uint16_t hex[] = L"0123456789abcdef";

void __attribute__((__unused__))
_early_print_val(int size, uint64_t value)
{
        uint16_t buf[21] = L"0x0000000000000000\r\n";
        int shift;
        uint64_t mask;
        int i;

	if (!_ST || !_ST->ConOut || !_ST->ConOut->OutputString)
		return;

        switch(size) {
        case 1:
                shift = 4;
                break;
        case 2:
                shift = 12;
                break;
        case 4:
                shift = 28;
                break;
        case 8:
        default:
                shift = 60;
                if (!(value & 0xffffffff00000000ull))
                        shift >>= 1;
                break;
        }
        mask = 0xfull << shift;

        for (i = 2; mask != 0; i += 2) {
                buf[i] = hex[(value & mask) >> shift];
                mask >>= 4;
                shift -= 4;
                buf[i+1] = hex[(value & mask) >> shift];
                mask >>= 4;
                shift -= 4;
        }
        buf[i+0] = L'\r';
        buf[i+1] = L'\n';
        buf[i+2] = L'\0';

        _ST->ConOut->OutputString(_ST->ConOut, buf);
}

void __attribute__((__unused__))
_early_print(uint16_t *str)
{
	if (!_ST || !_ST->ConOut || !_ST->ConOut->OutputString)
		return;

        _ST->ConOut->OutputString(_ST->ConOut, str);
}
#endif /* !_CRTE_DEBUG */

// vim:fenc=utf-8:tw=75:noet
