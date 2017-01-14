#include<iostream>  
#include<queue>      
using namespace std;

int a[11][11];
bool visited[11];

void store_graph()
{
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			cin >> a[i][j];
}

void bfs_graph()
{
	void bfs(int v);

	memset(visited, false, sizeof(visited));

	for (int i = 1; i <= 10; i++)
		if (visited[i] == false)
			bfs(i);
}

void bfs(int v)
{
	int Adj(int x);

	queue<int> myqueue;
	int adj, temp;

	cout << v << " ";
	visited[v] = true;
	myqueue.push(v);

	while (!myqueue.empty())    //���зǿձ�ʾ���ж���δ������  
	{
		temp = myqueue.front();  //��ö���ͷԪ��  
		myqueue.pop();         //ͷԪ�س���  

		adj = Adj(temp);
		while (adj != 0)
		{
			if (visited[adj] == false)
			{
				cout << adj << " ";
				visited[adj] = true;
				myqueue.push(adj);   //����  
			}

			adj = Adj(temp);
		}
	}
}

int Adj(int x)
{
	for (int i = 1; i <= 10; i++)
		if (a[x][i] == 1 && visited[i] == false)
			return i;

	return 0;
}

int main()
{
	cout << "��ʼ��ͼ:" << endl;
	store_graph();

	cout << "bfs�������:" << endl;
	bfs_graph();

	return 0;
}