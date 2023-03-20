//给定一个链表的头节点  head ，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
//如果链表中有某个节点，可以通过连续跟踪 next 指针再次到达，则链表中存在环。 为了表示给
//定链表中的环，评测系统内部使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。如果 pos 是 - 1，则在该链表中没有环。注意：pos 不作为参数进行传递，仅仅是为了标识链表的实际情况。
//不允许修改 链表。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        ListNode fast = head;
        ListNode slow = head;
        if (head == NULL || head.next == NULL)
        {
            return null;
        }
        while (fast != null && fast.next != NULL)
        {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
            {
                break;
            }
        }
        fast = fast.next.next;
        slow = slow.next;
        int len = 1;
        while (fast != slow)
        {
            fast = fast.next.next;
            slow = slow.next;
            len++;
        }
        fast = head;
        slow = head;
        for (int i = 0; i < len; i++)
        {
            fast = fast.next;
        }
        while (fast != slow)
        {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }
};
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        while (head) {
            if (!less<ListNode*>()(head, head->next)) {
                return head->next;
            }
            head = head->next;
        }
        return nullptr;
    }
};