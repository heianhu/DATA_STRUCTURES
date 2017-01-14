//ֱ��������ǰѧϰ��ģ��
#include<iostream>  
using namespace std;  
  
int a[11][11];  
bool visited[11];  
  
void store_graph()  //�ڽӾ���洢ͼ  
{  
    int i,j;  
  
    for(i=1;i<=10;i++)  
        for(j=1;j<=10;j++)  
            cin>>a[i][j];  
}  
  
void dfs_graph()    //��ȱ���ͼ  
{  
    void dfs(int v);  
  
    memset(visited,false,sizeof(visited));  
  
    for(int i=1;i<=10;i++)  //����ÿ��������Ϊ�˷�ֹͼ����ͨʱ�޷�����ÿ������  
        if(visited[i]==false)  
            dfs(i);  
}  
  
void dfs(int v)  //��ȱ�������  
{  
    int Adj(int x);  
  
    cout<<v<<" ";  //���ʶ���v  
    visited[v]=true;  
  
    int adj=Adj(v);  
    while(adj!=0)  
    {  
        if(visited[adj]==false)     
            dfs(adj);      //�ݹ������ʵ����ȱ����Ĺؼ�����  
  
        adj=Adj(v);  
    }  
}  
  
int Adj(int x)   //���ڽӵ�  
{  
    for(int i=1;i<=10;i++)  
        if(a[x][i]==1 && visited[i]==false)  
            return i;  
  
    return 0;  
}  
  
int main()  
{  
    cout<<"��ʼ��ͼ:"<<endl;  
    store_graph();  
  
    cout<<"dfs�������:"<<endl;  
    dfs_graph();  
  
    return 0;  
}  