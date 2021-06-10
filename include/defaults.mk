# SPDX-License-Identifier: BSD-2-Clause-Patent
#
# defaults.mk
# Copyright Peter Jones <pjones@redhat.com>
#

override .SUFFIXES :=

ifneq ($(HOST_ARCH),$(EFI_ARCH))
ifeq (1,$(if $(or $(if $(subst default,,$(origin CROSS_COMPILE)),,1),\
		  $(if $(subst undefined,,$(origin CROSS_COMPILE)),,1)),1,0))
CROSS_COMPILE	:= $(ARCH_CROSS_COMPILE)
endif
ifeq (1,$(if $(or $(if $(subst default,,$(origin CROSS_LINK)),,1),\
		  $(if $(subst undefined,,$(origin CROSS_LINK)),,1)),1,0))
CROSS_LINK	:= $(ARCH_CROSS_LINK)
endif

ifeq ($(V),2)
$(info HOST_ARCH:$(HOST_ARCH))
$(info EFI_ARCH:$(EFI_ARCH))
$(info ARCH_CROSS_COMPILE:$(ARCH_CROSS_COMPILE))
$(info ARCH_CROSS_LINK:$(ARCH_CROSS_LINK))
$(info CROSS_COMPILE:$(CROSS_COMPILE))
$(info CROSS_LINK:$(CROSS_LINK))
endif
endif

ifneq ($(origin V) $(V),undefined 0)
override QUIET :=
else
override QUIET := @
endif

CC		?= $(CROSS_COMPILE)$(COMPILER)
ifeq (1,$(if $(or $(if $(subst default,,$(origin CC)),,1),\
		  $(if $(subst undefined,,$(origin CC)),,1)),1,0))
override CC	:= $(CROSS_COMPILE)$(COMPILER)
else
$(info origin cc:$(origin CC))
endif
COMPILER	?= gcc
HOST_AR		?= gcc-ar
HOST_CC		?= $(COMPILER)
HOST_LD		?= ld
HOST_OBJCOPY	?= objcopy
AR		?= $(CROSS_COMPILE)$(HOST_AR)
ifeq ($(origin AR),default)
override AR	:= $(CROSS_COMPILE)$(HOST_AR)
endif
LD		?= $(CROSS_LINK)$(HOST_LD)
OBJCOPY		?= $(CROSS_LINK)$(HOST_OBJCOPY)
BUILDDIR	?= $(TOPDIR)/build/
ifneq ($(origin BUILDDIR),file)
override BUILDDIR := $(BUILDDIR)/
endif

PREFIX		?= /usr

FEATURE_FLAGS	?= \
		   -ffreestanding \
		   -fno-builtin \
		   -fno-strict-aliasing \
		   -fPIC \
		   -fshort-wchar

OPT_FLAGS	?= -O2

LANG_FLAGS	?= -std=gnu11

CC_INCLUDE_DIRS := $(shell $(CC) $(ARCH_CC_FLAGS) -print-file-name=include)

INCLUDE_FLAGS	?= \
		   -iquote $(TOPDIR)/include \
		   -I$(TOPDIR)/include \
		   -I$(TOPDIR)/include/efi \
		   -I$(TOPDIR)/include/efi-mix-ins \
		   -isystem $(TOPDIR)/include/system \
		   $(foreach x,$(CC_INCLUDE_DIRS),-isystem $(x) )

WARN_FLAGS	?= \
		   -Wall \
		   -Wextra \
		   -Wmissing-declarations \
		   -Wno-deprecated-declarations \
		   -Wno-empty-body \
		   -Wno-missing-field-initializers \
		   -Wno-nonnull-compare \
		   -Wno-unused-variable \
		   -Wno-unused-parameter \
		   -Werror \
		   -Wno-error=cpp

CFLAGS		?=
override USER_CFLAGS := $(CFLAGS)
BASE_CFLAGS = $(USER_CFLAGS) \
	      $(FEATURE_FLAGS) \
	      $(OPT_FLAGS) \
	      $(LANG_FLAGS) \
	      $(ARCH_CC_FLAGS) \
	      $(INCLUDE_FLAGS) \
	      $(WARN_FLAGS)

override CFLAGS = $(BASE_CFLAGS) $(EXTRA_FEATURE_FLAGS)

ifeq ($(call check-compiler-support,-fstack-protector -mstack-protector-guard=global),1)
	EXTRA_FEATURE_FLAGS += -mstack-protector-guard=global
ifeq ($(call check-compiler-support,-fstack-protector-strong),1)
	EXTRA_FEATURE_FLAGS += -fstack-protector-strong
else
	EXTRA_FEATURE_FLAGS += -fstack-protector
endif
else
ifeq ($(call check-compiler-support,-fno-stack-protector),1)
	EXTRA_FEATURE_FLAGS += -fno-stack-protector
endif
endif

LDFLAGS		?=
override USER_LDFLAGS := $(LDFLAGS)
override LDFLAGS = $(USER_CFLAGS) \
		   $(USER_LDFLAGS) \
		   $(ARCH_LDFLAGS) \
		   -nostartfiles \
		   -T crte/efi.lds \
		   $(FEATURE_FLAGS) \
		   $(OPT_FLAGS) \
		   $(LANG_FLAGS) \
		   $(ARCH_CC_FLAGS) \
		   $(INCLUDE_FLAGS) \
		   $(WARN_FLAGS)

export
# vim:ft=make
