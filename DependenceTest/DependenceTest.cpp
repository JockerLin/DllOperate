#include "DependenceTest.h"
#include "../exportlib.h"

// #pragma comment(lib, "QtClassLibraryBC.lib")

DependenceTest::DependenceTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


	// -----------------------------------------------------隐式调用1
	// 
	/* 使用工程配置 需要源码
	---引用项目QtClassLibraryA
	常规/配置类型/静态库(.lib)

	---使用项目DependenceTest
	c++/常规/附加包含目录		$(SolutionDir)QtClassLibraryA;
	连接器/输入/添加依赖项	QtClassLibraryA.lib;
	DependenceTest.h		#include "QtClassLibraryA.h"
	*/
	QtClassLibraryA qcla;
	qcla.lib_a = 223;


	// -----------------------------------------------------显示调用1 静态调用需要用到第三方的文件：.h.dll.lib
	// 程序是如何判断需要哪个类的dll呢？
	// dll 导入
	/* 使用工程配置 需要源码
	---引用项目QtClassLibraryBC
	常规/配置类型/动态库(.dll)

	---使用项目DependenceTest
	c++/常规/附加包含目录		$(SolutionDir)QtClassLibraryBC;
	连接器/输入/添加依赖项	QtClassLibraryBC.lib;
	DependenceTest.h		#include "QtClassLibraryBC.h"
	(配置类似隐式调用1，只是生成的库不一致，一个为静态，一个为动态)
	*/
	QtClassLibraryBC bc_by_dll;
	bc_by_dll.lib_bc = 998;

	// -----------------------------------------------------显示调用2 只有.dll文件时 ok
	/* 使用工程配置 需要源码
	---引用项目QtClassLibraryBC
	常规/配置类型/动态库(.dll)

	---使用项目DependenceTest
	不需要引用，只需要目标引用QtClassLibraryD.dll的依赖项dll在生成路径目录下，否则可能出现_dll为空的情况。
	(配置类似隐式调用1，只是生成的动态库不一致)
	*/
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
