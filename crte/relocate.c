// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * relocate.c - relocate our elf payload
 *
 * Copyright Peter Jones <pjones@redhat.com>
 */

#include <internals.h>

EFI_STATUS EFIAPI
_relocate_elf(uintptr_t ldbase, elf_dynamic *dyn)
{
	unsigned long relsz = 0, relent = 0, relasz = 0, relaent = 0;
	elf_rel *rel = 0;
	elf_rela *rela = 0;
	unsigned long *addr;
	unsigned int i;

	for (i = 0; dyn[i].d_tag != DT_NULL; i++) {
		switch (dyn[i].d_tag) {
			case DT_REL:
				rel = (elf_rel *)(dyn[i].d_ptr + ldbase);
				break;

			case DT_RELSZ:
				relsz = dyn[i].d_val;
				break;

			case DT_RELENT:
				relent = dyn[i].d_val;
				break;

			case DT_RELA:
				rela = (elf_rela *)(dyn[i].d_ptr + ldbase);
				break;

			case DT_RELASZ:
				relasz = dyn[i].d_val;
				break;

			case DT_RELAENT:
				relaent = dyn[i].d_val;
				break;

			default:
				/* FIXME: maybe display an error message */
				return EFI_LOAD_ERROR;
		}
	}

	if (!rel && relent == 0 && !rela && relaent == 0) {
		return EFI_SUCCESS;
	}

	if ((!rel || relent == 0) && (!rela || relaent == 0)) {
		/* FIXME: maybe display an error message */
		return EFI_LOAD_ERROR;
	}

	/* apply the relocs */
	while (relsz > 0) {
		if (relsz < sizeof (*rel))
			return EFI_LOAD_ERROR;

		switch (ELF_R_TYPE (rel->r_info)) {
		case REL_ARCH_NONE:
			break;

		case REL_ARCH_RELATIVE:
			addr = (void *)(ldbase + rel->r_offset);
			break;

		default:
			/* FIXME: maybe display an error message */
			return EFI_LOAD_ERROR;
		}

		rel = (elf_rel *)((uint8_t *)rel + relent);
		relsz -= relent;
	}

	while (relasz > 0) {
		if (relasz < sizeof (*rela))
			return EFI_LOAD_ERROR;

		switch (ELF_R_TYPE (rela->r_info)) {
		case REL_ARCH_NONE:
			break;

		case REL_ARCH_RELATIVE:
			addr = (void *)(ldbase + rela->r_offset);
			*addr = ldbase + rela->r_addend;
			break;

		default:
			/* FIXME: maybe display an error message */
			return EFI_LOAD_ERROR;
		}

		rela = (elf_rela *)((uint8_t *)rela + relaent);
		relasz -= relaent;
	}

	return EFI_SUCCESS;
}
