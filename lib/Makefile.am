# Makefile.am -- 
# Copyright 2004-2009,2013-25 Red Hat Inc.
# All Rights Reserved.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Lesser General Public
# License as published by the Free Software Foundation; either
# version 2.1 of the License, or (at your option) any later version.
# 
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Lesser General Public License for more details.
# 
# You should have received a copy of the GNU Lesser General Public
# License along with this program; see the file COPYING.lib. If not, write to
# the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor 
# Boston, MA 02110-1335, USA.
# 
# Authors:
#   Steve Grubb <sgrubb@redhat.com>
#

SUBDIRS = . test
CLEANFILES = $(BUILT_SOURCES)
CONFIG_CLEAN_FILES = *.loT *.rej *.orig
EXTRA_DIST = syscall-update.txt gen_tables64.c
VERSION_INFO = 1:0
AM_CFLAGS = -fPIC -DPIC -D_GNU_SOURCE ${WFLAGS}
AM_CPPFLAGS = -I. -I${top_srcdir} -I${top_srcdir}/auparse -I${top_srcdir}/common

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = audit.pc
DISTCLEANFILES = $(pkgconfig_DATA)

lib_LTLIBRARIES = libaudit.la
include_HEADERS = libaudit.h audit_logging.h audit-records.h

libaudit_la_SOURCES = libaudit.c netlink.c \
        lookup_table.c audit_logging.c deprecated.c \
        dso.h private.h errormsg.h
libaudit_la_LIBADD = $(CAPNG_LDADD) ${top_builddir}/common/libaucommon.la
libaudit_la_DEPENDENCIES = $(libaudit_la_SOURCES) ../config.h ${top_builddir}/common/libaucommon.la
libaudit_la_LDFLAGS = -Wl,-z,relro -version-info $(VERSION_INFO)
nodist_libaudit_la_SOURCES = $(BUILT_SOURCES)

BUILT_SOURCES = actiontabs.h errtabs.h fieldtabs.h flagtabs.h \
	fstypetabs.h ftypetabs.h i386_tables.h machinetabs.h \
	msg_typetabs.h optabs.h permtabs.h ppc_tables.h s390_tables.h \
	s390x_tables.h x86_64_tables.h uringop_tables.h
if USE_ARM
BUILT_SOURCES += arm_tables.h
endif
if USE_AARCH64
BUILT_SOURCES += aarch64_tables.h
endif
if USE_RISCV
BUILT_SOURCES += riscv64_tables.h riscv32_tables.h
endif
noinst_PROGRAMS = gen_actiontabs_h gen_errtabs_h gen_fieldtabs_h \
	gen_flagtabs_h gen_fstypetabs_h gen_ftypetabs_h gen_i386_tables_h \
	gen_machinetabs_h gen_msg_typetabs_h gen_optabs_h \
	gen_permtabs_h gen_ppc_tables_h gen_s390_tables_h \
	gen_s390x_tables_h gen_x86_64_tables_h gen_uringop_tables_h
if USE_ARM
noinst_PROGRAMS += gen_arm_tables_h
endif
if USE_AARCH64
noinst_PROGRAMS += gen_aarch64_tables_h
endif
if USE_RISCV
noinst_PROGRAMS += gen_riscv64_tables_h gen_riscv32_tables_h
endif
gen_actiontabs_h_SOURCES = gen_tables.c gen_tables.h actiontab.h
gen_actiontabs_h_CFLAGS = '-DTABLE_H="actiontab.h"'
$(gen_actiontabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_actiontabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_actiontabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_actiontabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_actiontabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_actiontabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_actiontabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_actiontabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
actiontabs.h: gen_actiontabs_h Makefile
	./gen_actiontabs_h --lowercase --i2s --s2i action > $@

if USE_ARM
gen_arm_tables_h_SOURCES = gen_tables.c gen_tables.h arm_table.h
gen_arm_tables_h_CFLAGS = '-DTABLE_H="arm_table.h"'
$(gen_arm_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_arm_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_arm_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_arm_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_arm_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_arm_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_arm_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_arm_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
arm_tables.h: gen_arm_tables_h Makefile
	./gen_arm_tables_h --lowercase --i2s --s2i arm_syscall > $@
endif

if USE_AARCH64
gen_aarch64_tables_h_SOURCES = gen_tables.c gen_tables.h aarch64_table.h
gen_aarch64_tables_h_CFLAGS = '-DTABLE_H="aarch64_table.h"'
$(gen_aarch64_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_aarch64_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_aarch64_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_aarch64_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_aarch64_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_aarch64_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_aarch64_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_aarch64_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
aarch64_tables.h: gen_aarch64_tables_h Makefile
	./gen_aarch64_tables_h --lowercase --i2s --s2i aarch64_syscall > $@
endif

if USE_RISCV
gen_riscv64_tables_h_SOURCES = gen_tables.c gen_tables.h riscv64_table.h
gen_riscv64_tables_h_CFLAGS = '-DTABLE_H="riscv64_table.h"'
$(gen_riscv64_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_riscv64_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_riscv64_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_riscv64_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_riscv64_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_riscv64_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_riscv64_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_riscv64_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
riscv64_tables.h: gen_riscv64_tables_h Makefile
	./gen_riscv64_tables_h --lowercase --i2s --s2i riscv64_syscall > $@

gen_riscv32_tables_h_SOURCES = gen_tables.c gen_tables.h riscv32_table.h
gen_riscv32_tables_h_CFLAGS = '-DTABLE_H="riscv32_table.h"'
$(gen_riscv32_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_riscv32_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_riscv32_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_riscv32_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_riscv32_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_riscv32_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_riscv32_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_riscv32_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
riscv32_tables.h: gen_riscv32_tables_h Makefile
	./gen_riscv32_tables_h --lowercase --i2s --s2i riscv32_syscall > $@
endif

gen_errtabs_h_SOURCES = gen_tables.c gen_tables.h errtab.h
gen_errtabs_h_CFLAGS = '-DTABLE_H="errtab.h"'
$(gen_errtabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_errtabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_errtabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_errtabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_errtabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_errtabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_errtabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_errtabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
errtabs.h: gen_errtabs_h Makefile
	./gen_errtabs_h --duplicate-ints --uppercase --i2s --s2i err > $@

gen_fieldtabs_h_SOURCES = gen_tables.c gen_tables.h fieldtab.h
gen_fieldtabs_h_CFLAGS = '-DTABLE_H="fieldtab.h"'
$(gen_fieldtabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_fieldtabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_fieldtabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_fieldtabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_fieldtabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_fieldtabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_fieldtabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_fieldtabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
fieldtabs.h: gen_fieldtabs_h Makefile
	./gen_fieldtabs_h --duplicate-ints --lowercase --i2s --s2i field > $@

gen_flagtabs_h_SOURCES = gen_tables.c gen_tables.h flagtab.h
gen_flagtabs_h_CFLAGS = '-DTABLE_H="flagtab.h"'
$(gen_flagtabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_flagtabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_flagtabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_flagtabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_flagtabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_flagtabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_flagtabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_flagtabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
flagtabs.h: gen_flagtabs_h Makefile
	./gen_flagtabs_h --lowercase --i2s --s2i flag > $@

gen_fstypetabs_h_SOURCES = gen_tables.c gen_tables.h fstypetab.h
gen_fstypetabs_h_CFLAGS = '-DTABLE_H="fstypetab.h"'
$(gen_fstypetabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_fstypetabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_fstypetabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_fstypetabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_fstypetabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_fstypetabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_fstypetabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_fstypetabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
fstypetabs.h: gen_fstypetabs_h Makefile
	./gen_fstypetabs_h --lowercase --i2s --s2i fstype > $@

gen_ftypetabs_h_SOURCES = gen_tables.c gen_tables.h ftypetab.h
gen_ftypetabs_h_CFLAGS = '-DTABLE_H="ftypetab.h"'
$(gen_ftypetabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_ftypetabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_ftypetabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_ftypetabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_ftypetabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_ftypetabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_ftypetabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_ftypetabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
ftypetabs.h: gen_ftypetabs_h Makefile
	./gen_ftypetabs_h --lowercase --i2s --s2i ftype > $@

gen_i386_tables_h_SOURCES = gen_tables.c gen_tables.h i386_table.h
gen_i386_tables_h_CFLAGS = '-DTABLE_H="i386_table.h"'
$(gen_i386_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_i386_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_i386_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_i386_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_i386_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_i386_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_i386_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_i386_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
i386_tables.h: gen_i386_tables_h Makefile
	./gen_i386_tables_h --duplicate-ints --lowercase --i2s --s2i \
		i386_syscall > $@

gen_machinetabs_h_SOURCES = gen_tables.c gen_tables.h machinetab.h
gen_machinetabs_h_CFLAGS = '-DTABLE_H="machinetab.h"'
$(gen_machinetabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_machinetabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_machinetabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_machinetabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_machinetabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_machinetabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_machinetabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_machinetabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
machinetabs.h: gen_machinetabs_h Makefile
	./gen_machinetabs_h --duplicate-ints --lowercase --i2s --s2i machine \
		> $@

gen_msg_typetabs_h_SOURCES = gen_tables.c gen_tables.h msg_typetab.h
gen_msg_typetabs_h_CFLAGS = '-DTABLE_H="msg_typetab.h"'
$(gen_msg_typetabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_msg_typetabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_msg_typetabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_msg_typetabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_msg_typetabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_msg_typetabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_msg_typetabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_msg_typetabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
msg_typetabs.h: gen_msg_typetabs_h Makefile
	./gen_msg_typetabs_h --uppercase --i2s --s2i msg_type > $@

gen_optabs_h_SOURCES = gen_tables.c gen_tables.h optab.h
gen_optabs_h_CFLAGS = '-DTABLE_H="optab.h"'
$(gen_optabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_optabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_optabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_optabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_optabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_optabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_optabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_optabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
optabs.h: gen_optabs_h Makefile
	./gen_optabs_h --i2s op > $@

gen_permtabs_h_SOURCES = gen_tables.c gen_tables.h permtab.h
gen_permtabs_h_CFLAGS = '-DTABLE_H="permtab.h"'
$(gen_permtabs_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_permtabs_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_permtabs_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_permtabs_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_permtabs_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_permtabs_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_permtabs_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_permtabs_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
permtabs.h: gen_permtabs_h Makefile
	./gen_permtabs_h --lowercase --i2s --s2i perm > $@

gen_ppc_tables_h_SOURCES = gen_tables.c gen_tables.h ppc_table.h
gen_ppc_tables_h_CFLAGS = '-DTABLE_H="ppc_table.h"'
$(gen_ppc_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_ppc_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_ppc_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_ppc_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_ppc_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_ppc_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_ppc_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_ppc_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
ppc_tables.h: gen_ppc_tables_h Makefile
	./gen_ppc_tables_h --lowercase --i2s --s2i ppc_syscall > $@

gen_s390_tables_h_SOURCES = gen_tables.c gen_tables.h s390_table.h
gen_s390_tables_h_CFLAGS = '-DTABLE_H="s390_table.h"'
$(gen_s390_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_s390_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_s390_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_s390_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_s390_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_s390_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_s390_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_s390_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
s390_tables.h: gen_s390_tables_h Makefile
	./gen_s390_tables_h --lowercase --i2s --s2i s390_syscall > $@

gen_s390x_tables_h_SOURCES = gen_tables.c gen_tables.h s390x_table.h
gen_s390x_tables_h_CFLAGS = '-DTABLE_H="s390x_table.h"'
$(gen_s390x_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_s390x_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_s390x_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_s390x_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_s390x_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_s390x_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_s390x_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_s390x_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
s390x_tables.h: gen_s390x_tables_h Makefile
	./gen_s390x_tables_h --lowercase --i2s --s2i s390x_syscall > $@

gen_uringop_tables_h_SOURCES = gen_tables.c gen_tables.h uringop_table.h
gen_uringop_tables_h_CFLAGS = '-DTABLE_H="uringop_table.h"'
$(gen_uringop_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_uringop_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_uringop_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_uringop_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_uringop_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_uringop_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_uringop_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_uringop_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
uringop_tables.h: gen_uringop_tables_h Makefile
	./gen_uringop_tables_h --lowercase --i2s --s2i uringop > $@

gen_x86_64_tables_h_SOURCES = gen_tables.c gen_tables.h x86_64_table.h
gen_x86_64_tables_h_CFLAGS = '-DTABLE_H="x86_64_table.h"'
$(gen_x86_64_tables_h_OBJECTS): CC=$(CC_FOR_BUILD)
$(gen_x86_64_tables_h_OBJECTS): CFLAGS=$(CFLAGS_FOR_BUILD)
$(gen_x86_64_tables_h_OBJECTS): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
$(gen_x86_64_tables_h_OBJECTS): LDFLAGS=$(LDFLAGS_FOR_BUILD)
gen_x86_64_tables_h$(BUILD_EXEEXT): CC=$(CC_FOR_BUILD)
gen_x86_64_tables_h$(BUILD_EXEEXT): CFLAGS=$(CFLAGS_FOR_BUILD)
gen_x86_64_tables_h$(BUILD_EXEEXT): CPPFLAGS=$(CPPFLAGS_FOR_BUILD)
gen_x86_64_tables_h$(BUILD_EXEEXT): LDFLAGS=$(LDFLAGS_FOR_BUILD)
x86_64_tables.h: gen_x86_64_tables_h Makefile
	./gen_x86_64_tables_h --lowercase --i2s --s2i x86_64_syscall > $@
