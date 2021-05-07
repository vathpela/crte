# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# Makefile
# Copyright Peter Jones <pjones@redhat.com>
#

$(BUILDDIR)/apps :
	@mkdir -p $(BUILDDIR)/apps

all : | $(BUILDDIR)/apps all-apps

dumpmake-apps :
	$(info ============ app sources ===========)
	$(info $(call add-app-sources-,hello,$(TOPDIR)/apps/hello.c))
	$(info =============== apps ===============)
	$(info $(call make-app-target-,hello,crte.efi.a libc.efi.a))

dumpmake : dumpmake-apps

$(call add-app-sources,hello,$(TOPDIR)/apps/hello.c)
$(call make-app-target,hello,crte.efi.a libc.efi.a)

.PHONY: all-apps dumpmake-apps

# vim:ft=make
