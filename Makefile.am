pkgconfigdir = $(libdir)/pkgconfig
nodist_pkgconfig_DATA = libenet.pc

IPV6_HEADER = include/enet/ipv6.h

enetincludedir=$(includedir)/enet
enetinclude_HEADERS = \
	include/enet/address.h \
	include/enet/callbacks.h \
	include/enet/enet.h \
	include/enet/list.h \
	include/enet/protocol.h \
	include/enet/time.h \
	include/enet/types.h \
	include/enet/unix.h \
	include/enet/utility.h \
	include/enet/win32.h \
	$(IPV6_HEADER)

lib_LTLIBRARIES = libenet.la
libenet_la_SOURCES = address.c callbacks.c compress.c host.c list.c packet.c peer.c protocol.c unix.c win32.c
# see info '(libtool) Updating version info' before making a release
libenet_la_LDFLAGS = $(AM_LDFLAGS) -version-info 7:5:0
AM_CPPFLAGS = -I$(top_srcdir)/include

ACLOCAL_AMFLAGS = -Im4

BUILT_SOURCES = $(IPV6_HEADER)
CLEANFILES = $(IPV6_HEADER)
if ENET_HAS_IPV6_SUPPORT
include/enet/ipv6.h: Makefile
	echo '#define ENET_HAS_IPV6_SUPPORT 1' >$@
else
include/enet/ipv6.h: Makefile
	echo '#undef ENET_HAS_IPV6_SUPPORT' >$@
endif