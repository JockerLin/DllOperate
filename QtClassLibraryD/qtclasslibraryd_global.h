#pragma once

#include <QtCore/qglobal.h>

#ifndef BUILD_STATIC
# if defined(QTCLASSLIBRARYD_LIB)
#  define QTCLASSLIBRARYD_EXPORT Q_DECL_EXPORT
# else
#  define QTCLASSLIBRARYD_EXPORT Q_DECL_IMPORT
# endif
#else
# define QTCLASSLIBRARYD_EXPORT
#endif
