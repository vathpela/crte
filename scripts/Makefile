# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# Makefile
# Copyright Peter Jones <pjones@redhat.com>
#
TOPDIR ?= ..

update-submodules-init:
	@git submodule init
	git submodule sync --recursive

update-edk2-submodule: update-submodules-init
	@if ! [ -f submodules/.edk2.lock ] ; then
		git submodule update --rebase --remote submodules/edk2
		git add submodules/edk2 >/dev/null
	fi

update-submodules: update-submodules-init update-edk2-submodule

update-edk2-includes: update-edk2-submodule
	@bash scripts/update-edk2-includes

# vim:ft=make
