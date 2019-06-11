#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libmfp2], [i0.1], [thierry@ordissimo.com])
AM_INIT_AUTOMAKE
AC_CONFIG_SRCDIR([src/sanei_init_debug.c])
AC_CONFIG_HEADERS([config.h])

# Checks for programs.
AC_PROG_CC
AM_PROG_LIBTOOL
AC_PROG_LIBTOOL

# Checks for libraries.
# FIXME: Replace `main' with a function in `-lcncpmslld2':
AC_CHECK_LIB([cncpmslld2], [main])
# FIXME: Replace `main' with a function in `-lcncpnet2':
AC_CHECK_LIB([cncpnet2], [main])
# FIXME: Replace `main' with a function in `-lcncpnet20':
AC_CHECK_LIB([cncpnet20], [main])
# FIXME: Replace `main' with a function in `-lcncpnet30':
AC_CHECK_LIB([cncpnet30], [main])
# FIXME: Replace `main' with a function in `-ldl':
AC_CHECK_LIB([dl], [main])
# FIXME: Replace `main' with a function in `-lpthread':
AC_CHECK_LIB([pthread], [main])

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h inttypes.h libintl.h limits.h stdlib.h string.h syslog.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_MODE_T
AC_TYPE_OFF_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_LSTAT_FOLLOWS_SLASHED_SYMLINK
AC_FUNC_MALLOC
AC_CHECK_FUNCS([memset strdup strncasecmp strtol])

path_bjlib=$(find -iname "bjlib")
AC_DEFINE(CNMSLIBPATH, [$path_bjlib], [Pat of bjlib in os])
AC_SUBST(CNMSLIBPATH)

libusb1="libusb-1.0 >= 1.0.0"
PKG_CHECK_MODULES(LIBUSB_1_0, [$libusb1 libjpeg])
AC_SUBST(LIBUSB_1_0_CFLAGS)
AC_SUBST(LIBUSB_1_0_LIBS)

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
