//����һ�����ͷָ�� ListNode* pHead����һ��ֵx����дһ�δ��뽫����С��x�Ľ����������
//���֮ǰ���Ҳ��ܸı�ԭ��������˳�򣬷����������к�������ͷָ�롣
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