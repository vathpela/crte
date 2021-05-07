# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# setup.mk
# Copyright Peter Jones <pjones@redhat.com>
#

.ONESHELL:

COMPILER	?= gcc
ifeq ($(origin CC),default)
override CC	?= $(CROSS_COMPILE)$(COMPILER)
endif
EFI_ARCH	?= $(shell $(CC) -dumpmachine | cut -f1 -d- | sed \
			-e 's,aarch64,aa64,' \
			-e 's,arm.*,arm,' \
			-e 's,i[3456789]86,ia32,' \
			-e 's,riscv.*,riscv64,' \
			-e 's,amd64,x64,' -e 's,x86_64,x64,' \
			)
override EFI_ARCH := $(EFI_ARCH)
override HOST_ARCH := $(shell uname -m | sed \
			-e 's,aarch64,aa64,' \
			-e 's,arm.*,arm,' \
			-e 's,i[3456789]86,ia32,' \
			-e 's,riscv.*,riscv64,' \
			-e 's,amd64,x64,' -e 's,x86_64,x64,' \
			)

include $(TOPDIR)/include/arch-$(EFI_ARCH).mk
include $(TOPDIR)/include/helpers.mk
include $(TOPDIR)/include/defaults.mk
include $(TOPDIR)/include/rules.efi.mk
include $(TOPDIR)/include/object.efi.mk
include $(TOPDIR)/include/archive.efi.mk
include $(TOPDIR)/include/app.efi.mk

ABSTOPDIR=$(abspath $(TOPDIR))

include $(TOPDIR)/crte/Makefile
include $(TOPDIR)/libc/Makefile
include $(TOPDIR)/scripts/Makefile
include $(TOPDIR)/apps/Makefile

# vim:ft=make
