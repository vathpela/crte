// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * stdio.h - vsnprintf() et alia
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_STDIO_H
#define _CRTE_STDIO_H

#include <limits.h>
#include <stdarg.h>
#include <stddef.h>
#include <crte/attributes.h>

#define EOF INT_MIN

int putchar(int c);
int puts(const char *s);

#endif /* !_CRTE_STDIO_H */
// vim:fenc=utf-8:tw=75:noet
