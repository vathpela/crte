// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * string.h - C standard library string.h functions.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_STRING_H
#define _CRTE_STRING_H

#include <stddef.h>

int bcmp(const void *s1, const void *s2, size_t n);
void bcopy(const void *src, void *dest, size_t n);
void bzero(void *s, size_t n);
void *memccpy(void *dest, const void *src, int c, size_t n);
void *memchr(const void *s, int c, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
void *memset(void *s, int c, size_t n);

size_t strlen(const char *s1);
int strcmp(const char *s1p, const char *s2p);
int strncmp(const char *s1p, const char *s2p, size_t len);
int strncasecmp(const char *s1p, const char *s2p, size_t n);
int strcasecmp(const char *str1, const char *str2);
char * strrchr(const char *str, int c);
size_t strnlen(const char *s, size_t n);
char * strcpy(char *dest, const char *src);
char * strncpy(char *dest, const char *src, size_t n);
char * strcat(char *dest, const char *src);
char * strdup(const char *const src);
char * strndup(const char *const src, const size_t srcmax);
char * stpcpy(char *dest, const char *const src);
char * strchrnul(const char *s, int c);
char * strchr(const char *s, int c);

#endif /* !_CRTE_STRING_H */
// vim:fenc=utf-8:tw=75:noet
