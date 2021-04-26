# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# arch-ia32.mk - ia32-specific make bits
# Copyright Peter Jones <pjones@redhat.com>
#
ifeq ($(EFI_ARCH),ia32)

ARCH_SUFFIX	:= ia32
ARCH_CC_BUGS	:= $(if $(findstring gcc,$(CC)),-maccumulate-outgoing-args,)
ARCH_CC_FLAGS	:= \
		   $(ARCH_CC_BUGS) \
		   -m32 \
		   -mno-mmx \
		   -mno-red-zone \
		   -mno-sse
ARCH_CROSS_COMPILE := i686-linux-gnu-
ARCH_CROSS_LINK := i686-linux-gnu-
ARCH_LDFLAGS	:=
ARCH_TIMESTAMP	:= 136
ARCH_TARGET	:= efi-app-ia32
LDARCH		:= i686
DASHJ		:= -j$(shell echo $$(($$(grep -c "^model name" /proc/cpuinfo) + 1)))

ifneq ($(HOST_ARCH),ia32)
ifeq ($(origin CROSS_COMPILE),default)
CROSS_COMPILE	:= i-linux-gnu-
endif
ifeq ($(origin CROSS_LINK),default)
CROSS_LINK	:= arm-efi-pe-
endif
endif

export
endif
# vim:ft=make
