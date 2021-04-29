# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# Makefile
# Copyright Peter Jones <pjones@redhat.com>

$(BUILDDIR)/libc :
	@mkdir -p $(BUILDDIR)/libc

all : | $(BUILDDIR)/libc all-libc

dumpmake-libc :
	$(info =========== libc sources ===========)
	$(info $(call add-archive-sources-,libc,$(wildcard $(TOPDIR)/libc/*.c)))
	$(info =============== libc ===============)
	$(info $(call make-archive-target-,libc))

dumpmake : dumpmake-libc

$(call add-archive-sources,libc,$(wildcard $(TOPDIR)/libc/*.c))
$(call make-archive-target,libc)

.PHONY: all-libc dumpmake-libc

# vim:ft=make

