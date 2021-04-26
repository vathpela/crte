# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# arch-aa64.mk - aa64-specific make bits
# Copyright Peter Jones <pjones@redhat.com>
#
ifeq ($(EFI_ARCH),aa64)

ARCH_SUBSYSTEM	:= 0xa
ARCH_SUFFIX	:= aa64
ARCH_CC_BUGS	:=
ARCH_CC_FLAGS	:= -mstrict-align
ARCH_CROSS_COMPILE := aarch64-linux-gnu-
ARCH_CROSS_LINK := aarch64-efi-pe-
ARCH_LDFLAGS	:= -Wl,--defsym=EFI_SUBSYSTEM=$(ARCH_SUBSYSTEM) -nolibc
ARCH_TIMESTAMP	:= 72
ARCH_TARGET	:= efi-app-aa64
LDARCH		:= aarch64
DASHJ		:= -j$(shell echo $$(($$(grep -c "^processor      " /proc/cpuinfo) + 1)))

export
endif
# vim:ft=make
