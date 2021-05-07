# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# rules.efi.mk - rules for building efi targets
# Copyright Peter Jones <pjones@redhat.com>
#

%.efi.a :
	$(AR) rcs $@ $(OBJECTS)

%.efi.o :
	$(CC) $(CFLAGS) -c -o $@ $^

%.efi.so :
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS) $(ARCHIVES)

%.efi : %.efi.so
	$(OBJCOPY) -D \
		-j .text -j .sdata -j .data -j .data.ident \
		-j .dynamic -j .rodata -j .rel* \
		-j .rela* -j .reloc -j .eh_frame \
		-j .vendor_cert -j .sbat \
		--target $(ARCH_TARGET) $< $@
	# I am tired of wasting my time fighting binutils timestamp code.
	dd conv=notrunc bs=1 count=4 seek=$(ARCH_TIMESTAMP) if=/dev/zero of=$@

%.efi.debug : %.efi.so
	@$(OBJCOPY) -D \
		-j .text -j .sdata -j .data \
		-j .dynamic -j .rodata -j .rel* \
		-j .rela* -j .reloc -j .eh_frame -j .sbat \
		-j .debug_info -j .debug_abbrev -j .debug_aranges \
		-j .debug_line -j .debug_str -j .debug_ranges \
		-j .note.gnu.build-id \
		$< $@
	# I am tired of wasting my time fighting binutils timestamp code.
	dd conv=notrunc bs=1 count=4 seek=$(ARCH_TIMESTAMP) if=/dev/zero of=$@

vpath %.efi $(BUILDDIR) $(BUILDDIR)/apps
vpath %.efi.so $(BUILDDIR) $(BUILDDIR)/apps
vpath %.efi.a $(BUILDDIR)/crte $(BUILDDIR)/libc
vpath %.efi.o $(BUILDDIR)/crte $(BUILDDIR)/libc $(BUILDDIR)/apps
vpath %.c $(TOPDIR)/crte $(TOPDIR)/libc $(TOPDIR)/apps

all :
	@mkdir -p $(BUILDDIR)

clean : clean-builddir

clean-builddir : | $(foreach x,apps libc crte,clean$(call dir-to-target,$(BUILDDIR)$(x)/))
	@if [ -d "$(BUILDDIR)" ]; then rmdir -v "$(BUILDDIR)" ; fi

# vim:ft=make
