#include<iostream>
using namespace std;
#include<string>
#include<vector>

int func(unsigned int val)
{
	val = (val & 0x55555555) + ((val & 0xaaaaaaaa) >> 1);
	val = (val & 0x33333333) + ((val & 0xcccccccc) >> 2);
	val = (val & 0x0f0f0f0f) + ((val & 0xf0f0f0f0) >> 4);
	val = (val & 0x00ff00ff) + ((val & 0xff00ff00) >> 8);
	val = (val & 0x0000ffff) + ((val & 0xffff0000) >> 16);

	return val;
}

int func1(unsigned int i)
{
	unsigned int temp = i;
	temp = (temp & 0x55555555) + ((temp & 0xaaaaaaaa) >> 1);
	temp = (temp & 0x33333333) + ((temp & 0xccccccccc) >> 2);
	temp = (temp & 0x0f0f0f0f) + ((temp & 0xf0f0f0f0) >> 4);
	temp = (temp & 0xff00ff) + ((temp & 0xff00fff00) >> 8);
	temp = (temp & 0xffff) + ((temp & 0xffff0000) >> 16);
	return temp;
}

string RePlace(string a) {
	int n = a.size();
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		if (a[i] == '{')
		{
			count++;
		}
	}

	while (count--)
	{
		int index1 = a.find("{");
		int index2 = a.find("}");
		a.replace(index1,index2,"*");
	}

	return a;
}

bool IsMatch(string s, string p)
{
	int m = s.size();
	int n = p.size();
	vector<vector<int>> dp(m + 1, vector<int>(n + 1));
	dp[0][0] = true;
	for (int i = 1; i <= n; ++i)
	{
		if (p[i - 1] == '*')
		{
			dp[0][i] = true;
		}
		else {
			break;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (p[j - 1] == '*')
			{
				dp[i][j] = dp[i][j - 1] | dp[i - 1][j];
			}
			else if (p[j - 1] == '*' || s[i - 1] == p[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	return dp[m][n];
}

vector<bool> Query(vector<string> &str, string &rule) {
	vector<bool> res;
	rule=RePlace(rule);
	for (int i = 0; i < str.size(); i++)
	{
		bool a = IsMatch(str[i], rule);
		res.push_back(a);
	}
	return res;

}



//int main() {
//	int N;
//	cin >> N;
//	string Rule;
//	cin.ignore();
//
//	vector<string> strs;
//
//	for (int i = 0; i <N+1; i++)
//	{
//		if (i == 0) {
//			getline(cin, Rule);
//		}
//		else {
//			string st;
//			getline(cin, st);
//			strs.push_back(st);
//		}
//	}
//	for (int i = 0; i < N; i++)
//	{
//		cout << strs[i] << endl;
//	}
//	
//	vector<bool> result = Query(strs, Rule);
//
//	for (int i=0;i<N;i++)
//	{
//		cout << strs[i] << endl;
//		cout << result[i] << endl;
//	}
//
//	string b = RePlace(Rule);
//	cout << b << endl;
//
//	return 0;
//
//}






//int main() {
//		/*����ָ����һά�����ﲻ���ã��������ڶ�ά����*/
//
//	unsigned int ab = func(0x11530829);
//	cout << ab << endl;
//
//	int arr2[3][3] = { {1, 2, 3},
//					  {4, 5, 6},
//					  {7, 8, 9} };
//
//	int* p3 = &arr2[1][0];//��ά�������������һ��ָ���ά������Ԫ�ص�ַ��ָ�룬��ά�������Ԫ�ػ���һ�����飬���Զ�ά�������������һ������ָ�룬�޷�����ȥ��ʼ��һ����ָͨ��
//	//arr2[2][0]�Ƕ�ά����ڶ��е���Ԫ�أ�p3ָ�������Ԫ��,����p3+1�������ڵڶ��е�ά���Ͻ����ƶ�
//	std::cout << *(p3 + 1) << std::endl;//����ڶ��еڶ���Ԫ��5
//
//	int(*p4)[3] = arr2;//p4��һ������ָ�룬ָ�����3��int��һά���飬��ǰָ��arr2�ĵ�һ��һά����({1,2,3})
//	//p4+1����һ����һά����Ĵ�С����p4+1ָ����arr2�ĵڶ���һά����({4,5,6})����p4+1�����û�õ��ڶ���һά������Ԫ�صĵ�ַ����*(p4+1)=&arr2[1][0]
//	//��ô����*(p4+1)�Ļ�������+2���õ��ľ��ǵڶ���һά���������һ��Ԫ�صĵ�ַ����6�Ĵ洢��ַ��*(p4+1)+2=&arr2[1][2]
//	//����������Ͻ��н����õõ��ľ���Ԫ��6����*(*(p4+1)+2)=arr2[1][2]=6
//	std::cout << *(p4 + 1) << std::endl;//0000001F65BAFC84
//	std::cout << &arr2[1][0] << std::endl;//0000001F65BAFC84
//	std::cout << *(p4 + 1) + 2 << std::endl;//0000002A1CBAF9BC
//	std::cout << &arr2[1][2] << std::endl;//0000002A1CBAF9BC
//	std::cout << *(*(p4 + 1) + 2) << std::endl;//6
//	std::cout << arr2[1][2] << std::endl;//6
//	std::cout << *(arr2[1] + 2) << std::endl;//6
//	std::cout << *arr2[1] << std::endl;//4
//	std::cout << 2[1[arr2]] << std::endl;//�൱��arr2[1][2]
//
//	return 0;
//}

//int main()
//{
//	int arr[] = { 1,2,4,5,6 };
//	int* p1 = arr;//��ָͨ�룬p1����ָ����arr����Ԫ�أ�p1+1ֻ��һ��int�ֽڣ�4�ֽڣ���ָ����arr��һ��Ԫ��
//
//	int(*p2)[5] = &arr;//����ָ�룬p2ȴָ������������ĵ�ַ��p2+1ȴ��������arr��С���ֽڣ�4*5=20�ֽڣ���
//	std::cout << p1 << std::endl;
//	std::cout << p1[2] << std::endl;//ָ�������ָ�����ʹ������
//	std::cout << (*p2) << std::endl;//p2ָ������������ĵ�ַ����p2�����õõ�����������Ԫ�صĵ�ַ���ٽ�����һ�ξ���������Ԫ��
//	std::cout << p1 << std::endl;
//	std::cout << p2 << std::endl;
//
//	int p0 = *((int*)(*p2)+1);
//	std::cout << p0 << std::endl;
//
//
//	/*����ָ����һά�����ﲻ���ã��������ڶ�ά����*/
//	int arr2[3][3] = { {1, 2, 3},
//					  {4, 5, 6},
//					  {7, 8, 9} };
//
//	int* p3 = &arr2[1][0];//��ά�������������һ��ָ���ά������Ԫ�ص�ַ��ָ�룬��ά�������Ԫ�ػ���һ�����飬���Զ�ά�������������һ������ָ�룬�޷�����ȥ��ʼ��һ����ָͨ��
//	//arr2[2][0]�Ƕ�ά����ڶ��е���Ԫ�أ�p3ָ�������Ԫ��,����p3+1�������ڵڶ��е�ά���Ͻ����ƶ�
//	std::cout << *(p3 + 1) << std::endl;//����ڶ��еڶ���Ԫ��5
//
//	int(*p4)[3] = arr2;//p4��һ������ָ�룬ָ�����3��int��һά���飬��ǰָ��arr2�ĵ�һ��һά����({1,2,3})
//	//p4+1����һ����һά����Ĵ�С����p4+1ָ����arr2�ĵڶ���һά����({4,5,6})����p4+1�����û�õ��ڶ���һά������Ԫ�صĵ�ַ����*(p4+1)=&arr2[1][0]
//	//��ô����*(p4+1)�Ļ�������+2���õ��ľ��ǵڶ���һά���������һ��Ԫ�صĵ�ַ����6�Ĵ洢��ַ��*(p4+1)+2=&arr2[1][2]
//	//����������Ͻ��н����õõ��ľ���Ԫ��6����*(*(p4+1)+2)=arr2[1][2]=6
//	std::cout << *(p4 + 1) << std::endl;//0000001F65BAFC84
//	std::cout << &arr2[1][0] << std::endl;//0000001F65BAFC84
//	std::cout << *(p4 + 1) + 2 << std::endl;//0000002A1CBAF9BC
//	std::cout << &arr2[1][2] << std::endl;//0000002A1CBAF9BC
//	std::cout << *(*(p4 + 1) + 2) << std::endl;//6
//	std::cout << arr2[1][2] << std::endl;//6
//
//	/*
//	�ɴ˵õ�һ�����ۣ�*(*(p4+i)+j)=arr2[i][j]��p4+iָ��arr2��i��һά����ĵ�ַ��*(p4+i)ָ���i��һά������Ԫ�صĵ�ַ
//	*/
//
//
//
//
//	return 0;
//}

