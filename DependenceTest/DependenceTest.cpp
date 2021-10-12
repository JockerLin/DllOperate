#include "DependenceTest.h"
#include "QtClassLibraryBC.h"
#include "../exportlib.h"

#pragma comment(lib, "QtClassLibraryBC.lib")

DependenceTest::DependenceTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

	// -----------------------------------------------------��ʽ����
	QtClassLibraryA qcla;
	qcla.lib_a = 223;


	// -----------------------------------------------------��ʾ����1 ��̬������Ҫ�õ����������ļ���.h.dll.lib
	// ����������ж���Ҫ�ĸ����dll�أ�
	// dll ����
	QtClassLibraryBC bc_by_dll;
	bc_by_dll.lib_bc = 998;

	// -----------------------------------------------------��ʾ����2 ֻ��.dll�ļ�ʱ failed!
	HMODULE _dll = LoadLibrary(L"QtClassLibraryD.dll");
	if (_dll == nullptr)
	{
		qDebug()<<("dllΪ��");
	}
	auto createInstanceFunc = (QtClassLibBase*(*)())GetProcAddress(_dll, "createInstance");
	if (createInstanceFunc == nullptr)
	{
		qDebug() << ("createInstanceΪ��");
	}

	auto ins = createInstanceFunc();
	if (ins == nullptr)
	{
		qDebug() << ("insΪ��");
	}
	int basev = ins->basev;
	int test_import_num = ins->getLibNum();

	// HMODULE _dll2 = LoadLibrary(L"HikCamera.dll");
}
