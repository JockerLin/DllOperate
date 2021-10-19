#include "DependenceTest.h"
#include "../exportlib.h"

// #pragma comment(lib, "QtClassLibraryBC.lib")

DependenceTest::DependenceTest(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);


	// -----------------------------------------------------��ʽ����1
	// 
	/* ʹ�ù������� ��ҪԴ��
	---������ĿQtClassLibraryA
	����/��������/��̬��(.lib)

	---ʹ����ĿDependenceTest
	c++/����/���Ӱ���Ŀ¼		$(SolutionDir)QtClassLibraryA;
	������/����/���������	QtClassLibraryA.lib;
	DependenceTest.h		#include "QtClassLibraryA.h"
	*/
	QtClassLibraryA qcla;
	qcla.lib_a = 223;


	// -----------------------------------------------------��ʾ����1 ��̬������Ҫ�õ����������ļ���.h.dll.lib
	// ����������ж���Ҫ�ĸ����dll�أ�
	// dll ����
	/* ʹ�ù������� ��ҪԴ��
	---������ĿQtClassLibraryBC
	����/��������/��̬��(.dll)

	---ʹ����ĿDependenceTest
	c++/����/���Ӱ���Ŀ¼		$(SolutionDir)QtClassLibraryBC;
	������/����/���������	QtClassLibraryBC.lib;
	DependenceTest.h		#include "QtClassLibraryBC.h"
	(����������ʽ����1��ֻ�����ɵĿⲻһ�£�һ��Ϊ��̬��һ��Ϊ��̬)
	*/
	QtClassLibraryBC bc_by_dll;
	bc_by_dll.lib_bc = 998;

	// -----------------------------------------------------��ʾ����2 ֻ��.dll�ļ�ʱ ok
	/* ʹ�ù������� ��ҪԴ��
	---������ĿQtClassLibraryBC
	����/��������/��̬��(.dll)

	---ʹ����ĿDependenceTest
	����Ҫ���ã�ֻ��ҪĿ������QtClassLibraryD.dll��������dll������·��Ŀ¼�£�������ܳ���_dllΪ�յ������
	(����������ʽ����1��ֻ�����ɵĶ�̬�ⲻһ��)
	*/
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
