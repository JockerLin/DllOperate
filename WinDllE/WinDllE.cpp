// WinDllE.cpp : 定义 DLL 的导出函数。
//

#include "pch.h"
#include "framework.h"
#include "WinDllE.h"


// 这是导出变量的一个示例
WINDLLE_API int nWinDllE=0;

// 这是导出函数的一个示例。
WINDLLE_API int fnWinDllE(void)
{
    return 0;
}

// 这是已导出类的构造函数。
WinDllE::WinDllE()
{
    return;
}
