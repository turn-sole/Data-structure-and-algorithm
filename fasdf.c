struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* fast = head, * slow = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
*@param pListHead ListNode类
* @param k int整型
* @return ListNode类
* /
struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
    struct ListNode* fast = pListHead;
    struct ListNode* slow = pListHead;
    while (k--)
    {
        if (fast == NULL)
        {
            return NULL;
        }
        fast = fast->next;
    }
    while (fast)
    {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}
void SLTDestroy(SLTNode** phead)
{
    SLTNode* cur = *phead;
    while (cur)
    {
        SLTNode* tmp = cur->next;
        free(cur);
        cur = tmp;
    }
    *phead = NULL;
}
struct ListNode* reverseList(struct ListNode* head) {
    if (head == NULL)
    {
        return NULL;
    }
    struct ListNode* n1, * n2, * n3;
    n1 = NULL;
    n2 = head;
    n3 = n2->next;
    while (n2)
    {
        n2->next = n1;
        n2 = n3;
        n3 = n3->next;
    }
    return n1;
}
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* cur = head, * newhead = NULL;
    while (cur)
    {
        struct ListNode* next = cur->next;
        cur->next = newhead;
        newhead = cur;
        cur = next;
    }
    return newhead;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    struct ListNode* cur1 = list1, * cur2 = list2;
    struct ListNode* head = NULL, * tail = NULL;
    while (cur1 && cur2)
    {
        if (cur1->val < cur2->val)
        {
            if (head == NULL)
            {
                head = tail = cur1;
            }
            else
            {
                tail->next = cur1;
                tail = tail->next;
            }
            cur1 = cur1->next;
        }
        else
        {
            if (head == NULL)
            {
                head = tail = cur2;
            }
            else
            {
                tail->next = cur2;
                tail = tail->next;
            }
            cur2 = cur2->next;
        }
    }
    if (cur1)
    {
        tail->next = cur1;
    }
    if(cur2)
    {
        tail->next = cur2;
    }
    return head;
}
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode* cur1 = list1, * cur2 = list2;
    struct ListNode*guard  = NULL, * tail = NULL;
    guard = tail = (struct ListNode*)malloc(sizeof(struct ListNode));
    tail->next = NULL;
    while (cur1 && cur2)
    {
        if (cur1->val < cur2->val)
        {
            tail->next = cur1;
            tail = tail->next;
            cur1 = cur1->next;
        }
        else
        {
            tail->next = cur2;
            tail = tail->next;
            cur2 = cur2->next;
        }
    }
    if (cur1)
    {
        tail->next = cur1;
    }
    if (cur2)
    {
        tail->next = cur2;
    }
    return head;
}