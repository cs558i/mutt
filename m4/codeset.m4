#serial 1

dnl From Bruno Haible.

AC_DEFUN([MUTT_AM_LANGINFO_CODESET],
[
  AC_CACHE_CHECK([for nl_langinfo and CODESET], am_cv_langinfo_codeset,
    [AC_LINK_IFELSE([AC_LANG_PROGRAM([[#include <langinfo.h>]],
      [[char* cs = nl_langinfo(CODESET);]])],
      [am_cv_langinfo_codeset=yes],
      [am_cv_langinfo_codeset=no])
    ])
  if test $am_cv_langinfo_codeset = yes; then
    AC_DEFINE(HAVE_LANGINFO_CODESET, 1,
      [Define if you have <langinfo.h> and nl_langinfo(CODESET).])
  fi
])
