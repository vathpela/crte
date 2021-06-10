// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * stack-protector.c - support for stack protector using
 *		       "-fstack-protector-strong -mstack-protector-guard=global"
 *		       or "-fstack-protector -mstack-protector-guard=global"
 *		       in an early constructor.
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include "internals.h"

#include <string.h>

static uint8_t stack_chk_guard_buf[32];

void *__stack_chk_guard = NULL;

void __noreturn
__stack_chk_fail(void)
{
	if (!_ST || !_ST->ConOut || !_ST->ConOut->OutputString)
		_ST->ConOut->OutputString(_ST->ConOut, L"FATAL: Stack Protector triggered!");

	do {
#if defined(__x86_64__) || defined(__i386__) || defined(__i686__)
		asm volatile("pause");
#elif defined(__aarch64__)
		asm volatile("wfi");
#else
		/*
		 * We need the loop to not get optimized out, even if we
		 * don't have any better option than just busy looping.
		 */
		asm volatile("");
#endif
	} while (1);
}

static void __constructor
___stack_protector_init(void)
{
	EFI_RNG_PROTOCOL *rng = NULL;
	EFI_STATUS status;

	status = _BS->LocateProtocol(&gEfiRngProtocolGuid, NULL, (void **)&rng);
	if (EFI_ERROR(status))
		return;

	memcpy(&__stack_chk_guard, stack_chk_guard_buf, sizeof(__stack_chk_guard));
}

// vim:fenc=utf-8:tw=75:noet
