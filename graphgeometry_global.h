#ifndef GRAPHGEOMETRY_GLOBAL_H
#define GRAPHGEOMETRY_GLOBAL_H

#ifdef QMAKE_BUILD
#  if defined(GRAPHGEOMETRY_LIBRARY)
#    define GRAPHGEOMETRY_EXPORT __declspec(dllexport)
#  else
#    define GRAPHGEOMETRY_EXPORT __declspec(dllimport)
#  endif
#else
#  define GRAPHGEOMETRY_EXPORT
#endif

#endif // GRAPHGEOMETRY_GLOBAL_H
