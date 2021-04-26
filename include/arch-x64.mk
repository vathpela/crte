# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# arch-x64.mk - x64-specific make bits
# Copyright Peter Jones <pjones@redhat.com>
#
ifeq ($(EFI_ARCH),x64)

ARCH_SUFFIX	:= x64
ARCH_CC_BUGS	:= $(if $(findstring gcc,$(CC)),-maccumulate-outgoing-args,)
ARCH_CC_FLAGS	:= \
		   $(ARCH_CC_BUGS) \
		   -m64 \
		   -mabi=ms \
		   -mno-mmx \
		   -mno-red-zone \
		   -mno-sse
ARCH_CROSS_COMPILE := x86_64-linux-gnu-
ARCH_CROSS_LINK := x86_64-linux-gnu-
ARCH_LDFLAGS	:=
ARCH_TIMESTAMP	:= 136
ARCH_TARGET	:= efi-app-x86_64
LDARCH		:= x86_64
DASHJ		:= -j$(shell echo $$(($$(grep -c "^model name" /proc/cpuinfo) + 1)))

export
endif


# vim:ft=make
