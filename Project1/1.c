#include<stdio.h>

#include<stdlib.h>
#include<string.h>


char* GetMemory(char* p)///ָ�봫ֵ���ں����ڲ�ֻ��ָ������޸ģ���û������ģ�ʵ��ָ�����ݲ�����ı䡣��Ϊ�ں����ڲ�ֻ�Ƕ��β�ָ���ָ�����˸ı䣬
						///�Ⲣ����Ӱ��ʵ��ָ���ָ��ʵ��ָ��str����ָ��NULL
{
	p = (char*)malloc(100);
	return p;
}
//��ݼ���shift+alt+->  ����ѡ�������
//void main()
//{
//	/*char* str =NULL;
//	str=GetMemory(str);
//	strcpy_s(str,20,"helloworld");
//	printf(str);*/
//
//	printf("Hello World!\n");
//
//	return 0;
//}