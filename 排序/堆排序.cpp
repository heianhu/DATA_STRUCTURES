//��һ��ʵ�ֶ���������д��һЩע���Լ�ʵ��
#include <time.h>
#include <iostream>
#include <vector>
using namespace std;
void MinHeapify(vector<int> &arry, int size, int element)
{
	int lchild = element * 2 + 1, rchild = lchild + 1;//��������
	while (rchild < size)//�������ڷ�Χ��
	{
		if (arry[element] <= arry[lchild] && arry[element] <= arry[rchild])//���������������С���������
		{
			return;
		}
		if (arry[lchild] <= arry[rchild])//��������С
		{
			swap(arry[element], arry[lchild]);//��������ᵽ����
			element = lchild;//ѭ��ʱ��������
		}
		else//����������С
		{
			swap(arry[element], arry[rchild]);//ͬ��
			element = rchild;
		}
		lchild = element * 2 + 1;
		rchild = lchild + 1;//���¼�������λ��
	}
	if (lchild < size&&arry[lchild] < arry[element])//ֻ��������������С���Լ�
	{
		swap(arry[lchild], arry[element]);
	}
	return;
}

void HeapSort(vector<int> &arry, int size)
{
	int i;
	for (i = size - 1; i >= 0; i--)//��������ʼ������
	{
		MinHeapify(arry, size, i);
	}
	while (size > 0)//�����
	{
		swap(arry[size - 1], arry[0]);//��������С����������ĩ����
		size--;//����С��С
		MinHeapify(arry, size, 0);//������
	}
	return;
}

void RemoveRep(vector<int> &v)
{
	int temp;
	int n = v.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (v[i] == v[j])
			{
				v[j] = v[n - 1];
				v.pop_back();
				j--;
				n--;
			}
		}
	}
}

int main()
{
	vector<int> s;

	srand(time(0));

	for (int i = 0; i < 10; i++)
	{
		s.push_back(1 + rand() % 10);
	}
	RemoveRep(s);
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	cout << endl << s.size() << endl;

	HeapSort(s, s.size());
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << " ";
	}
	return 0;
}
