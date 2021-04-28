// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * structors.c - constructor and destructor iterators
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <internals.h>

typedef void (*structor)(void);

#define add(a, b, res) __builtin_add_overflow(a, b, res)

static inline EFI_STATUS EFIAPI
_call_structor(uintptr_t ldbase, uintptr_t offset)
{
	bool overflow;
	uintptr_t funcp;
	structor func;

	overflow = add(ldbase, offset, &funcp);
	if (overflow || funcp < _text || funcp > _etext)
		return EFI_LOAD_ERROR;

	func = (structor)funcp;
	func();
	return EFI_SUCCESS;
}

EFI_STATUS EFIAPI
_ctors(uintptr_t ldbase)
{
	EFI_STATUS status;

        for (uintptr_t *offset = (uintptr_t *)&_init_array; offset < &_init_array_end; offset++) {
		status = _call_structor(ldbase, *offset);
		if (EFI_ERROR(status))
			return status;
        }

        for (uintptr_t *offset = (uintptr_t *)&__CTOR_LIST__; offset < &__CTOR_END__; offset++) {
		status = _call_structor(ldbase, *offset);
		if (EFI_ERROR(status))
			return status;
        }

	return EFI_SUCCESS;
}

EFI_STATUS EFIAPI
_dtors(uintptr_t ldbase)
{
	EFI_STATUS status;

        for (uintptr_t *offset = (uintptr_t *)&__DTOR_LIST__; offset < &__DTOR_END__; offset++) {
		status = _call_structor(ldbase, *offset);
		if (EFI_ERROR(status))
			return status;
        }

        for (uintptr_t *offset = (uintptr_t *)&_fini_array; offset < &_fini_array_end; offset++) {
		status = _call_structor(ldbase, *offset);
		if (EFI_ERROR(status))
			return status;
        }

	return EFI_SUCCESS;
}

// vim:fenc=utf-8:tw=75:noet
