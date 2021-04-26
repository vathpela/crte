# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# object.efi.mk - make generators to build .efi.o files
# Copyright Peter Jones <pjones@redhat.com>
#

src-to-efi-obj- = $(patsubst %.c,%.efi.o,$(patsubst %.S,%.efi.o,$(1)))
src-to-efi-obj = $(call top-to-build,$(call src-to-efi-obj-,$(1)))

define add-efi-object-rule-

$(call src-to-efi-obj,$(1)) : $(1)
endef

# vim:ft=make
