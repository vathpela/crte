// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * stdlib.c - C standard library functions.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_STDLIB_H
#define _CRTE_STDLIB_H

#include <stddef.h>

void *malloc(size_t size);
void free(void *ptr);
void *calloc(size_t nmemb, size_t size);
void *_realloc(void *ptr, size_t oldsize, size_t newsize);
void *_reallocarray(void *ptr, size_t oldnmemb, size_t newnmemb, size_t size);

#endif /* !_CRTE_STDLIB_H */
// vim:fenc=utf-8:tw=75:noet
