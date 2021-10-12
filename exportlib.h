#pragma once
#ifndef EXPORT_API
#define EXPORT_API
#endif // !EXPORT_API



#ifdef EXPORT_API
#define Algorithm_API __declspec(dllexport)
#else
#define Algorithm_API	__declspec(dllimport)
#endif


/*!
 * 创建对象
 *
 * \return 成功返回对象地址，失败为空
 */
template<typename T>
void* createInstance()
{
	return new T();
}

/*!
 * 释放对象
 *
 * \param p
 * \return
 */
template<typename T>
Algorithm_API void destoryInstance(void** p)
{
	delete static_cast<T*>(*p);
	*p = nullptr;
}

/*!
 * 导出工具宏 在类声明后面使用
 * class A
 * {
 * };
 * EXPORT_PLUGIN(A)
 *
 */
#define EXPORT_PLUGIN(TYPE)	\
	extern "C"\
	{\
		template Algorithm_API void* createInstance<TYPE>();\
		template Algorithm_API void destoryInstance<TYPE>(void** p);\
	}


class QtClassLibBase {
public:
	QtClassLibBase() {}

	int basev = 20;
	virtual int getLibNum() = 0;
};