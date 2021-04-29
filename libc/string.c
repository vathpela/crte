// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * string.c - C standard library string.h functions.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <ctype.h>
#include <errno.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <crte/attributes.h>

#define add(a, b, res) __builtin_add_overflow(a, b, res)
#define sub(a, b, res) __builtin_sub_overflow(a, b, res)
#define mul(a, b, res) __builtin_mul_overflow(a, b, res)

int
bcmp(const void *s1, const void *s2, size_t n)
{
	const uint8_t *a = (const uint8_t *)s1;
	const uint8_t *b = (const uint8_t *)s2;

	for (size_t i = 0; i < n; i++) {
		if (a[i] != b[i])
			return a[i] - b[i];
	}
	return 0;
}

void
bcopy(const void *src, void *dest, size_t n)
{
	const uint8_t *s = (const uint8_t *)src;
	uint8_t *d = (uint8_t *)dest;

	if (n == 0)
		return;

	for (size_t i = n; i > 0; i--) {
		d[i-1] = s[i-1];
	}
}

void
bzero(void *s, size_t n)
{
	memset(s, 0, n);
}

void *
memccpy(void *dest, const void *src, int c, size_t n)
{
	const int8_t *s = (const int8_t *)src;
	int8_t *d = (int8_t *)dest;

	for (size_t i = 0; i < n; i++) {
		d[i] = s[i];
		if (s[i] == c)
			return &d[i];
	}
	return NULL;
}

void *
memchr(const void *s, int c, size_t n)
{
	const int8_t *src = (const int8_t *)s;

	for (size_t i = 0; i < n; i++) {
		if (src[i] == c)
			return (void *)&src[i];
	}

	return NULL;
}

int
memcmp(const void *s1, const void *s2, size_t n)
{
	return bcmp(s1, s2, n);
}

void *
memcpy(void *dest, const void *src, size_t n)
{
	const uint8_t *s = (const uint8_t *)src;
	uint8_t *d = (uint8_t *)dest;

	for (size_t i = 0; i < n; i++) {
		d[i] = s[i];
	}

	return dest;
}

void *
memmove(void *dest, const void *src, size_t n)
{
	bcopy(src, dest, n);
	return dest;
}

void *
memset(void *s, int c, size_t n)
{
	uint8_t *d = (uint8_t *)s;

	for (size_t i = 0; i < n; i++)
		d[i] = c;
	return s;
}

size_t
strlen(const char *s1)
{
	size_t len;

	for (len = 0; *s1; s1 += 1, len += 1)
		;
	return len;
}

int
strcmp(const char *s1p, const char *s2p)
{
	const uint8_t *s1 = (const uint8_t *)s1p;
	const uint8_t *s2 = (const uint8_t *)s2p;

	while (*s1) {
		if (*s1 != *s2) {
			break;
		}

		s1 += 1;
		s2 += 1;
	}

	return *s1 - *s2;
}

int
strncmp(const char *s1p, const char *s2p, size_t len)
{
	const uint8_t *s1 = (const uint8_t *)s1p;
	const uint8_t *s2 = (const uint8_t *)s2p;

	while (*s1 && len) {
		if (*s1 != *s2) {
			break;
		}

		s1 += 1;
		s2 += 1;
		len -= 1;
	}

	return len ? *s1 - *s2 : 0;
}

/* Based on AsciiStriCmp() in edk2 MdePkg/Library/BaseLib/String.c */
int
strncasecmp(const char *s1p, const char *s2p, size_t n)
{
	const uint8_t *s1 = (const uint8_t *)s1p;
	const uint8_t *s2 = (const uint8_t *)s2p;

	while (*s1 && n) {
		if (toupper(*s1) != toupper(*s2)) {
			break;
		}

		s1 += 1;
		s2 += 1;
		n -= 1;
	}

	return n ? *s1 - *s2 : 0;
}

/* Based on AsciiStriCmp() in edk2 MdePkg/Library/BaseLib/String.c */
int
strcasecmp(const char *str1, const char *str2)
{
	uint8_t c1, c2;

	c1 = toupper(*str1);
	c2 = toupper(*str2);
	while ((*str1 != '\0') && (c1 == c2)) {
		str1++;
		str2++;
		c1 = toupper(*str1);
		c2 = toupper(*str2);
	}

	return c1 - c2;
}

/* Scan a string for the last occurrence of a character */
char *
strrchr(const char *str, int c)
{
	char *save;

	for (save = NULL;; ++str) {
		if (*str == c) {
			save = (char *)str;
		}
		if (*str == 0) {
			return (save);
		}
	}
}

__nonnull(1)
size_t
strnlen(const char *s, size_t n)
{
	size_t i;
	for (i = 0; i < n; i++)
		if (s[i] == '\0')
			break;
	return i;
}

__returns_nonnull __nonnull(1, 2)
char *
strcpy(char *dest, const char *src)
{
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[i] = src[i];

	dest[i] = '\0';
	return dest;
}

__returns_nonnull __nonnull(1, 2)
char *
strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];
	if (i < n)
		dest[i] = '\0';

	return dest;
}

__returns_nonnull __nonnull(1, 2)
char *
strcat(char *dest, const char *src)
{
	size_t dest_len = strlen(dest);
	size_t i;

	for (i = 0; src[i] != '\0'; i++)
		dest[dest_len + i] = src[i];
	dest[dest_len + i] = '\0';

	return dest;
}

__nonnull(1)
char *
strdup(const char *const src)
{
	size_t len;
	char *news = NULL;
	size_t sz;

	len = strlen(src);

	if (add(len, 1, &sz)) {
		errno = EOVERFLOW;
		return NULL;
	}

	news = calloc(1, sz);
	if (news)
		strncpy(news, src, len);
	return news;
}

__nonnull(1)
char *
strndup(const char *const src, const size_t srcmax)
{
	size_t len, sz;
	char *news = NULL;

	len = strnlen(src, srcmax);
	if (add(len, 1, &sz)) {
		errno = EOVERFLOW;
		return NULL;
	}

	news = calloc(1, sz);
	if (news)
		strncpy(news, src, len);
	return news;
}

__returns_nonnull __nonnull(1, 2)
char *
stpcpy(char *dest, const char *const src)
{
	size_t i = 0;
	for (i = 0; src[i]; i++)
		dest[i] = src[i];
	dest[i] = '\000';
	return &dest[i];
}

__returns_nonnull __nonnull(1)
char *
strchrnul(const char *s, int c)
{
	unsigned int i;

	for (i = 0; s[i] != '\000' && s[i] != c; i++)
		;

	return (char *)&s[i];
}

__nonnull(1)
char *
strchr(const char *s, int c)
{
	const char *s1;

	s1 = strchrnul(s, c);
	if (!s1 || s1[0] == '\000')
		return NULL;

	return (char *)s1;
}

// vim:fenc=utf-8:tw=75:noet
