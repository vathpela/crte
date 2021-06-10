# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# helpers.mk - helpful functions for make stuff
# Copyright Peter Jones <pjones@redhat.com>
#

empty :=
space := $(empty) $(empty)
tab := $(empty)	$(empty)

cleanup = $(subst $(space)$(space),$(space),$(subst $(tab)$(space),$(space),$(subst /./,/,$(subst //,/,$(1)))))

sources = $(call cleanup,$(foreach x,$(1),$(wildcard $(x)/*.c) $(wildcard $(x)/*.S)))

top-to-build = $(foreach x,$(1),$(call cleanup,$(patsubst $(TOPDIR)%,$(BUILDDIR)%,$(x))))

dir-to-target = $(foreach x,$(1),$(subst -$(space),,$(subst --,-,$(subst /,-,$(subst //,/,$(subst ./,/,-$(x)-$(space)))))))

define make-builddir-target-
$(1) :
	@mkdir -p $(1)

clean$(call dir-to-target,$(1)) : clean$(call dir-to-target,$(1))-objs
	@if [ -d "$(1)" ] ; then rmdir -v "$(1)" ; fi

clean : clean$(call dir-to-target,$(1))

.PHONY: clean$(call dir-to-target,$(1)) clean
endef

define make-builddir-targets
$(foreach x,$(1),$(call make-builddir-target-,$(x)))
endef

check-compiler-support := $(shell if $(CC) $(CFLAGS) -xc -S $(foreach x,$(1),$(x)) -o /dev/null /dev/null >&/dev/null ; then echo 1 ; fi)

# vim:ft=make
