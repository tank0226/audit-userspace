# Makefile.am--
# Copyright (C) 2007,2008 International Business Machines  Corp.
# Copyright (C) 2011, 2015 Red Hat.
# All Rights Reserved.
#
# This program is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 2 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program; see the file COPYING. If not, write to the
# Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor 
# Boston, MA 02110-1335, USA.
#
# Authors:
#   Klaus Heinrich Kiwi <klausk@br.ibm.com>
#

AM_CPPFLAGS = -I${top_srcdir} -I${top_srcdir}/lib -I${top_srcdir}/auparse
CONFIG_CLEAN_FILES = *.rej *.orig
EXTRA_DIST = zos-remote.conf audispd-zos-remote.conf
plugin_confdir=$(sysconfdir)/audit
plugin_conf = zos-remote.conf
dispatcher_confdir = $(plugin_confdir)/plugins.d
dispatcher_conf = audispd-zos-remote.conf
sbin_PROGRAMS = audispd-zos-remote

noinst_HEADERS = zos-remote-log.h zos-remote-ldap.h zos-remote-config.h \
	zos-remote-queue.h
audispd_zos_remote_SOURCES = zos-remote-plugin.c zos-remote-log.c \
	zos-remote-ldap.c zos-remote-config.c zos-remote-queue.c
audispd_zos_remote_CFLAGS = -W -Wall -Wundef -D_GNU_SOURCE -fPIE -DPIE ${WFLAGS}
audispd_zos_remote_LDFLAGS = -pie -Wl,-z,relro -Wl,-z,now
audispd_zos_remote_LDADD = -lpthread -lldap -llber $(CAPNG_LDADD) ${top_builddir}/auparse/libauparse.la
audispd_zos_remote_DEPENDENCIES = ${top_builddir}/auparse/libauparse.la

install-data-hook:
	mkdir -p -m 0750 ${DESTDIR}${plugin_confdir}
	$(INSTALL_DATA) -D -m 640 ${srcdir}/$(plugin_conf) \
	    ${DESTDIR}${plugin_confdir}
	$(INSTALL_DATA) -D -m 640 ${srcdir}/$(dispatcher_conf) \
	    ${DESTDIR}${dispatcher_confdir}

uninstall-hook:
	rm ${DESTDIR}${plugin_confdir}/$(plugin_conf)
	rm ${DESTDIR}${dispatcher_confdir}/$(dispatcher_conf)
