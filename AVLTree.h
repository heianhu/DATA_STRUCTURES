#pragma once
#include "UserInfo.h"
#include <vector>
#include <math.h>
#include <stdlib.h>
class AVLTree
{
private:
	UserInfo *root;		//AVL���ĸ��ڵ�
public:


	void saveTreeToFile(string file);	//��ǰ�����AVL����������
	void showTreeToFile(string file);
	void destory();		//����AVL��
	void insert(string ID, string password);	//����ָ��ֵ�Ľڵ�
	void remove(string ID);	//�Ƴ�ָ��ֵ�Ľڵ�
	UserInfo* search(string ID);	//ָ��ֵ�Ĳ���
	bool password_istrue(string ID, string password);
	void changePassword(string id, string password);
	string minimum();		//����AVL�е���Сֵ
	string maximum();		//����AVL�е����ֵ
	int height();		//�������ĸ߶�
	AVLTree();
	~AVLTree();
private:


	void destory(UserInfo* & pnode);

	int height(UserInfo* pnode);	//���ص�ǰ���ĸ߶�
//	int max(int a, int b);		//�ȽϺ���,û��ʹ�ú������к���

	UserInfo* insert(UserInfo* &pnode, string ID, string password);	//���ز����ĸ��ڵ�
	UserInfo* remove(UserInfo* & pnode, string ID); //ɾ��AVL���нڵ�pdel�������ر�ɾ���Ľڵ�

	UserInfo* minimum(UserInfo*pnode)const;		//������С�ڵ�
	UserInfo* maximum(UserInfo*pnode)const;		//�������ڵ�


	UserInfo* search(UserInfo* pnode, string ID) const;	//����ָ��Ԫ��

	UserInfo* leftRotation(UserInfo* pnode);		//��������
	UserInfo* rightRotation(UserInfo* pnode);		//��������
	UserInfo* leftRightRotation(UserInfo* pnode);	//����������������
	UserInfo* rightLeftRotation(UserInfo* pnode);	//����������������

													/*���º������Գ���ʹ��*/
public:
//	void preOrder();	//��ǰ�����AVL��
	void printtheTree();
	void dotreeholl();
private:
	void preOrder(ostream &out, UserInfo* pnode) const;
	std::vector<string> printTree;
	void bulidTree(UserInfo *T, int deep);
	int count = 0;
};
