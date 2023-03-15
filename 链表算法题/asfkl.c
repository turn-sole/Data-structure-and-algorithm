//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//����������
//1->2->2->1
//���أ�true
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <cstddef>
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        struct ListNode* fast = A;
        struct ListNode* slow = A;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        struct ListNode* cur = NULL;
        struct ListNode* tail = slow;
        while (tail) {
            struct ListNode* next = slow->next;
            tail->next = cur;
            cur = tail;
            tail = next;
        }
        while (slow)
        {
            if (A->val != cur->val)
            {
                return false;
            }
            slow = slow->next;
            cur = cur->next;
        }
        return true;
    }
};