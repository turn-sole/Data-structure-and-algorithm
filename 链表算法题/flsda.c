//���������������ͷ�ڵ� headA �� headB �������ҳ������������������ཻ����ʼ�ڵ㡣
//����������������ཻ�ڵ㣬���� null ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB) {
    struct ListNode* cur1 = headA;
    struct ListNode* cur2 = headB;
    int len1 = 1;
    int len2 = 1;
    while (cur1->next)
    {
        cur1 = cur1->next;
        len1++;
    }
    while (cur2->next)
    {
        cur2 = cur2->next;
        len2++;
    }
    if (cur1 != cur2)
    {
        return NULL;
    }
    int gap = abs(len1 - len2);
    struct ListNode* longlist = headA;
    struct ListNode* shortlist = headB;
    if (len1 < len2)
    {
        longlist = headB;
        shortlist = headA;
    }
    while (gap)
    {
        longlist = longlist->next;
        gap--;
    }
    while (longlist != shortlist)
    {
        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return longlist;
}
//����һ�������ͷ�ڵ� head ���ж��������Ƿ��л��������������ĳ���ڵ㣬����ͨ��������
//�� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ���������еĻ�������ϵͳ�ڲ�ʹ������
//pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ����ע�⣺pos ����Ϊ�������д��� ��
//������Ϊ�˱�ʶ�����ʵ���������������д��ڻ� ���򷵻� true �� ���򣬷��� false ��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
        return false;
    struct ListNode* fast = head->next->next;
    struct ListNode* slow = head->next;
    while (fast != NULL)
    {
        if (fast == slow)
        {
            return true;
        }
        else if (fast->next == NULL)
        {
            return false;
        }
        fast = fast->next->next;
        slow = slow->next;
    }
    return false;
}