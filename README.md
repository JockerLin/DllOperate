
cpp ���ÿ�ļ��ַ���ʵ��

## ����A

-----------------------------------------------------��ʽ����1

ʹ�ù������� ��ҪԴ��
---������ĿQtClassLibraryA
����/��������/��̬��(.lib)

---ʹ����ĿDependenceTest
c++/����/���Ӱ���Ŀ¼		$(SolutionDir)QtClassLibraryA;
������/����/���������	QtClassLibraryA.lib;
DependenceTest.h		#include "QtClassLibraryA.h"

## ����B

-----------------------------------------------------��ʾ����1 ��̬������Ҫ�õ����������ļ���.h.dll.lib
����������ж���Ҫ�ĸ����dll�أ�
dll ����
ʹ�ù������� ��ҪԴ��
---������ĿQtClassLibraryBC
����/��������/��̬��(.dll)

---ʹ����ĿDependenceTest
c++/����/���Ӱ���Ŀ¼		$(SolutionDir)QtClassLibraryBC;
������/����/���������	QtClassLibraryBC.lib;
DependenceTest.h		#include "QtClassLibraryBC.h"
(����������ʽ����1��ֻ�����ɵĿⲻһ�£�һ��Ϊ��̬��һ��Ϊ��̬)

## ����C

-----------------------------------------------------��ʾ����2 ֻ��.dll�ļ�ʱ ͬʱ��Ҫexportlib.h�ļ� ok 
ʹ�ù������� ��ҪԴ��
---������ĿQtClassLibraryBC
����/��������/��̬��(.dll)

---ʹ����ĿDependenceTest
����Ҫ���ã�ֻ��ҪĿ������QtClassLibraryD.dll��������dll������·��Ŀ¼�£�������ܳ���_dllΪ�յ������
(����������ʽ����1��ֻ�����ɵĶ�̬�ⲻһ��)

��̬���ò��ԣ�

```cpp
#include "windows.h"
#include <iostream>

#include "exportlib.h"

int main()
{
    std::cout << "Hello World!\n";

	// ���ÿ�D
	HMODULE _dll = LoadLibrary(L"QtClassLibraryD.dll");
	if (_dll == nullptr)
	{
		std::cout << ("dllΪ��");
	}
	auto createInstanceFunc = (QtClassLibBase*(*)())GetProcAddress(_dll, "createInstance");
	if (createInstanceFunc == nullptr)
	{
		std::cout << ("createInstanceΪ��");
	}

	auto ins = createInstanceFunc();
	if (ins == nullptr)
	{
		std::cout << ("insΪ��");
	}
	int basev = ins->basev;
	int test_import_num = ins->getLibNum();

	// 

}
```

