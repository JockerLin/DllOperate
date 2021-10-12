#include "DependenceTest.h"
#include "QtClassLibraryBC.h"
#include "../exportlib.h"

#pragma comment(lib, "QtClassLibraryBC.lib")

DependenceTest::DependenceTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	// -----------------------------------------------------隐式调用
	QtClassLibraryA qcla;
	qcla.lib_a = 223;


	// -----------------------------------------------------显示调用1 静态调用需要用到第三方的文件：.h.dll.lib
	// 程序是如何判断需要哪个类的dll呢？
	// dll 导入
	QtClassLibraryBC bc_by_dll;
	bc_by_dll.lib_bc = 998;

	// -----------------------------------------------------显示调用2 只有.dll文件时 failed!
	HMODULE _dll = LoadLibrary(L"QtClassLibraryD.dll");
	if (_dll == nullptr)
	{
		qDebug()<<("dll为空");
	}
	auto createInstanceFunc = (QtClassLibBase*(*)())GetProcAddress(_dll, "createInstance");
	if (createInstanceFunc == nullptr)
	{
		qDebug() << ("createInstance为空");
	}

	auto ins = createInstanceFunc();
	if (ins == nullptr)
	{
		qDebug() << ("ins为空");
	}
	int basev = ins->basev;
	int test_import_num = ins->getLibNum();

	// HMODULE _dll2 = LoadLibrary(L"HikCamera.dll");
}
