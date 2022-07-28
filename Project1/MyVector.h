#pragma once
#include<iostream>
using namespace std;

template<typename T>
class MyVector {
public:
	MyVector() {
		ReAlloc(2);
	}

	void PushBack(const T& value)//������ֵ�����õ�PushBack����
	{
		if (m_Size >= m_Cap) {
			ReAlloc(m_Cap + m_Cap / 2);
		}
		m_Data[m_Size] = value;
		m_Size++;
	}

	void PushBack(T&& value) //������ֵ���õ�PushBack����
	{
		if (m_Size >= m_Cap) {
			ReAlloc(m_Cap + m_Cap / 2);
		}
		m_Data[m_Size] = move(value);
		m_Size++;
	}
	template<typename...Args>
	T& EmplaceBack(Args&&...args) {
		if (m_Size >= m_Cap) {
			ReAlloc(m_Cap + m_Cap / 2);
		}
		//new(&m_Data[m_Size]) T(forward<Args>(args)...);//�ô��Ƕ�λnew���ʽ
		m_Data[m_Size] = T(forward<Args>(args)...);
		return m_Data[m_Size++];
	}

	const T& operator[](size_t index) const {
		if (index >= m_Size)
		{
			cout << "�������磬�޷�����" << endl;
		}
		return m_Data[index];
	}

	T& operator[](size_t index) {
		if (index >= m_Size)
		{
			cout << "�������磬�޷�����" << endl;
		}
		return m_Data[index];
	}

	size_t Size()const {
		return m_Size;
	}
	void PopBack() {
		if (m_Size > 0) {
			m_Size--;
			m_Data[m_Size].~T();
		}
	}
	void Clear()
	{
		for (size_t i = 0; i < m_Size; i++) {
			m_Data[i].~T();
		}
		m_Size = 0;
	}
	~MyVector()
	{
		Clear();
		//delete[] m_Data;//ֱ��delete���ٴε��ö�����������������ܻᵼ���ظ��������ڴ�,��Ϊ�洢�Ķ����������ָ�����ݳ�Ա
		::operator delete(m_Data, m_Cap * sizeof(T));
	}

private:
	T* m_Data=nullptr;
	size_t m_Size = 0;
	size_t m_Cap = 0;

	void ReAlloc(size_t newCap)
	{
		//1.�½�һ���ڴ�
		//2.���������ƶ�Ԫ�ص����ڴ���
		//3.ɾ�����ڴ�
		T* newBlock = (T*)::operator new(newCap*sizeof(T));

		if (newCap < m_Size) {
			m_Size = newCap;
		}
		for (size_t i = 0; i < m_Size; i++) {
			newBlock[i] =move(m_Data[i]);
		}
		for (size_t i = 0; i < m_Size; i++) {
			m_Data[i].~T();
		}
		::operator delete(m_Data, m_Cap * sizeof(T));
		m_Data = newBlock;
		m_Cap = newCap;
	}

};