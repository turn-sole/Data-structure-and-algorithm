//����һ�������ͷ�ڵ�  head ����������ʼ�뻷�ĵ�һ���ڵ㡣 ��������޻����򷵻� null��
//�����������ĳ���ڵ㣬����ͨ���������� next ָ���ٴε���������д��ڻ��� Ϊ�˱�ʾ��
//�������еĻ�������ϵͳ�ڲ�ʹ������ pos ����ʾ����β���ӵ������е�λ�ã������� 0 ��ʼ������� pos �� - 1�����ڸ�������û�л���ע�⣺pos ����Ϊ�������д��ݣ�������Ϊ�˱�ʶ�����ʵ�������
//�������޸� ����
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