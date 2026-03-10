#define _CRT_SECURE_NO_WARNINGS
//面向对象实现链表
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
struct List
{

//指向头节点的指针
	Node* phead;

//成员函数
//构造函数
	List()
	{
		cout << "调用构造函数:list()" << endl;
		phead = NULL;
	}

//析构函数
	~List()
	{
		cout << "调用析构函数:~list()" << endl;
		while (phead)
		{
			PopFront();
		}
	}
//创建节点
	Node* CreateNode(int d)
	{
		Node* p = new Node;
		p->data = d;
		p->next = NULL;
		return p;
	}

//头插
void PushFront(int d)
{
		//非空链表
		Node* pn = CreateNode(d);
		pn->next = phead;
		phead = pn;
}

//尾插
void PushBack(int d)
{
	Node* pn = CreateNode(d);
	if (phead == NULL)
	{
		//空链表
		phead = pn;
	}
	else
	{
		//非空链表
		Node* tail = phead;
		//1.找最后一个节点
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//2.进行
		tail->next = pn;
	}
}

//打印链表元素
void PrintList()
{
	Node* cur = phead;
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

//头删
void PopFront()
{
	if (phead == NULL)
	{
		cout << "链表为空,无法删除" << endl;
	}
	else
	{
		//1.记录当前节点
		Node* del = phead;
		//2.将ph指向第二个节点
		phead = phead->next;
		//3.释放del并置为空
		delete del;
		del = NULL;
	}
}

//尾删
void PopBack()
{
	if (phead == NULL)
	{
		cout << "链表为空,无法删除" << endl;
	}
	else
	{
		//只有一个节点
		if (phead->next == NULL)
		{
			delete phead;
			phead = NULL;
		}
		//多个节点
		else
		{
			//1.找到倒数第二个节点
			Node* tail = phead;
			while (tail->next->next != NULL)
			{
				tail = tail->next;
			}
			//2.释放掉最后一个节点
			delete tail->next;
			tail->next = NULL;
		}
	}
}

};
int main()
{
	List list;
	list.PushBack(1);
	list.PushBack(2);
	list.PushBack(3);
	list.PushBack(4);
	list.PrintList();//1 2 3 4

	list.PopFront();
	list.PrintList();//2 3 4
	list.PopFront();
	list.PrintList();//3 4
	list.PopFront();
	list.PrintList();//4
	list.PopFront();
	list.PrintList();//NULL

	return 0;
}