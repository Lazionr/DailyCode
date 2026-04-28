#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef int QDatatype;

//定义Queue
typedef struct QListNode
{
	struct QListNode* next;
	QDatatype val;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int size;
}Queue;

//初始化
void QueueInit(Queue* pq)
{
	assert(pq);
	pq->phead = pq->ptail = NULL;
	//在获取队列中有效元素个数中说明size
	pq->size = 0;
}

//入队
void QueuePush(Queue* pq, QDatatype x)
{
	assert(pq);
	//申请节点
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		return;
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		//第一个入队元素
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		//直接在队尾插入
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}
	//在获取队列中有效元素个数中说明size
	pq->size++;
}

//出队
void QueuePop(Queue* pq)
{
	assert(pq);
	//队列不能为空
	assert(pq->size > 0);
	QNode* next = pq->phead->next;
	free(pq->phead);
	pq->phead = next;
	if (pq->phead == NULL)
	{
		pq->ptail = NULL;
	}
	//在获取队列中有效元素个数中说明size
	pq->size--;
}

//获取队头元素
QDatatype QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->phead);
	return pq->phead->val;
}

//获取队尾元素
QDatatype QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->ptail);
	return pq->ptail->val;
}

//获取队列中有效元素个数
int QueueSize(Queue* pq)
{
	//不能直接用尾指针 - 头指针
	//两个指针并非顺序存储
	assert(pq);
	return pq->size;
}

//检测队列是否为空
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//return pq->phead == NULL;
	//在获取队列中有效元素个数中说明size
	return pq->size == 0;
}

//销毁队列
void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->phead = pq->ptail = NULL;
	pq->size = 0;
}

//初始化
void QueueInit(Queue* pq);

//入队
void QueuePush(Queue* pq, QDatatype x);

//出队
void QueuePop(Queue* pq);

//获取队头元素
QDatatype QueueFront(Queue* pq);

//获取队尾元素
QDatatype QueueBack(Queue* pq);

//获取队列中有效元素个数
int QueueSize(Queue* pq);

//检测队列是否为空
bool QueueEmpty(Queue* pq);

//销毁队列
void QueueDestroy(Queue* pq);



typedef struct
{
	//两个队列
	Queue q1;
	Queue q2;
}MyStack;


MyStack* myStackCreate()
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

void myStackPush(MyStack* obj, int x)
{
	//push到有元素的队列中
	Queue empty = obj->q1, unempty = obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = obj->q2;
		unempty = obj->q1;
	}
	QueuePush(&unempty, x);
}

int myStackPop(MyStack* obj)
{
	//将有元素的队列的前 N - 1 个数据导入空队列中，同时 pop 最后一个元素
	Queue empty = obj->q1, unempty = obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = obj->q2;
		unempty = obj->q1;
	}
	while (QueueSize(&unempty) > 1)
	{
		QueuePush(&empty, QueueFront(&unempty));
		QueuePop(&unempty);
	}

	int ret = QueueFront(&unempty);
	QueuePop(&unempty);

	return ret;
}

int myStackTop(MyStack* obj)
{
	int top = myStackPop(obj);

	Queue empty = obj->q1, unempty = obj->q2;
	if (QueueEmpty(&obj->q2))
	{
		empty = obj->q2;
		unempty = obj->q1;
	}

	QueuePush(&unempty, top);

	return top;
}

bool myStackEmpty(MyStack* obj)
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);

	free(obj);
	obj = NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/