# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# arch-arm.mk - arm-specific make bits
# Copyright Peter Jones <pjones@redhat.com>
#
ifeq ($(EFI_ARCH),arm)

ARCH_SUBSYSTEM	:= 0xa
ARCH_SUFFIX	:= arm
ARCH_CC_BUGS	:=
ARCH_CC_FLAGS	:= -mno-unaligned-access
ARCH_CROSS_COMPILE := arm-linux-gnu-
ARCH_CROSS_LINK := arm-efi-pe-
ARCH_LDFLAGS	:= -Wl,--defsym=EFI_SUBSYSTEM=$(ARCH_SUBSYSTEM)
ARCH_TIMESTAMP	:= 72
ARCH_TARGET	:= efi-app-arm
LDARCH		:= arm
DASHJ		:= -j$(shell echo $$(($$(grep -c "^processor	" /proc/cpuinfo) + 1)))

ifneq ($(HOST_ARCH),arm)
ifeq ($(origin CROSS_COMPILE),default)
CROSS_COMPILE	:= arm-linux-gnu-
endif
ifeq ($(origin CROSS_LINK),default)
CROSS_LINK	:= arm-efi-pe-
endif
endif

export
endif
# vim:ft=make
