#include <stdio.h>
#include <stdlib.h>

struct ListNode 
{    
     int val;
     struct ListNode *next;
};


struct ListNode* partition(struct ListNode* head, int x)
{
    //思路一：新建链表，小于x头插，大于等于x尾插
    struct ListNode* cur = head;
    struct ListNode* dummyhead = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* tail = dummyhead->next = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        if (cur->val < x)
        {
            if (tail == NULL)
            {
                //第一次头插,更改尾节点
                tail = cur;
            }
            //头插到新链表中
            cur->next = dummyhead->next;
            dummyhead->next = cur;
        }
        else
        {
            //尾插即可
            tail->next = cur;
            tail = cur;
        }
        cur = next;
    }
    if (tail != NULL)
        tail->next = NULL;

    return dummyhead->next;
}

int main()
{
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 1;
    head->next = NULL;

    int x = 0;
    scanf_s("%d", &x);
    partition(head, x);


    return 0;
}