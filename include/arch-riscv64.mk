# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# arch-riscv64.mk - riscv64-specific make bits
# Copyright Peter Jones <pjones@redhat.com>
#
ifeq ($(EFI_ARCH),riscv64)

ARCH_SUFFIX	:= riscv64
ARCH_CC_BUGS	:=
ARCH_CC_FLAGS	:= \
		   $(ARCH_CC_BUGS)
ARCH_CROSS_COMPILE := riscv64-linux-gnu-
ARCH_CROSS_LINK := riscv64-efi-pe-
ARCH_LDFLAGS	:=
# XXX FIXME THIS IS COPY-PASTA FROM X64
ARCH_TIMESTAMP	:= 136
ARCH_TARGET	:= efi-app-riscv64
LDARCH		:= riscv64
# XXX FIXME THIS IS COPY-PASTA FROM X64
DASHJ		:= -j$(shell echo $$(($$(grep -c "^model name" /proc/cpuinfo) + 1)))

export
endif
# vim:ft=make
