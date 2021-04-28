// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * symbols.h - symbols provided by the toolchain and whatnot
 * Copyright Peter Jones <pjones@redhat.com>
 */

#ifndef _CRTE_SYMBOLS_H
#define _CRTE_SYMBOLS_H

extern uintptr_t _text;
extern uintptr_t _etext;

extern uintptr_t _DYNAMIC;

/*
 * XXX FIXME
 *
 * Note that these aren't the using the GNU "CONSTRUCTOR" output section
 * command, so they don't start with a size.  Because of p2align and the
 * end/END definitions, and the fact that they're mergeable, they can also
 * have NULLs which aren't guaranteed to be at the end.
 */
extern uintptr_t _init_array, _init_array_end;
extern uintptr_t __CTOR_LIST__, __CTOR_END__;
extern uintptr_t _fini_array, _fini_array_end;
extern uintptr_t __DTOR_LIST__, __DTOR_END__;

#endif /* !_CRTE_SYMBOLS_H */
// vim:fenc=utf-8:tw=75:noet
