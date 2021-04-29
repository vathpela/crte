// SPDX-License-Identifier: BSD-2-Clause-Patent
/*
 * Copyright (c) 2006 - 2010, Intel Corporation. All rights reserved.
 * Portions copyright (c) 2008 - 2009, Apple Inc. All rights reserved.
 */

#include "pecoff.h"
#ifndef _CRTE_TECOFF_H
#define _CRTE_TECOFF_H

/*
 * Data directory indexes in our TE image header
 */
#define TE_IMAGE_DIRECTORY_ENTRY_BASERELOC 0
#define TE_IMAGE_DIRECTORY_ENTRY_DEBUG     1

#define TE_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES 2

#define TE_IMAGE_HEADER_SIGNATURE "VZ"

#ifndef __ASSEMBLY__
/*
 * Header format for TE images, defined in the PI Specification, 1.0.
 */
typedef struct {
	uint8_t signature[2];       // The signature for TE format = "VZ".
	uint16_t machine;           // From the original file header.
	uint8_t number_of_sections; // From the original file header.
	uint8_t subsystem;          // From original optional header.
	uint16_t stripped_size; // Number of bytes we removed from the header.
	uint32_t address_of_entry_point; // Offset to entry point -- from original optional header.
	uint32_t base_of_code; // From original image -- required for ITP debug.
	uint64_t image_base;   // From original file header.
	union {
		struct {
			image_data_directory_t basereloc;
			image_data_directory_t debug;
		};
		image_data_directory_t data_directory[TE_IMAGE_NUMBER_OF_DIRECTORY_ENTRIES];
	};
} te_image_header_t;

#endif /* __ASSEMBLY__ */
#endif /* _CRTE_PECOFF_H */
// vim:fenc=utf-8:tw=75:noet
