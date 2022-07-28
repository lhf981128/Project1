#include<iostream>
#include<fstream>
#include<chrono>
#include<thread>
#include<string>
#include"MyVector.h"
using namespace std;

template<typename S,int N>

//��ͨģ����
class Array {
private:
	S m_array[N];
public:
	int getSize()const {
		return N;
	}
};

struct Vector3 {
	float x = 0.0f, y = 0.0f, z = 0.0f;
	int* m_MemoryBlock = nullptr;
	Vector3()
	{
		m_MemoryBlock = new int[5];
	}
	Vector3(float sca):x(sca),y(sca),z(sca) {
		m_MemoryBlock = new int[5];
	}
	Vector3(float x, float y, float z) :x(x), y(y), z(z) {
		m_MemoryBlock = new int[5];
	}

	Vector3(const Vector3& other) = delete;

	Vector3(Vector3&& other) :x(other.x), y(other.y), z(other.z)//�ƶ�
	{
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		cout << "Move"<<"1" << endl;
	}

	Vector3& operator=(const Vector3& other) = delete;

	Vector3& operator=(Vector3&& other) {
		cout << other.x<< "Move"<<"2\n";
		m_MemoryBlock = other.m_MemoryBlock;
		other.m_MemoryBlock = nullptr;
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	~Vector3()
	{
		cout << "destroy" << endl;
		delete[] m_MemoryBlock;
	}


};



//�����࣬����ѧϰ����Ա����
class Entity {
public:
	int x;
	int y;
	Entity(int x,int y) {
		this->x = x;
		this->y = y;
	}
	int getX() const//const����thisָ�룬�ڸú����thisָ��ָ�����һ����Entity����
	{
		const Entity& e= *this;//�����øú������this�������õ�����һ�������������
	}
	void Print() {
		cout << this->x << " " << this->y << endl;
	}
	~Entity()
	{

	}
};

//�򵥵�unique_ptr����ָ��
class SmartPtr {

public:
	SmartPtr* m_ptr;
	SmartPtr(SmartPtr* ptr):m_ptr(ptr) {

	}
	~SmartPtr()
	{
		delete m_ptr;
	}
};


//�ַ�����
class String {
public:
public:
	friend ostream& operator <<(ostream& st, const String& str);
	char& operator[](unsigned int index) {
		return m_buffer[index];
	}
	String(const char* str) {//�вι���
		cout << "�в�" << endl;
		m_size = strlen(str);
		m_buffer = new char[m_size + 1];//��1��Ϊ�˰�char*�ַ�������\0�ӽ�ȥ��������������ַ�
		memcpy(m_buffer, str, m_size);
		m_buffer[m_size] = 0;
	}
	//Ĭ���ṩ�Ŀ���������ǳ����������ʹ������String��m_bufferָ��ͬһ���ַ����ִ����������ʱ����ʹ��ͬһ���ڴ��ַ���������Σ����³������
	//String(String& other):m_buffer(other.m_buffer),m_size(other.m_size){}����Ĭ�Ͽ������캯����������Կ�����m_buffer��other.m_bufferָ��ͬһ���ַ
	String(String& other) :m_size(other.m_size) {
		cout << "Copy Func" << endl;
		m_buffer = new char[m_size + 1];//��new��һ���ַ����other.m_buffer��ͬ��
		memcpy(m_buffer, other.m_buffer, m_size + 1);
	}
	~String()
	{
		delete[] m_buffer;
	}
private:
	char* m_buffer;//����洢���������ַ���
	unsigned int m_size;

};

//���������������
ostream& operator <<(ostream& st, const String& str) {
	st << str.m_buffer;
	return st;
}

void PrintString(String a) {
	cout << a << endl;
}

void PrintStringConst(const String& a) {
	cout << a << endl;
}

struct MyStr {
	int x = 0;
	int y = 1;
	int z = 2;
};

struct MyStruct
{
public:
	int x = 0;
	int y = 1;
	int z = 2;
public:
	virtual void speak() {
		cout << "�ְ���˵��!!!!" << endl;
	}

};

//�ṹ��̳�
struct vert:public MyStruct{
	void speak() {
		cout << "������˵��!!!!" << endl;
	}
};

//�ṹ��Ҳ�����й��캯����������������̬
struct Timer {
         chrono::time_point<chrono::steady_clock> start, end;
		 chrono::duration<float> duration;

		 Timer() {
			 start = chrono::high_resolution_clock::now();
		 }
		 ~Timer()
		 {
			 end = chrono::high_resolution_clock::now();
			 duration = end-start;

			 float ms = duration.count()*1000.0f;
			 cout <<"time took"<< ms << "ms" << endl;
		 }
};
template<typename T>
void PrintVector(const MyVector<T> & a)//��ӡ����vector��Ԫ��
{
	for (size_t i = 0; i < a.Size(); i++)
	{
		cout << a[i] << endl;
	}
	cout << "____________________\n";
}


void PrintVector3(const MyVector<Vector3>& ve) {
	for (size_t i = 0; i < ve.Size(); i++)
	{
		cout << ve[i].x << " " << ve[i].y << " " << ve[i].z << endl;
	}
}

void PrintT(int &t)
{
	cout << "lvalue" << endl;
}

void PrintT(int &&t)
{
	cout << "rvalue" << endl;
}

template<typename D>
void TestForward(D && v)
{
	PrintT(v);
	PrintT(std::forward<int>(v));
	PrintT(std::move(v));
	cout << endl;
}


//int main() {
//	//��дvector����
//	/*MyVector<string> myv;
//	myv.PushBack("C++");
//	myv.PushBack("Java");
//	myv.PushBack("C#");
//	myv.PushBack("Python");
//	myv.PushBack("C");
//	PrintVector(myv);*/
//
//	/*MyVector<Vector3> ve;
//	ve.EmplaceBack(1.0f);
//	ve.EmplaceBack(2,3,4);
//	ve.EmplaceBack();
//	PrintVector3(ve);
//	cout << "-----------" << endl;
//	ve.PopBack();
//	PrintVector3(ve);
//	cout << "----------" << endl;
//	ve.Clear();
//	PrintVector3(ve);*/
//
//
//	//����forward��֤����ת���������۵�
//	TestForward(1);//��������ֵ1ʱ��D���ƶ�Ϊint ,v��������int &&������v�����Ǹ���ֵ����Ϊ���Ǳ�����ֻ��������Ϊ���ð󶨵���һ����ֵ�ϣ�
//					//����Print(v)����ý�����ֵ���ò�����Print���Ͼ���ֵ���ò��ܰ���ֵ
//	int x = 1;
//	TestForward(x);//TestForward�Ĳ���������T&&,������һ����ֵʱ������c++�±�׼����������۵�������T�ᱻ�۵��ƶ�Ϊint &
//	TestForward(std::forward<int>(x));
//
//
//
//	//Timer timer;
//	//auto start = chrono::high_resolution_clock::now();
//
//	//Array<int, 64> a;
//	//cout << a.getSize() << endl;
//	//unique_ptr<Entity> pr = make_unique<Entity>(5,8);
//	//pr->Print();
//	//String first = "LiuHongFei";//ֱ�ӵ����вι��죬�൱��String first("LiuHongFei");
//	//String second = first;//���ÿ�������
//	//first[0] = 'K';
//
//	////PrintString(first);//��ΪPrintString�Ĳ���������ֵ���ݣ���������Ҳ����ÿ������죻���Խ�PrintString���βθ�Ϊconst String&�������⿽��,��PrintStringConst������
//	////PrintString(second);
//
//	//PrintStringConst(first);
//	//PrintStringConst(second);
//
//	////һ�������ĵ�ַ����������������һƬ�ڴ�ռ���׵�ַ������׵�ַҲ�Ͷ�Ӧ����ĳһ����Ա�����ĵ�ַ
//	////����һ��ָ��յ�MyStructָ�룬�����ĵ�һ�����ݳ�Ա��ַ�Ǵ�0��ʼ�ģ��Ϳɼ������Ա�ĵ�ַƫ����
//	//int offset = (int)&((MyStr*)nullptr)->y;
//
//	//cout << offset << endl;
//
//	//MyStr temp;
//	//int* position = (int*)&temp;
//	//cout << position[0] << "," << position[1] << "," << position[2] << endl;
//
//	//int y1 = *(int*)((char*)&temp + 4);//תΪchar*ָ�룬+1�൱����һ�ֽڣ�����Ҫ��һ��int�ĳ��ȣ�Ҫ��4
//	//cout << "y:" << y1 << endl;
//	//int z1 = *(int*)((char*)&temp + 8);
//	//cout << "z:" << z1 << endl;
//
//
//	//int y2 = *((int*)&temp + 1);//תΪint*ָ�룬+1�൱�����ĸ��ֽڣ�������һ��int�ĳ��ȣ�ֻ��1
//	//cout << "y2:" << y2 << endl;
//	//int z2 = *((int*)&temp + 2);
//	//cout << "z2:" << z2 << endl;
//
//
//	//auto end = chrono::high_resolution_clock::now();
//	//chrono::duration<float> duration = end - start;
//	//float ms = duration.count()*1000.0f;
//	//cout <<"time took"<<ms<< "ms" << endl;
//
//	//MyStruct* far = new MyStruct();
//	//far->speak();
//	//MyStruct* far1 = new vert();
//	//far1->speak();
//
//	//delete far;
//	//delete far1;
//
//
//	return 0;
//}