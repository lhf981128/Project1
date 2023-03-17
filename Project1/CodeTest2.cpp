#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

//�����⣺��һ������ΪV�����ӣ���n�����壬����ȡ��������������ӣ�ʣ����С�Ŀռ�

int minSpace(int V, vector<int> &weight) {
	vector<vector<int>> dp(weight.size(), vector<int>(V + 1, 0));

	for (int j = weight[0]; j <= V; j++)
	{
		dp[0][j] = weight[0];
	}
	for (int i = 1; i < weight.size(); i++)
	{
		for (int j = 0; j <= V; j++)
		{
			if (j < weight[i]) dp[i][j] = dp[i - 1][j];
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + weight[i]);
		}
	}
	return dp[weight.size() - 1][V];

}



//int main()
//{
//	int V;
//	int n;
//	cin >> V;
//	cin >> n;
//	vector<int> weight(n);
//	for (int i = 0; i < n; i++)
//	{
//		int num;
//		cin >> num;
//		weight[i] = num;
//	}
//	int res = minSpace(V, weight);
//
//	return V-res;
//}