// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * param.h - sys/param.h
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_SYS_PARAM_H
#define _CRTE_SYS_PARAM_H

#include <stddef.h>

#define NBBY CHAR_BIT

/* Bit map related macros. */
#define setbit(a, i) ((a)[(i) / NBBY] |= 1 << ((i) % NBBY))
#define clrbit(a, i) ((a)[(i) / NBBY] &= ~(1 << ((i) % NBBY)))
#define isset(a, i)  ((a)[(i) / NBBY] & (1 << ((i) % NBBY)))
#define isclr(a, i)  (((a)[(i) / NBBY] & (1 << ((i) % NBBY))) == 0)

/* Macros for counting and rounding. */
#ifndef howmany
#define howmany(x, y) (((x) + ((y)-1)) / (y))
#endif
#ifdef __GNUC__
#define roundup(x, y)                           \
	(__builtin_constant_p(y) && powerof2(y) \
	         ? (((x) + (y)-1) & ~((y)-1))   \
	         : ((((x) + ((y)-1)) / (y)) * (y)))
#else
#define roundup(x, y) ((((x) + ((y)-1)) / (y)) * (y))
#endif
#define powerof2(x) ((((x)-1) & (x)) == 0)

/* Macros for min/max. */
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

#ifndef __align_mask
#define __align_mask(x, mask) (((x) + (mask)) & ~(mask))
#endif
#ifndef ALIGN
#define ALIGN(x, a) __align_mask(x, (typeof(x))(a)-1)
#endif
#ifndef ALIGN_DOWN
#define ALIGN_DOWN(x, a) ALIGN((x) - ((a) - 1), (a))
#endif

#endif /* !_CRTE_SYS_PARAM_H */
// vim:fenc=utf-8:tw=75:noet
