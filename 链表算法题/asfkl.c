//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回文结构。
//给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度小于等于900。
//测试样例：
//1->2->2->1
//返回：true
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