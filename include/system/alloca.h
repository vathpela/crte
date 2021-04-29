// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * alloca.h - allocate memory that is automatically freed
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_ALLOCA_H
#define _CRTE_ALLOCA_H

#include <errno.h>
#include <stddef.h>

#define alloca(size)                                        \
	({                                                  \
		uint8_t *buf_;                              \
		uint32_t sz_ = size;                        \
		buf_ = __builtin_alloca(sz_);               \
		if (!buf_)                                  \
			errno = ENOMEM;                     \
		for (size_t i_ = 0; buf_ && i_ < sz_; i_++) \
			buf_[i_] = 0;                       \
		(void *)buf_;                               \
	})

#endif /* !_CRTE_ALLOCA_H */
// vim:fenc=utf-8:tw=75:noet
