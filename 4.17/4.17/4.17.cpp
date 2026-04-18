
//环形链表2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //判断是否相交
    struct ListNode* curA = headA, * curB = headB;
    int lenA = 1, lenB = 1;
    while (curA->next)
    {
        curA = curA->next;
        ++lenA;
    }
    while (curB->next)
    {
        curB = curB->next;
        ++lenB;
    }
    if (curA != curB) return NULL;
    //先走差距步
    int gap = abs(lenA - lenB);
    //假设lenA > lenB
    struct ListNode* longList = headA, * shortList = headB;
    if (lenA < lenB)
    {
        longList = headB;
        shortList = headA;
    }
    while (gap--)
    {
        longList = longList->next;
    }
    //再同时走
    while (longList != shortList)
    {
        longList = longList->next;
        shortList = shortList->next;
    }
    return shortList;
}

struct ListNode* detectCycle(struct ListNode* head)
{

    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;

        //相遇
        if (fast == slow)
        {
            //改成相交链表的问题
            struct ListNode* meet = slow;
            struct ListNode* newhead = meet->next;
            meet->next = NULL;

            return getIntersectionNode(newhead, head);
        }
    }
    return NULL;
}



//随机链表的复制 
struct Node* copyRandomList(struct Node* head)
{
    //所有的拷贝节点都在原节点的后面

    //将原链表每个节点复制之后尾插在每个节点对应的后面
    struct Node* cur = head;
    while (cur)
    {
        struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->val = cur->val;
        newnode->next = cur->next;
        cur->next = newnode;

        cur = newnode->next;
    }
    //cur->random->next可能还没有遍历到，因此要先复制完每个节点之后再进行random的修改
    cur = head;
    while (cur)
    {
        struct Node* newnode = cur->next;
        if (cur->random == NULL) newnode->random = NULL;
        //拷贝节点的random就在cur指向的random的下一个节点上,cur是原节点,后面几位拷贝节点
        else newnode->random = cur->random->next;
        cur = newnode->next;
    }
    //把拷贝节点取下来并尾插到新链表中，同时恢复原链表
    cur = head;
    struct Node* newhead = NULL;
    struct Node* newtail = NULL;
    while (cur)
    {
        struct Node* copy = cur->next;
        if (newhead == NULL)
        {
            newhead = copy;
            newtail = copy;
        }
        else
        {
            newtail->next = copy;
            newtail = copy;
        }
        cur = copy->next;
    }

    return newhead;
}



//相交链表
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //1.遍历链表，看尾节点是否相等
    struct ListNode* curA = headA, * curB = headB;
    //遍历到尾节点直接结束，尾节点不会被++，因此初始化为1
    int lenA = 1, lenB = 1;
    while (curA->next)
    {
        curA = curA->next;
        ++lenA;
    }
    while (curB->next)
    {
        curB = curB->next;
        ++lenB;
    }
    //相等即为相交
    if (curA != curB) return NULL;
    //节点多的链表先走差距步，再同时走
    int gap = abs(lenA - lenB);
    //假设法
    struct ListNode* longlist = headA, * shortlist = headB;
    if (lenA < lenB)
    {
        longlist = headB;
        shortlist = headA;
    }
    //先走差距步
    while (gap--)
    {
        longlist = longlist->next;
    }
    //同时走
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}
