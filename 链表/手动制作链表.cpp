#include <iostream>
using namespace std;
struct student  //�����Զ����������� 
{
	int num;
	float score;
	student *next;
};
int main(int argc, char** argv) //������ 
{
	student *creat(void);  //�������� 
	void print(student *head);  //������� 
	student *insert(student *head, student *stu);  //��������ڵ� 
	student *del(student *head, int num);  //ɾ���ڵ� 
	student *head, *stu;
	int del_num, Features;
	cout << "����������" << endl;
	head = creat();  //���������ҷ����׵�ַ 
	print(head);  //������нڵ� 
	cout << endl << "��ѡ���ܣ�����0�˳�����" << endl << "1:ɾ��ѧ��" << endl << "2:����ѧ��" << endl;
	while (cin >> Features)
	{
		if (Features == 1)
		{
			cout << "������Ҫɾ����ѧ����ѧ��,����0ʱ�˳�ɾ��";
			cin >> del_num;
			while (del_num != 0)
			{
				head = del(head, del_num);
				print(head);
				cout << "������Ҫɾ����ѧ����ѧ��,����0ʱ�˳�ɾ��";
				cin >> del_num;
			}
		}
		if (Features == 2)
		{
			cout << "������Ҫ�����ѧ����Ϣ(ѧ�źͷ���)����ѧ��Ϊ0ʱ�˳�����";
			stu = new student;
			cin >> stu->num >> stu->score;
			while (stu->num != 0)
			{
				head = insert(head, stu);
				print(head);
				cout << "������Ҫ�����ѧ����Ϣ(ѧ�źͷ���)����ѧ��Ϊ0ʱ�˳�����";
				stu = new student;
				cin >> stu->num >> stu->score;
			}
		}
		if (Features == 0) return 0;
	}
	return 0;
}
int n;  //����ȫ�ֱ���n 
student *creat(void)  //��������ĺ������˺�������һ��ָ������ͷ��ָ�� 
{
	student *head, *p1, *p2;
	n = 0;
	p1 = p2 = new student;  //ʹp1,p2ָ��һ���¿��ٵ��µ�Ԫ 
	cin >> p1->num >> p1->score;
	head = NULL;
	while (p1->num != 0)  //�ж��Ƿ���� 
	{
		n++;
		if (n == 1) head = p1;  //��ͷ��ַ��ֵ 
		else p2->next = p1;   //�ص�* 
		p2 = p1;
		p1 = new student;  //*�ص� 
		cin >> p1->num >> p1->score;
	}
	p2->next = NULL;
	return (head);
}
void print(student *head)  //������� 
{
	student *p;
	cout << endl << n << "��ѧ��Ϊ��" << endl;
	p = head;
	if (head != NULL)
		while (p != NULL)
		{
			cout << p->num << " " << p->score << endl;
			p = p->next;
		}
}
student *insert(student *head, student *stu)  //��������ڵ� 
{
	student *p0, *p1, *p2=NULL;
	p1 = head;
	p0 = stu;
	if (head == NULL)
	{
		head = p0;
		p0->next = NULL;
	}
	else
	{
		while ((p0->num > p1->num) && (p1->num != NULL))
		{
			p2 = p1;
			p1 = p1->next;
		}
		if (p0->num <= p1->num)
		{
			if (head == p1) head = p0;
			else p2->next = p0;
			p0->next = p1;
		}
		else
		{
			p1->next = p0;
			p0->next = NULL;
		}
	}
	n = n + 1;
	return (head);
}
student *del(student *head, int num)  //ɾ�������е�һ���ڵ� 
{
	student *p1, *p2=NULL;
	if (head == NULL)
	{
		cout << "����Ϊ��" << endl;
		return (head);
	}
	p1 = head;
	while (num != p1->num&&p1->next != NULL)
	{
		p2 = p1;
		p1 = p1->next;
	}
	if (num == p1->num)
	{
		if (p1 == head) head = p1->next;
		else p2->next = p1->next;
		cout << "ɾ����" << num << endl;
		n--;
	}
	else cout << "��������û���ҵ�" << num << endl;
	return (head);
}