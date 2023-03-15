//现有一链表的头指针 ListNode* pHead，给一定值x，编写一段代码将所有小于x的结点排在其余
//结点之前，且不能改变原来的数据顺序，返回重新排列后的链表的头指针。
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