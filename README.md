
cpp 调用库的几种方法实验

## 测试A

-----------------------------------------------------隐式调用1

使用工程配置 需要源码
---引用项目QtClassLibraryA
常规/配置类型/静态库(.lib)

---使用项目DependenceTest
c++/常规/附加包含目录		$(SolutionDir)QtClassLibraryA;
连接器/输入/添加依赖项	QtClassLibraryA.lib;
DependenceTest.h		#include "QtClassLibraryA.h"

## 测试B

-----------------------------------------------------显示调用1 静态调用需要用到第三方的文件：.h.dll.lib
程序是如何判断需要哪个类的dll呢？
dll 导入
使用工程配置 需要源码
---引用项目QtClassLibraryBC
常规/配置类型/动态库(.dll)

---使用项目DependenceTest
c++/常规/附加包含目录		$(SolutionDir)QtClassLibraryBC;
连接器/输入/添加依赖项	QtClassLibraryBC.lib;
DependenceTest.h		#include "QtClassLibraryBC.h"
(配置类似隐式调用1，只是生成的库不一致，一个为静态，一个为动态)

## 测试C

-----------------------------------------------------显示调用2 只有.dll文件时 同时需要exportlib.h文件 ok 
使用工程配置 需要源码
---引用项目QtClassLibraryBC
常规/配置类型/动态库(.dll)

---使用项目DependenceTest
不需要引用，只需要目标引用QtClassLibraryD.dll的依赖项dll在生成路径目录下，否则可能出现_dll为空的情况。
(配置类似隐式调用1，只是生成的动态库不一致)

动态调用测试：

```cpp
#include "windows.h"
#include <iostream>

#include "exportlib.h"

int main()
{
    std::cout << "Hello World!\n";

	// 调用库D
	HMODULE _dll = LoadLibrary(L"QtClassLibraryD.dll");
	if (_dll == nullptr)
	{
		std::cout << ("dll为空");
	}
	auto createInstanceFunc = (QtClassLibBase*(*)())GetProcAddress(_dll, "createInstance");
	if (createInstanceFunc == nullptr)
	{
		std::cout << ("createInstance为空");
	}

	auto ins = createInstanceFunc();
	if (ins == nullptr)
	{
		std::cout << ("ins为空");
	}
	int basev = ins->basev;
	int test_import_num = ins->getLibNum();

	// 

}
```

