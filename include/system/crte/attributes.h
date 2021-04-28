// SPDX-License-Identifier: BSD-2-Clause-Patent

#ifndef _CRTE_COMPILER_H
#define _CRTE_COMPILER_H

/*
 * These are special ones that get our unit tests in trouble with the
 * compiler optimizer dropping out tests...
 */
#ifdef __nonnull__
# undef __nonnull__
#endif
#ifdef __returns_nonnull
# undef __returns_nonnull
#endif

#ifdef _CRTE_UNIT_TEST
# define __nonnull(first, args...)
# define __returns_nonnull
#else
# define __nonnull(first, args...) __attribute__((__nonnull__(first, ## args)))
#if (defined(__GNUC__) && (__GNUC__ > 4 || (__GNUC__ == 4 && __GNUC_MINOR__ >= 9)))
# define __returns_nonnull __attribute__((__returns_nonnull__))
#else
# define __returns_nonnull
#endif
#endif

#ifndef __unused
#define __unused __attribute__((__unused__))
#endif
#ifndef __hidden
#define __hidden __attribute__((__visibility__ ("hidden")))
#endif
#ifndef __public
#define __public __attribute__((__visibility__ ("default")))
#endif
#ifndef __deprecated
#define __deprecated __attribute__((__deprecated__))
#endif
#ifndef __destructor
#define __destructor __attribute__((destructor))
#endif
#ifndef __constructor
#define __constructor __attribute__((constructor))
#endif
#ifndef __alias
#define __alias(x) __attribute__((weak, alias (#x)))
#endif
#ifndef __allocfunc
#define __allocfunc(dealloc, dealloc_arg) __attribute__((__malloc__(dealloc, dealloc_arg)))
#endif
#ifndef __printf
#define __printf(first, args...) __attribute__((__format__(printf, first, ## args)))
#endif
#ifndef __pure
#define __pure __attribute__((__pure__))
#endif
#ifndef __flatten
#define __flatten __attribute__((__flatten__))
#endif
#ifndef __packed
#define __packed __attribute__((__packed__))
#endif
#ifndef __version
#define __version(sym, ver) __asm__(".symver " # sym "," # ver)
#endif
#ifndef __noreturn
#define __noreturn __attribute__((__noreturn__))
#endif
#ifndef __aligned
#define __aligned(n) __attribute__((__aligned__(n)))
#endif
#ifndef __cleanup_func
#define __cleanup_func(x) __attribute__((__cleanup__(x)))
#endif
#ifndef __used
#define __used __attribute__((__used__))
#endif
#ifndef __section
#define __section(x) __attribute__((__section__(x)))
#endif
#ifndef __optimize
#define __optimize(x) __attribute__((__optimize__(x)))
#endif

#ifndef __cat
#define __cat(a, b) a ## b
#endif
#ifndef __cat3
#define __cat3(a, b, c) a ## b ## c
#endif
#ifndef __stringify_1
#define __stringify_1(x...) #x
#endif
#ifndef __stringify
#define __stringify(x...) __stringify_1(x)
#endif

#ifndef __likely
#define __likely(x) __builtin_expect(!!(x), 1)
#endif

#ifndef __unlikely
#define __unlikely(x) __builtin_expect(!!(x), 0)
#endif

#define __unreachable __builtin_unreachable()

#endif /* !_CRTE_COMPILER_H */
// vim:fenc=utf-8:tw=75:et
