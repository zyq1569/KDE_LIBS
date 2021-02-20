
#ifndef OKULARCORE_EXPORT_H
#define OKULARCORE_EXPORT_H

#ifdef OKULARCORE_STATIC_DEFINE
#  define OKULARCORE_EXPORT
#  define OKULARCORE_NO_EXPORT
#else
#  ifndef OKULARCORE_EXPORT
#    ifdef okularcore_EXPORTS
        /* We are building this library */
#      define OKULARCORE_EXPORT __declspec(dllexport)
#    else
        /* We are using this library */
#      define OKULARCORE_EXPORT __declspec(dllimport)
#    endif
#  endif

#  ifndef OKULARCORE_NO_EXPORT
#    define OKULARCORE_NO_EXPORT 
#  endif
#endif

#ifndef OKULARCORE_DEPRECATED
#  define OKULARCORE_DEPRECATED __declspec(deprecated)
#endif

#ifndef OKULARCORE_DEPRECATED_EXPORT
#  define OKULARCORE_DEPRECATED_EXPORT OKULARCORE_EXPORT OKULARCORE_DEPRECATED
#endif

#ifndef OKULARCORE_DEPRECATED_NO_EXPORT
#  define OKULARCORE_DEPRECATED_NO_EXPORT OKULARCORE_NO_EXPORT OKULARCORE_DEPRECATED
#endif

#if 0 /* DEFINE_NO_DEPRECATED */
#  ifndef OKULARCORE_NO_DEPRECATED
#    define OKULARCORE_NO_DEPRECATED
#  endif
#endif

#endif /* OKULARCORE_EXPORT_H */
