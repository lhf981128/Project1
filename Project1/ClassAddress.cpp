#include <iostream>
#include <memory>
using namespace std;


typedef void(*func)(void);
class Base {
public:
	virtual void f() { cout << "Base::f" << endl; }
	virtual void g() { cout << "Base::g" << endl; }
	virtual void h() { cout << "Base::h" << endl; }
};


//int main()
//{
//	Base base;
//	/*
//	�������麯����û�����ԵĿ�����������麯��������Ϊ���٣��ռ䳤�ȶ�Ϊ4�ֽڣ�������Ϊ������һ��ָ������ָ�룬ָ���ڴ�ŵ������ĵ�ַ
//
//	���麯�������ÿ�������ǰ�ĸ��ֽڣ�������������ָ�룬�����ָ������������ĵ�ַ������൱��һ��ָ�����飬���������麯���ĵ�ַ��ÿ���麯����ַҲռ4���ֽ�
//
//	ע�⣺ע����˵��4���ֽڶ��������32λϵͳ
//	*/
//
//
//	//��ȡvptr�ĵ�ַ��������visual studio  x86�����£����Խ�ָ�밴int*��С����
//	//�������C++�ı�����Ӧ���Ǳ�֤�麯�����ָ������ڶ���ʵ������ǰ���λ��
//	int* vPtr = (int*)(&base);//int *��ʾǿ�ƻ�ȡ4���ֽڵ����ݣ������ָ��ĵ�ַ
//	//��ȡvTable �׸������ĵ�ַ
//	func vTable_f = (func)*(int*)(*vPtr);//*vPtr:���������ָ�������ĵ�ַ��(int*)(*vPtr):ǿ��ȡ�����ַ���ǰ4���ֽڣ���4���ֽ������ŵ�һ���麯���ĵ�ַ��
//										//*(int*)(*vPtr)�������õõ�������ַ����func)*(int*)(*vPtr):ǿתΪfunc����
//	//��ȡvTable �ڶ��������ĵ�ַ
//	func vTable_g = (func)*((int*)(*vPtr) + 1);//��1 ����4���ֽڵ���ŵڶ���������λ��
//	func vTable_h = (func)*((int*)(*vPtr) + 2);//��2����8���ֽڵ���ŵ�����������λ��
//
//	vTable_f();
//	vTable_g();
//	vTable_h();
//
//	return 0;
//}

