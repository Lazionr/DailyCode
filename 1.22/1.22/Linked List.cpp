#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
int main()
{
	//创建几个节点
	Node n1 = { 1,NULL };
	Node n2 = { 2,NULL };
	Node n3 = { 3,NULL };
	Node n4 = { 4,NULL };

	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = NULL;
	return 0;
}

#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* CreateNode(int d)
{
	Node* p = new Node;
	p->data = d;
	p->next = NULL;
	return p;
}

//打印链表元素
void PrintList(Node* p)
{
	Node* cur = p;
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

int main()
{
	Node* p1 = CreateNode(1);
	Node* p2 = CreateNode(2);
	Node* p3 = CreateNode(3);
	Node* p4 = CreateNode(4);

	p1->next = p2;
	p2->next = p3;
	p3->next = p4;

	//打印链表元素
	PrintList(p1);

	return 0;
}

#include <iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
Node* CreateNode(int d)
{
	Node* p = new Node;
	p->data = d;
	p->next = NULL;
	return p;
}

//打印链表元素
void PrintList(Node* p)
{
	Node* cur = p;
	while (cur != NULL)
	{
		cout << cur->data << "--->";
		cur = cur->next;
	}
	cout << "NULL" << endl;
}

//头插
void PushFront(Node*& ph, int d)
{
	if (ph == NULL)
	{
		//空链表
		ph = CreateNode(d);
	}
	else
	{
		//非空链表
		Node* pn = CreateNode(d);
		pn->next = ph;
		ph = pn;
	}
}
void PushFront(Node*& ph, int d)
{
		//非空链表
		Node* pn = CreateNode(d);
		pn->next = ph;
		ph = pn;
}

//尾插
void PushBack(Node*& ph, int d)
{
	Node* pn = CreateNode(d);
	if (ph == NULL)
	{
		//空链表
		ph = pn;
	}
	else
	{
		//非空链表
		Node* tail = ph;
		//1.找最后一个节点
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		//2.进行
		tail->next = pn;
	}
}

//头删
void PopFront(Node* & ph)
{
	if (ph == NULL)
	{
		cout << "链表为空,无法删除" << endl;
	}
	else
	{
		//1.记录当前节点
		Node* del = ph;
		//2.将ph指向第二个节点
		ph = ph->next;
		//3.释放del并置为空
		delete del;
		del = NULL;
	}
}

//尾删
void PopBack(Node* & ph)
{
	if (ph == NULL)
	{
		cout << "链表为空,无法删除" << endl;
	}
	else
	{
		//只有一个节点
		if (ph->next == NULL)
		{
			delete ph;
			ph = NULL;
		}
		//多个节点
		else
		{
			//1.找到倒数第二个节点
			Node* tail = ph;
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

//释放所有节点
void DestroyList(Node* ph)
{
	while(ph)
	{
		PopFront(ph);
	}
}

int main()
{
	//头插
	Node* phead = NULL;
	PushFront(phead, 1);
	PushFront(phead, 2);
	PushFront(phead, 3);
	PushFront(phead, 4);
	
	//尾插
	Node* phead = NULL;
	PushBack(phead,1);
	PushBack(phead,2); 
	PushBack(phead,3);
	PushBack(phead,4);
	PrintList(phead);//1 2 3 4

	//头删
	PopFront(phead);
	PrintList(phead);//2 3 4

	PopFront(phead);
	PrintList(phead);//3 4

	PopFront(phead);
	PrintList(phead);//4

	PopFront(phead);
	PrintList(phead);//NULL
	
	//尾删
	PopBack(phead);
	PrintList(phead);//1 2 3

	PopBack(phead);
	PrintList(phead);//1 2

	PopBack(phead);
	PrintList(phead);//1 

	PopBack(phead);
	PrintList(phead);//NULL

	//释放链表
	DestroyList(phead);
	return 0;
}