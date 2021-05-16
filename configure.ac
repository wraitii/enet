AC_INIT([libenet], [1.3.17])
AC_CONFIG_SRCDIR([include/enet/enet.h])
AM_INIT_AUTOMAKE([foreign])

AC_CONFIG_MACRO_DIR([m4])

AC_PROG_CC
AC_PROG_LIBTOOL


AC_ARG_ENABLE([ipv6], AS_HELP_STRING([--enable-ipv6], "Enable IPV6 support."))

AC_MSG_CHECKING([if ipv6 support is enabled])
AM_CONDITIONAL([ENET_HAS_IPV6_SUPPORT], [test "x$enable_ipv6" = "xyes"])
AS_IF([test "x$enable_ipv6" = "xyes"], [
	AC_MSG_RESULT([yes])
	AC_DEFINE(ENET_HAS_IPV6_SUPPORT, 1)

	AC_CHECK_FUNC(getaddrinfo, [AC_DEFINE(HAS_GETADDRINFO)], [AC_MSG_ERROR([getaddrinfo is required with ipv6 support.])])
	AC_CHECK_FUNC(getnameinfo, [AC_DEFINE(HAS_GETNAMEINFO)], [AC_MSG_ERROR([getaddrinfo is required with ipv6 support.])])
],
[
	AC_MSG_RESULT([no])
	AC_CHECK_FUNC(getaddrinfo, [AC_DEFINE(HAS_GETADDRINFO)])
	AC_CHECK_FUNC(getnameinfo, [AC_DEFINE(HAS_GETNAMEINFO)])
])

AC_CHECK_FUNC(gethostbyaddr_r, [AC_DEFINE(HAS_GETHOSTBYADDR_R)])
AC_CHECK_FUNC(gethostbyname_r, [AC_DEFINE(HAS_GETHOSTBYNAME_R)])
AC_CHECK_FUNC(poll, [AC_DEFINE(HAS_POLL)])
AC_CHECK_FUNC(fcntl, [AC_DEFINE(HAS_FCNTL)])
AC_CHECK_FUNC(inet_pton, [AC_DEFINE(HAS_INET_PTON)])
AC_CHECK_FUNC(inet_ntop, [AC_DEFINE(HAS_INET_NTOP)])

AC_CHECK_MEMBER(struct msghdr.msg_flags, [AC_DEFINE(HAS_MSGHDR_FLAGS)], , [#include <sys/socket.h>])

AC_CHECK_TYPE(socklen_t, [AC_DEFINE(HAS_SOCKLEN_T)], , 
              #include <sys/types.h>
              #include <sys/socket.h>
)

AC_CONFIG_FILES([Makefile
	libenet.pc])
AC_OUTPUT
