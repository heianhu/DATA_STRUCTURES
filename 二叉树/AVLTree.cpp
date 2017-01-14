#include "stdafx.h"
#include "AVLTree.h"
#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
AVLTree::AVLTree() :root(NULL)
{
}


AVLTree::~AVLTree()
{
	destory(root);
}

// int AVLTree::max(int a, int b)
// {
// 	return a > b ? a : b;
// }

void AVLTree::insert(string ID, string password)
{
	insert(root, ID, password);
}

UserInfo * AVLTree::insert(UserInfo *& pnode, string ID, string password)
{

	if (pnode == NULL)	//Ѱ�ҵ������λ��
	{
		pnode = new UserInfo(ID, password, NULL, NULL);
	}
	else if (ID > pnode->getID())	//����ֵ�ȵ�ǰ���ֵ�󣬲��뵽��ǰ������������
	{
		pnode->rchild = insert(pnode->rchild, ID, password);
		if (height(pnode->rchild) - height(pnode->lchild) == 2) //��������ʧ��
		{
			if (ID > pnode->rchild->getID()) //���һ���������������ҽڵ㣬��������
				pnode = leftRotation(pnode);
			else if (ID < pnode->rchild->getID())  //���������������������ڵ�,��������������ת
				pnode = rightLeftRotation(pnode);
		}
	}
	else if (ID < pnode->getID()) //����ֵ�ȵ�ǰ�ڵ�ֵС�����뵽��ǰ������������
	{
		pnode->lchild = insert(pnode->lchild, ID, password);
		if (height(pnode->lchild) - height(pnode->rchild) == 2) //������뵼��ʧ��
		{
			if (ID < pnode->lchild->getID())		//����������뵽�����������ӽڵ��ϣ���������
				pnode = rightRotation(pnode);
			else if (ID > pnode->lchild->getID())
				pnode = leftRightRotation(pnode);//����ģ����뵽���������Һ��ӽڵ��ϣ��������������ת
		}
	}
	pnode->setHeight(max(height(pnode->lchild), height(pnode->rchild)) + 1);
	return pnode;
}

void AVLTree::remove(string ID)
{
	root = remove(root, ID);
}

UserInfo * AVLTree::remove(UserInfo *& pnode, string ID)
{
	if (pnode != NULL)
	{
		if (ID == pnode->getID())			//�ҵ�ɾ���Ľڵ�
		{
			if (pnode->lchild != NULL&&pnode->rchild != NULL)		//�����Ҷ���Ϊ��
			{
				if (height(pnode->lchild) > height(pnode->rchild))		//����������������
				{
					//ʹ�����������ڵ������汻ɾ�ڵ㣬��ɾ�������ڵ�
					UserInfo* ppre = maximum(pnode->lchild);		//���������ڵ�
					pnode->setID(ppre->getID());							//�����ڵ��ֵ���ǵ�ǰ���
					pnode->lchild = remove(pnode->lchild, ppre->getID());	//�ݹ��ɾ�����ڵ�
				}
				else
				{
					//ʹ����С�ڵ������汻ɾ�ڵ㣬��ɾ������С�ڵ�
					UserInfo* psuc = minimum(pnode->rchild);		//����������С�ڵ�
					pnode->setID(psuc->getID());								//����С�ڵ�ֵ���ǵ�ǰ���
					pnode->rchild = remove(pnode->rchild, psuc->getID());	//�ݹ��ɾ����С�ڵ�
				}

			}
			else
			{
				UserInfo * ptemp = pnode;
				if (pnode->lchild != NULL)
					pnode = pnode->lchild;
				else if (pnode->rchild != NULL)
					pnode = pnode->rchild;
				delete ptemp;
				return NULL;
			}

		}
		else if (ID > pnode->getID())		//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ����������������ɾ��
		{
			pnode->rchild = remove(pnode->rchild, ID);
			if (height(pnode->lchild) - height(pnode->rchild) == 2) //ɾ���������ڵ㵼�²�ƽ��:�൱��������������
			{
				if (height(pnode->lchild->rchild) > height(pnode->lchild->lchild))
					pnode = leftRightRotation(pnode);				//�൱�������
				else
					pnode = rightRotation(pnode);					//�൱�������
			}
		}
		else if (ID < pnode->getID())		//Ҫɾ���Ľڵ�ȵ�ǰ�ڵ�С����������������ɾ��
		{
			pnode->lchild = remove(pnode->lchild, ID);
			if (height(pnode->rchild) - height(pnode->lchild) == 2)  //ɾ���������ڵ㵼�²�ƽ�⣺�൱������������һ
			{
				if (height(pnode->rchild->lchild) > height(pnode->rchild->rchild))
					pnode = rightLeftRotation(pnode);
				else
					pnode = leftRotation(pnode);
			}
		}
		return pnode;
	}
	return NULL;
}

void AVLTree::destory()
{
	destory(root);
}

void AVLTree::destory(UserInfo *& pnode)
{
	if (pnode != NULL)
	{
		destory(pnode->lchild);
		destory(pnode->rchild);
		delete pnode;
		pnode = NULL;
	}
}

UserInfo * AVLTree::search(string ID)
{
	return search(root, ID);;
}

bool AVLTree::password_istrue(string ID, string password)
{
	UserInfo *Find = search(ID);
	if (Find!=NULL&&Find->getPassword()==password)
	{
		return true;
	}
	return false;
}

void AVLTree::changePassword(string id, string password)
{
	UserInfo *Find = search(id);
	Find->setPassword(password);
}

UserInfo * AVLTree::search(UserInfo * pnode, string ID) const
{
	while (pnode != NULL)
	{
		if (pnode->getID() == ID)
			return pnode;
		else if (ID > pnode->getID())
			pnode = pnode->rchild;
		else
			pnode = pnode->lchild;
	}
	return NULL;
}

UserInfo * AVLTree::minimum(UserInfo * pnode) const
{
	if (pnode != NULL)
	{
		while (pnode->lchild != NULL)
			pnode = pnode->lchild;
		return pnode;
	}
	return NULL;
}

string AVLTree::minimum()
{
	UserInfo* presult = minimum(root);
	if (presult != NULL)
		return presult->getID();
}

UserInfo * AVLTree::maximum(UserInfo*pnode)const
{
	if (pnode != NULL)
	{
		while (pnode->rchild != NULL)
			pnode = pnode->rchild;
		return pnode;
	}
	return NULL;
}

string AVLTree::maximum()
{
	UserInfo* presult = maximum(root);
	if (presult != NULL)
		return presult->getID();
}

int AVLTree::height(UserInfo* pnode)
{
	if (pnode != nullptr)
	{
		return pnode->getHeight();
	}
	return 0;																//����ǿ������߶�Ϊ0
};

int AVLTree::height()
{
	return height(root);
};

//pnodeΪ��Сʧ�������ĸ��ڵ�
//������ת��ĸ��ڵ�
UserInfo* AVLTree::leftRotation(UserInfo* proot)	//����
{
	UserInfo* prchild = proot->rchild;
	proot->rchild = prchild->lchild;
	prchild->lchild = proot;

	proot->setHeight(max(height(proot->lchild), height(proot->rchild)) + 1);		//���½ڵ�ĸ߶�ֵ
	prchild->setHeight(max(height(prchild->lchild), height(prchild->rchild)) + 1);	//���½ڵ�ĸ߶�ֵ

	return prchild;
};

UserInfo* AVLTree::rightRotation(UserInfo*proot)	//����
{
	UserInfo* plchild = proot->lchild;
	proot->lchild = plchild->rchild;
	plchild->rchild = proot;

	proot->setHeight(max(height(proot->lchild), height(proot->rchild)) + 1);     //���½ڵ�ĸ߶�ֵ
	plchild->setHeight(max(height(plchild->lchild), height(plchild->rchild)) + 1); //���½ڵ�ĸ߶�ֵ

	return plchild;
};

UserInfo* AVLTree::leftRightRotation(UserInfo* proot)	//�������
{
	proot->lchild = leftRotation(proot->lchild);
	return rightRotation(proot);
};

UserInfo* AVLTree::rightLeftRotation(UserInfo* proot)	//���Һ���
{
	proot->rchild = rightRotation(proot->rchild);
	return leftRotation(proot);
};

void AVLTree::saveTreeToFile(string file)
{
	ofstream fout(file);
	preOrder(fout,root);
	fout.close();

}


/*���º������Գ���ʹ��*/
// void AVLTree::preOrder()
// {
// 	preOrder(root);
// }

void AVLTree::preOrder(ostream &out,UserInfo * pnode) const
{
	if (pnode != NULL)
	{
		out << pnode->getID() <<" "<< pnode->getPassword() << endl;
		//cout << pnode->getID() << endl;
		preOrder(out,pnode->lchild);
		preOrder(out,pnode->rchild);
	}
}

void AVLTree::dotreeholl()
{
	printTree.resize(height() * 2);
	for (int i = 0; i < printTree.size(); i++)
	{
		printTree[i].assign(int(pow(2, height() - 1)) * 4, ' ');
	}
}

void AVLTree::bulidTree(UserInfo *T, int deep)
{
	if (NULL != T)
	{
		bulidTree(T->lchild, deep + 1);
		printTree[deep * 2].insert(count, T->getID());
		if (NULL != T->lchild)
			printTree[deep * 2 + 1][count] = '/';
		if (NULL != T->rchild)
			printTree[deep * 2 + 1][count + 1] = '\\';
		count += 2;
		bulidTree(T->rchild, deep + 1);
	}
}

void AVLTree::printtheTree()
{
	bulidTree(root, 0);
	for (int i = 0; i < printTree.size(); i++)
	{
		cout << printTree[i] << endl;
	}
}

void AVLTree::showTreeToFile(string file)
{
	count = 0;
	for (int i = 0; i < printTree.size(); i++)
		printTree[i] = "";
	ofstream fout(file);
	fout << "���С���ܾ�����״չʾ�����е��˻�,��Ȼ�����û�п�~" << endl;
	dotreeholl();
	bulidTree(root, 0);
	for (int i = 0; i < printTree.size(); i++)
	{
		fout << printTree[i] << endl;
	}
	fout.close();
}