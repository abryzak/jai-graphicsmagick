/*
  Copyright (C) 2003 - 2020 GraphicsMagick Group

  This program is covered by multiple licenses, which are described in
  Copyright.txt. You should have received a copy of Copyright.txt with this
  package; otherwise see http://www.graphicsmagick.org/www/Copyright.html.

  GraphicsMagick types typedefs.

  GraphicsMagick is expected to compile with any C '89 ANSI C compiler
  supporting at least 16-bit 'short', 32-bit 'int', and 32-bit 'long'.
  It is also expected to take advantage of 64-bit LP64 and Windows
  WIN64 LLP64.  We use C '99 style types but declare our own types so
  as to not depend on C '99 header files, and take care to depend only
  on C '89 library functions, POSIX, or well-known extensions.  Any C
  '99 syntax used is removed if the compiler does not support it.
*/

#ifndef _MAGICK_TYPES_H
#define _MAGICK_TYPES_H

#if defined(__cplusplus) || defined(c_plusplus)
extern "C" {
#endif

/*
  Assign ANSI C'99 stdint.h-like typedefs based on the sizes of native types
  magick_int8_t   --                       -128 to 127
  magick_uint8_t  --                          0 to 255
  magick_int16_t  --                    -32,768 to 32,767
  magick_uint16_t --                          0 to 65,535
  magick_int32_t  --             -2,147,483,648 to 2,147,483,647
  magick_uint32_t --                          0 to 4,294,967,295
  magick_int64_t  -- -9,223,372,036,854,775,807 to 9,223,372,036,854,775,807
  magick_uint64_t --                          0 to 18,446,744,073,709,551,615

  magick_uintmax_t -- largest native unsigned integer type ("%ju")
                                              0 to UINTMAX_MAX
                      UINTMAX_C(value) declares constant value
  magick_uintptr_t -- unsigned type for storing a pointer value ("%tu")
                                              0 to UINTPTR_MAX

  ANSI C '89 stddef.h-like types
  size_t           -- unsigned type representing sizes of objects ("%zu")
                                              0 to SIZE_MAX
  ptrdiff_t -- signed type for subtracting two pointers ("%td")
                                    PTRDIFF_MIN to PTRDIFF_MAX

  IEEE Std 1003.1 (1990), 2004 types.  Not part of ANSI C!
  ssize_t          -- signed type for a count of bytes or an error indication ("%zd")
                                              ? to SSIZE_MAX
 Useful inttypes.h "printf" formatters:

  magick_int8_t PRId8
  magick_uint8_t PRIu8
  magick_int16_t PRId16
  magick_uint16_t PRIu16
  magick_int32_t PRId32
  magick_uint32_t PRIu32
  magick_int64_t PRId64
  magick_uint64_t PRIu64
  magick_uintmax_t ju
  magick_uintptr_t tu
  size_t zu
  ptrdiff_t td
  ssize_t zd?

*/

#if (defined(WIN32) || defined(WIN64)) && \
  !defined(__MINGW32__) && !defined(__MINGW64__)

  /* The following typedefs are used for WIN32 & WIN64 (without
     configure) */
  typedef signed char   magick_int8_t;
  typedef unsigned char  magick_uint8_t;

  typedef signed short  magick_int16_t;
  typedef unsigned short magick_uint16_t;

  typedef signed int  magick_int32_t;
  typedef unsigned int magick_uint32_t;

  typedef signed __int64  magick_int64_t;
  typedef unsigned __int64 magick_uint64_t;

#  if defined(MAGICK_IMPLEMENTATION)

#  define MAGICK_INT32_F ""
#  define MAGICK_UINT32_F ""
#  define MAGICK_INT64_F "I64"
#  define MAGICK_UINT64_F "I64"

  typedef magick_uint64_t magick_uintmax_t;

#  if defined(WIN64)
  /* WIN64 uses the LLP64 model */
  typedef unsigned long long magick_uintptr_t;
#  define MAGICK_SIZE_T_F "I64"
#  define MAGICK_SIZE_T unsigned __int64
#  define MAGICK_SSIZE_T_F "I64"
#  define MAGICK_SSIZE_T signed __int64
  typedef size_t uintptr_t;
  typedef signed __int64 ptrdiff_t;
#  else
  typedef unsigned long magick_uintptr_t;
#  define MAGICK_SIZE_T_F "l"
#  define MAGICK_SIZE_T unsigned long
#  define MAGICK_SSIZE_T_F ""
#  define MAGICK_SSIZE_T int
  typedef long magick_ptrdiff_t
  typedef unsigned long magick_uintptr_t;
#  endif // defined(WIN64)

#endif /* if defined(MAGICK_IMPLEMENTATION) */

#else

  /* The following typedefs are subtituted when using Unixish configure */
  typedef signed char   magick_int8_t;     /* int8_t */
  typedef unsigned char  magick_uint8_t;    /* uint8_t */

  typedef signed short  magick_int16_t;    /* int16_t */
  typedef unsigned short magick_uint16_t;   /* uint16_t */

  typedef signed int  magick_int32_t;    /* int32_t */
  typedef unsigned int magick_uint32_t;   /* uint32_t */

  typedef signed long  magick_int64_t;    /* int64_t */
  typedef unsigned long magick_uint64_t;   /* uint64_t */

#  if defined(MAGICK_IMPLEMENTATION)

#  define MAGICK_INT32_F ""      /* %PRId32 */
#  define MAGICK_UINT32_F ""    /* %PRIu32 */
#  define MAGICK_INT64_F "l"      /* %PRId64 */
#  define MAGICK_UINT64_F "l"    /* %PRIu64 */

  /*
    C99 special size specifiers:

    hh - signed char / unsigned char
    h  - short / unsigned short
    ll - long long / unsigned long long
    j  - intmax_t / uintmax_t
    z  - signed size_t / size_t
    t  - ptrdiff_t / unsigned ptrdiff_t
  */

  typedef unsigned long magick_uintmax_t; /* uintmax_t */
#  define MAGICK_UINTMAX_F "l"  /* %ju */

  typedef unsigned long magick_uintptr_t; /* uintptr_t */
#  define MAGICK_UINTPTR_F "l"  /* %tu */

  typedef signed long magick_ptrdiff_t; /* ptrdiff_t */
#  define MAGICK_PTRDIFF_F "l"  /* %td */

#  define MAGICK_SIZE_T_F "l" /* %zu */
#  define MAGICK_SIZE_T unsigned long     /* size_t */

#  define MAGICK_SSIZE_T_F "l" /* %zd */
#  define MAGICK_SSIZE_T signed long     /* ssize_t */

#endif /* defined(MAGICK_IMPLEMENTATION) */

#endif

  /* 64-bit file and blob offset type */
  typedef magick_int64_t magick_off_t;

#if defined(MAGICK_IMPLEMENTATION)
#  define MAGICK_OFF_F MAGICK_INT64_F
#endif /* defined(MAGICK_IMPLEMENTATION) */

#if defined(__cplusplus) || defined(c_plusplus)
}
#endif /* defined(__cplusplus) || defined(c_plusplus) */

#endif /* _MAGICK_TYPES_H */