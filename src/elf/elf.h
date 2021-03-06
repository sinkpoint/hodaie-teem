/*
  Teem: Tools to process and visualize scientific data and images              
  Copyright (C) 2010, 2009 Thomas Schultz

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public License
  (LGPL) as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.
  The terms of redistributing and/or modifying this software also
  include exceptions to the LGPL that facilitate static linking.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public License
  along with this library; if not, write to Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef ELF_HAS_BEEN_INCLUDED
#define ELF_HAS_BEEN_INCLUDED

#include <teem/tijk.h>
#include <teem/limn.h>

#if defined(_WIN32) && !defined(__CYGWIN__) && !defined(TEEM_STATIC)
#  if defined(TEEM_BUILD) || defined(tijk_EXPORTS) || defined(teem_EXPORTS)
#    define ELF_EXPORT extern __declspec(dllexport)
#  else
#    define ELF_EXPORT extern __declspec(dllimport)
#  endif
#else /* TEEM_STATIC || UNIX */
#  define ELF_EXPORT extern
#endif

#ifdef __cplusplus
extern "C" {
#endif

/* glyphElf.c */
ELF_EXPORT float elfGlyphHOME(limnPolyData *glyph, const char antipodal,
			      const float *ten, const tijk_type *type,
			      char *isdef, const char normalize);

ELF_EXPORT float elfGlyphPolar(limnPolyData *glyph, const char antipodal,
			       const float *ten, const tijk_type *type,
			       char *isdef, const char clamp,
			       const char normalize,
			       const unsigned char *posColor,
			       const unsigned char *negColor);

ELF_EXPORT int elfColorGlyphMaxima(limnPolyData *glyph, const char antipodal,
				   const int *neighbors, unsigned int nbstride,
				   const float *ten, const tijk_type *type,
				   const char modulate, const float gamma);

#ifdef __cplusplus
}
#endif

#endif /* ELF_HAS_BEEN_INCLUDED */
