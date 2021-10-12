#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTCLASSLIBRARYA_LIB)
#  define QTCLASSLIBRARYA_EXPORT Q_DECL_EXPORT
# else
#  define QTCLASSLIBRARYA_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTCLASSLIBRARYA_EXPORT
#endif
