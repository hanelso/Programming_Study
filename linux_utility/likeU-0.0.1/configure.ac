AC_INIT(likeU, 0.0.1, hanelso@github.com)
AM_INIT_AUTOMAKE([likeU], [0.0.1])		# comment using automake

# check C compiler and CFlAGS options
AC_PROG_CC

# check libm.a library
AC_CHECK_LIB([m], [sin])


# check libintl.h header file
AC_CHECK_HEADERS([libintl.h])

#check setlocale function using
AC_CHECK_FUNCS([setlocale])

#set output file after excuting ./configure
AC_CONFIG_FILES([Makefile])
AC_OUTPUT
