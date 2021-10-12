#pragma once

#include "qtclasslibraryd_global.h"
#include "../exportlib.h"

//class QTCLASSLIBRARYD_EXPORT QtClassLibraryD
class QtClassLibraryD:public QtClassLibBase
{
public:
    QtClassLibraryD();
	int is_d = 1996;
	virtual int getLibNum() override;
};
EXPORT_PLUGIN(QtClassLibraryD)