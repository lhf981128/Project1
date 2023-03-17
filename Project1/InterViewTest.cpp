#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<numeric>
#include<functional>
#include<math.h>
using namespace std;

struct ListNode {
	int val;
	struct ListNode *next;
  };
 

class Solution {
public:
	/**
	 *
	 * @param head ListNode��
	 * @param m int����
	 * @param n int����
	 * @return ListNode��
	 */
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		// write code here
		if (m == n) return head;
		int gap = n - m;
		int flag = m;
		m = m - 1;
		ListNode* pre = nullptr;//��¼��m���ڵ��ǰһ���ڵ�
		ListNode* cur = nullptr;//��¼��n���ڵ�ĺ�һ���ڵ�
		ListNode* begin = head;

		//ѭ���ҵ���m���ڵ�
		while (true) {
			if (m == 1) pre = begin;
			if (m == 0) break;
			--m;
			begin = begin->next;
		}
		ListNode* end = begin;
		//ѭ���ҵ���n���ڵ�
		while (true)
		{
			if (gap == 0) break;
			--gap;
			end = end->next;
		}
		cur = end->next;

		ListNode* temp1 = nullptr;//��תʱ���ڼ�¼ǰһ���ڵ�
		ListNode* temp2 = begin;//��תʱ������ǰ��һ���Ľڵ�
		ListNode* temp3 = begin;//���ڼ�¼סbegin��ʹ�÷�ת������ƴ������
		if (cur != nullptr)//����Ҫ��һ���жϣ�����ᱨ�δ���
		{
			while (temp2 != cur)
			{
				temp2 = temp2->next;
				begin->next = temp1;
				temp1 = begin;
				begin = temp2;
			}
		}
		else {
			while (temp2 != nullptr)
			{
				temp2 = temp2->next;
				begin->next = temp1;
				temp1 = begin;
				begin = temp2;
			}
		}

		/*
		����Ҫע�⣬���m=1�����ڵ�һ��whileѭ���pre��û�б����¸�ֵ�ģ�����Ϊnullptr��������û��next��Աָ���
		��Ҫ���ж�
		*/
		if (pre != nullptr)
			pre->next = temp1;//��ת������temp1ָ�����end��λ��
		else
			pre = temp1;
		temp3->next = temp2;//temp3��¼����begin��λ�ã���ת������temp2ָ��cur��λ�ã���end��һλ

		/*
		���£�m=2,n=4
		��תǰ��
		temp1=nullptr

			  temp3
			  temp2
		pre   begin         end    cur

		1       2      3     4      5     null

		��ת��
								   begin

				end                temp2
		pre    temp1         temp3  cur

		1        4      3      2     5    null

		����Ҫƴ�������Ļ���preӦ��ָ��temp1��temp3Ӧ��ָ��temp2

		*/
		if (flag > 1)
			return head;
		else
			return pre;

	}
};

class ClassA
{
public:
	ClassA() { cout << "ClassA::ClassA()" << endl; }
	virtual ~ClassA() { cout << "ClassA::~ClassA()" << endl; }

	void func1() { cout << "ClassA::func1()" << endl; }
	void func2() { cout << "ClassA::func2()" << endl; }

	virtual void vfunc1() { cout << "ClassA::vfunc1()" << endl; }
	virtual void vfunc2() { cout << "ClassA::vfunc2()" << endl; }
private:
	int aData;
};

class ClassB : public ClassA
{
public:
	ClassB() { cout << "ClassB::ClassB()" << endl; }
	virtual ~ClassB() { cout << "ClassB::~ClassB()" << endl; }

	void func1() { cout << "ClassB::func1()" << endl; }
	virtual void vfunc1() { cout << "ClassB::vfunc1()" << endl; }
private:
	int bData;
};

class ClassC : public ClassB
{
public:
	ClassC() { cout << "ClassC::ClassC()" << endl; }
	virtual ~ClassC() { cout << "ClassC::~ClassC()" << endl; }

	void func2() { cout << "ClassC::func2()" << endl; }
	virtual void vfunc2() { cout << "ClassC::vfunc2()" << endl; }
private:
	int cData;
};





//int main() {
//	int N;
//	cin >> N;//�������
//	ListNode *head = new ListNode();
//	ListNode *cur = head;
//	for (int i = 0; i < N; i++) {
//		int num;
//		cin >> num;
//		ListNode* temp = new ListNode();
//		temp->val = num;
//		cur->next = temp;
//		cur = cur->next;
//	}
//	int start, end;
//	cin >> start;
//	cin >> end;
//	Solution s;
//
//	ListNode* res= s.reverseBetween(head->next,start,end);//�����main�������أ���main�����������;�Ҫ���ListNode*
//
//	while (res != nullptr) {
//		if (res->next != nullptr) {
//			cout << res->val << " ";
//
//		}
//		else {
//			cout << res->val;
//		}
//		res = res->next;
//	}
//	delete head;
//	delete cur;
//
//	return 0;
//}