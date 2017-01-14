#include <iostream>
#define inf 1<<20
using namespace std;
int main()
{
	int e[10][10], k, i, j, n, m, t1, t2, t3;
	cin >> n >> m;	
	for (i = 1; i <= n; i++)	//��ʼ��
		for (j = 1; j <= n; j++)
			if (i == j) e[i][j] = 0;
			else e[i][j] = inf;
	for (i = 1; i <= m; i++)	//�����
	{
		cin >> t1 >> t2 >> t3;
		e[t1][t2] = t3;
	}			
	for (k = 1; k <= n; k++)	//Floyd-Warshall�㷨�������
		for (i = 1; i <= n; i++)
			for (j = 1; j <= n; j++)
				if (e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];
	for (i = 1; i <= n; i++)	//������յĽ��
	{
		for (j = 1; j <= n; j++)
		{
			cout << e[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}