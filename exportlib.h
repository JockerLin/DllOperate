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
 * ��������
 *
 * \return �ɹ����ض����ַ��ʧ��Ϊ��
 */
template<typename T>
void* createInstance()
{
	return new T();
}

/*!
 * �ͷŶ���
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
 * �������ߺ� ������������ʹ��
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