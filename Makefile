# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# defaults.mk
# Copyright Peter Jones <pjones@redhat.com>
#

TOPDIR ?= .

default : all

include include/setup.mk

dumpmake :

.PHONY: all clean default dumpmake

# vim:ft=make
