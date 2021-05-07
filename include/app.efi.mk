# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# app.efi.mk - make generators to build .efi files
# Copyright Peter Jones <pjones@redhat.com>
#

define add-app-object-rule-
$(call cleanup,$(BUILDDIR)apps/$(1).efi.so) : $(call src-to-efi-obj,$(2))
endef

define add-app-sources-
$(call make-builddir-targets,$(sort $(foreach x,$(2),$(dir $(call src-to-efi-obj,$(x))))))

$(call cleanup,$(BUILDDIR)apps/$(1).efi.so) : $(foreach x,$(2),$(call src-to-efi-obj,$(x)))
$(call cleanup,$(BUILDDIR)apps/$(1).efi.so) : OBJECTS+=$(foreach x,$(2),$(call src-to-efi-obj,$(x)))
$(foreach x,$(2),$(call add-efi-object-rule-,$(x)))

clean-$(1)-objs :
	@rm -vf $(foreach x,$(2),$(call src-to-efi-obj,$(x)))

clean$(call dir-to-target,$(BUILDDIR)/apps/)-objs : clean-$(1)-objs
endef

define make-app-target-
$(call cleanup,$(BUILDDIR)apps/$(1).efi) : $(call cleanup,$(BUILDDIR)apps/$(1).efi.so)

$(call cleanup,$(BUILDDIR)apps/$(1).efi.so) : $(foreach x,$(2),$(BUILDDIR)$(x))
$(call cleanup,$(BUILDDIR)apps/$(1).efi.so) : ARCHIVES+=$(foreach x,$(2),$(BUILDDIR)$(x))
clean-$(1) :
	@rm -vf $(call cleanup,$(BUILDDIR)apps/$(1).efi.so) $(call cleanup,$(BUILDDIR)apps/$(1).efi)

clean$(call dir-to-target,$(BUILDDIR))-apps : clean-$(1)

all-$(1) : $(call cleanup,$(BUILDDIR)apps/$(1).efi)

all : all-$(1)

.PHONY: clean-$(1) clean-$(1)-objs all-$(1)
endef

define make-app-target
$(eval $(call make-app-target-,$(1),$(2)))
endef

define add-app-sources
$(eval $(call add-app-sources-,$(1),$(2)))
endef

# vim:ft=make
