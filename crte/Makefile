# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# Makefile
# Copyright Peter Jones <pjones@redhat.com>
#

$(BUILDDIR)/crte :
	@mkdir -p $(BUILDDIR)/crte

all : | $(BUILDDIR)/crte all-crte

dumpmake-crte :
	$(info =========== crte sources ===========)
	$(info $(call add-archive-sources-,crte,$(wildcard $(TOPDIR)/crte/*.c)))
	$(info =============== crte ===============)
	$(info $(call make-archive-target-,crte))

dumpmake : dumpmake-crte

$(call make-archive-target,crte)
$(call add-archive-sources,crte,$(wildcard $(TOPDIR)/crte/*.c))

.PHONY: all-crte dumpmake-crte

# vim:ft=make
