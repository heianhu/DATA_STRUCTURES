#include<iostream> 
#include<functional>
#include<queue>
using namespace std;
struct cmp1 {
	bool operator ()(int &a, int &b) {
		return a > b;//��Сֵ����  
	}
};
struct cmp2 {
	bool operator ()(int &a, int &b) {
		return a < b;//���ֵ����  
	}
};
//����ṹ��ʹ�����������,�Զ������ȼ�2  
struct number1 {
	int x;
	bool operator < (const number1 &a) const {
		return x > a.x;//��Сֵ����  
	}
};
struct number2 {
	int x;
	bool operator < (const number2 &a) const {
		return x < a.x;//���ֵ����  
	}
};
int a[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number1 num1[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };
number2 num2[] = { 14,10,56,7,83,22,36,91,3,47,72,0 };

int main()
{
	priority_queue<int>que;//����Ĭ�����ȼ��������  

	priority_queue<int, vector<int>, cmp1>que1;//��Сֵ����  
	priority_queue<int, vector<int>, cmp2>que2;//���ֵ����  

	priority_queue<int, vector<int>, greater<int> >que3;//ע�⡰>>���ᱻ��Ϊ����  
														//������������������������ÿո�Ÿ���  
	priority_queue<int, vector<int>, less<int> >que4;////���ֵ����  

	priority_queue<number1>que5;
	priority_queue<number2>que6;

	int i;
	for (i = 0; a[i]; i++) {
		que.push(a[i]);
		que1.push(a[i]);
		que2.push(a[i]);
		que3.push(a[i]);
		que4.push(a[i]);
	}
	for (i = 0; num1[i].x; i++)
		que5.push(num1[i]);
	for (i = 0; num2[i].x; i++)
		que6.push(num2[i]);


	cout << "����Ĭ�����ȹ�ϵ:\n(priority_queue<int>que;)\n";
	while (!que.empty()) {
		cout << que.top();
		que.pop();
	}
	puts("");
	puts("");

	cout << "���ýṹ���Զ������ȼ���ʽһ:\n(priority_queue<int,vector<int>,cmp>que;)\n";
	while (!que1.empty()) {
		cout << que1.top();
		que1.pop();
	}
	puts("");
	while (!que2.empty()) {
		cout << que2.top();
		que2.pop();
	}
	puts("");
	puts("");
	cout << "����ͷ�ļ�\"functional\"�ڶ������ȼ�:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n";
	while (!que3.empty()) {
		cout << que3.top();
		que3.pop();
	}
	puts("");
	while (!que4.empty()) {
		cout << que4.top();
		que4.pop();
	}
	puts("");
	puts("");
	cout << "���ýṹ���Զ������ȼ���ʽ��:\n(priority_queue<number>que)\n";
	while (!que5.empty()) {
		cout << que5.top().x;
		que5.pop();
	}
	puts("");
	while (!que6.empty()) {
		cout << que6.top().x;
		que6.pop();
	}
	puts("");
	return 0;
}