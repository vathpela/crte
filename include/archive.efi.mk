# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# archive.efi.mk - make generators to build .efi.a files
# Copyright Peter Jones <pjones@redhat.com>
#

define make-archive-target-
$(call cleanup,$(BUILDDIR)$(1).efi.a) :

all-$(1) : $(dir $(call cleanup,$(BUILDDIR)$(1)/))
all-$(1) : $(call cleanup,$(BUILDDIR)$(1).efi.a)

all : all-$(1)

clean-$(1) :
	@rm -vf $(call cleanup,$(BUILDDIR)$(1).efi.a)

clean : clean-$(1)

.PHONY: clean-$(1) clean$(call dir-to-target,$(BUILDDIR)$(1))-objs all-$(1)
endef

define add-archive-sources-
$(call make-builddir-targets,$(sort $(foreach x,$(2),$(dir $(call src-to-efi-obj,$(x))))))

$(call cleanup,$(BUILDDIR)$(1).efi.a) : $(foreach x,$(2),$(call src-to-efi-obj,$(x)))
$(call cleanup,$(BUILDDIR)$(1).efi.a) : OBJECTS+=$(foreach x,$(2),$(call src-to-efi-obj,$(x)))
$(foreach x,$(2),$(call add-efi-object-rule-,$(x)))

clean$(call dir-to-target,$(BUILDDIR)$(1))-objs :
	@rm -vf $(foreach x,$(2),$(call src-to-efi-obj,$(x))) $(BUILDDIR)$(1).efi.a
endef

define add-archive-sources
$(eval $(call add-archive-sources-,$(1),$(2)))
endef

define make-archive-target
$(eval $(call make-archive-target-,$(1),$(2)))
endef

# vim:ft=make
