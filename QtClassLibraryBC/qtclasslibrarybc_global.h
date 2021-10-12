#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTCLASSLIBRARYBC_LIB)
#  define QTCLASSLIBRARYBC_EXPORT Q_DECL_EXPORT
# else
#  define QTCLASSLIBRARYBC_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTCLASSLIBRARYBC_EXPORT
#endif
