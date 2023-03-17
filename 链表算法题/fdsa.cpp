//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其
//余结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <cstddef>
#include <cstdlib>
class Partition {
public:
    ListNode* partition(ListNode* pHead, int x) {
        struct ListNode* gguard, * gtail, * lguard, * ltail;
        gguard = gtail = (struct ListNode*)malloc(sizeof(struct ListNode));
        lguard = ltail = (struct ListNode*)malloc(sizeof(struct ListNode));
        gtail->next = ltail->next = NULL;
        struct ListNode* cur = pHead;
        while (cur)
        {
            if (cur->val < x)
            {
                ltail->next = cur;
                ltail = ltail->next;
            }
            else
            {
                gtail->next = cur;
                gtail = gtail->next;
            }
            cur = cur->next;
        }
        ltail->next = gguard->next;
        gtail->next = NULL;
        pHead = lguard->next;
        free(gguard);
        free(lguard);
        return pHead;
    }
};
//对于一个链表，请设计一个时间复杂度为O(n), 额外空间复杂度为O(1)的算法，判断其是否为回
//文结构。给定一个链表的头指针A，请返回一个bool值，代表其是否为回文结构。保证链表长度
//小于等于900。
/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};*/
#include <cmath>
#include <cstddef>
class PalindromeList {
public:
    bool chkPalindrome(ListNode* A) {
        struct ListNode* fast = A;
        struct ListNode* slow = A;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        struct ListNode* cur = slow->next;
        struct ListNode* tail = NULL;
        while (cur)
        {
            struct ListNode* next = cur->next;
            cur->next = tail;
            tail = cur;
            cur = next;
        }
        while (slow->next)
        {
            if (tail->val != A->val)
            {
                return false;
            }
            slow = slow->next;
            tail = tail->next;
        }
        return true;
    }
};
