//给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。
//如果两个链表不存在相交节点，返回 null 。
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
//给你一个链表的头节点 head ，判断链表中是否有环。如果链表中有某个节点，可以通过连续跟
//踪 next 指针再次到达，则链表中存在环。 为了表示给定链表中的环，评测系统内部使用整数
//pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。注意：pos 不作为参数进行传递 。
//仅仅是为了标识链表的实际情况。如果链表中存在环 ，则返回 true 。 否则，返回 false 。
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